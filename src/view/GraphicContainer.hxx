#ifndef GRAPHICCONTAINER_HXX_INCLUDED
#define GRAPHICCONTAINER_HXX_INCLUDED

#include "GraphicContainer.h"
#include <algorithm>
#include "GraphicContainerException.h"
#include "Layout.h"

namespace ogame {
  namespace view {

    inline
    const std::string& GraphicContainer::getName() const noexcept {
      return m_name;
    }

    inline
    const unsigned GraphicContainer::getChildCount() const noexcept {
      return m_children.size();
    }

    inline
    void GraphicContainer::addEventListener(GraphicContainerListener* listener) {
      m_listeners.insert(listener);
    }

    inline
    void GraphicContainer::removeEventListener(GraphicContainerListener* listener) {
      m_listeners.erase(listener);
    }

    inline
    utils::Area GraphicContainer::getRenderingArea() {
      utils::Area area;
      lock();
      area = getRenderingAreaPrivate();
      unlock();
      return area;
    }

    inline
    void GraphicContainer::setRenderingArea(const utils::Area& area) {
      lock();
      m_area = area;
      makeDeepDirty();
      unlock();
    }

    inline
    void GraphicContainer::onKeyPressedEvent(const SDL_KeyboardEvent& keyEvent) {
      // Pass this event to children in case they can handle it.
      std::for_each(m_children.cbegin(), m_children.cend(),
        [&keyEvent](const std::pair<std::string, GraphicContainerShPtr>& child) {
          child.second->onKeyPressedEvent(keyEvent);
        }
      );

      // Process the event internally.
      if (isRelevant(EventListener::Interaction::KeyPressed, true)) {
        onKeyPressedEventPrivate(keyEvent);
      }
    }

    inline
    void GraphicContainer::onKeyReleasedEvent(const SDL_KeyboardEvent& keyEvent) {
      // Pass this event to children in case they can handle it.
      std::for_each(m_children.cbegin(), m_children.cend(),
        [&keyEvent](const std::pair<std::string, GraphicContainerShPtr>& child) {
          child.second->onKeyReleasedEvent(keyEvent);
        }
      );

      // Process the event internally.
      if (isRelevant(EventListener::Interaction::KeyReleased, true)) {
        onKeyReleasedEventPrivate(keyEvent);
      }
    }

    inline
    void GraphicContainer::onMouseMotionEvent(const SDL_MouseMotionEvent& mouseMotionEvent) {
      // Pass this event to children in case they can handle it.
      std::for_each(m_children.cbegin(), m_children.cend(),
        [&mouseMotionEvent](const std::pair<std::string, GraphicContainerShPtr>& child) {
          child.second->onMouseMotionEvent(mouseMotionEvent);
        }
      );

      // Process the event internally.
      if (isRelevant(EventListener::Interaction::MouseMotion, isInside(mouseMotionEvent.x, mouseMotionEvent.y))) {
        onMouseMotionEventPrivate(mouseMotionEvent);
      }
    }

    inline
    void GraphicContainer::onMouseButtonPressedEvent(const SDL_MouseButtonEvent& mouseButtonEvent) {
      // Pass this event to children in case they can handle it.
      std::for_each(m_children.cbegin(), m_children.cend(),
        [&mouseButtonEvent](const std::pair<std::string, GraphicContainerShPtr>& child) {
          child.second->onMouseButtonPressedEvent(mouseButtonEvent);
        }
      );

      // Process the event internally.
      if (isRelevant(EventListener::Interaction::MouseButtonPressed, isInside(mouseButtonEvent.x, mouseButtonEvent.y))) {
        onMouseButtonPressedEventPrivate(mouseButtonEvent);
      }
    }

    inline
    void GraphicContainer::onMouseButtonReleasedEvent(const SDL_MouseButtonEvent& mouseButtonEvent) {
      // Pass this event to children in case they can handle it.
      std::for_each(m_children.cbegin(), m_children.cend(),
        [&mouseButtonEvent](const std::pair<std::string, GraphicContainerShPtr>& child) {
          child.second->onMouseButtonReleasedEvent(mouseButtonEvent);
        }
      );

      // Process the event internally.
      if (isRelevant(EventListener::Interaction::MouseButtonReleased, isInside(mouseButtonEvent.x, mouseButtonEvent.y))) {
        onMouseButtonReleasedEventPrivate(mouseButtonEvent);
      }
    }

    inline
    void GraphicContainer::onMouseWheelEvent(bool upWheel) {
      // Pass this event to children in case they can handle it.
      std::for_each(m_children.cbegin(), m_children.cend(),
        [&upWheel](const std::pair<std::string, GraphicContainerShPtr>& child) {
          child.second->onMouseWheelEvent(upWheel);
        }
      );

      // Process the event internally.
      if (isRelevant(EventListener::Interaction::MouseWheel, true)) {
        onMouseWheelEventPrivate(upWheel);
      }
    }

    template <typename ContainerPtr>
    inline
    ContainerPtr GraphicContainer::getChild(const std::string& name) const {
      std::unordered_map<std::string, std::shared_ptr<GraphicContainer>>::const_iterator child = m_children.find(name);
      if (child == m_children.cend()) {
        return nullptr;
      }
      return dynamic_cast<ContainerPtr>(child->second.get());
    }

    template <typename Type>
    inline
    bool GraphicContainer::checkChild(const Type* child, const std::string& name) const noexcept {
      if (child == nullptr) {
        std::cerr << "[GRAPHIC] Could not find " << name << " to update panel " << getName() << std::endl;
      }
      return child != nullptr;
    }

    template <typename LayoutPtr>
    inline
    LayoutPtr GraphicContainer::getLayout() const {
      return dynamic_cast<LayoutPtr>(m_layout.get());
    }

    template <typename Type>
    bool GraphicContainer::checkLayout(const Type* layout, const std::string& type) const noexcept {
      if (layout == nullptr) {
        std::cerr << "[GRAPHIC] Could not convert layout to " << type << " for container " << getName() << std::endl;
      }
      return layout != nullptr;
    }

    inline
    void GraphicContainer::makeDirty() {
      m_dirty = true;
    }

    inline
    void GraphicContainer::makeDeepDirty() {
      m_deepDirty = true;
    }

    inline
    void GraphicContainer::setParent(GraphicContainer* parent) {
      m_parent = parent;
    }

    inline
    const GraphicContainer* GraphicContainer::getParent() const noexcept {
      return m_parent;
    }

    inline
    bool GraphicContainer::hasChanged() const noexcept {
      return hasInternallyChanged() || childrenChanged();
    }

    inline
    bool GraphicContainer::hasInternallyChanged() const noexcept {
      return m_dirty || m_deepDirty;
    }

    inline
    const utils::Area& GraphicContainer::getRenderingAreaPrivate() const noexcept {
      return m_area;
    }

    inline
    const bool GraphicContainer::isInside(const float& x, const float& y) {
      return isInside(utils::Vector2f(x, y));
    }

    inline
    const bool GraphicContainer::isInside(const utils::Vector2f& point) {
      utils::Area area = getRenderingArea();
      return area.isInsideRect(convertCoordinates(point));
    }

    inline
    void GraphicContainer::onKeyPressedEventPrivate(const SDL_KeyboardEvent& keyEvent) {
      std::cout << "[GRAPHIC] Key pressed event" << std::endl;
      notifyGraphicListeners(view::EventListener::Interaction::KeyPressed);
    }

    inline
    void GraphicContainer::onKeyReleasedEventPrivate(const SDL_KeyboardEvent& keyEvent) {
      std::cout << "[GRAPHIC] Key released event" << std::endl;
      notifyGraphicListeners(view::EventListener::Interaction::KeyReleased);
    }

    inline
    void GraphicContainer::onMouseMotionEventPrivate(const SDL_MouseMotionEvent& mouseMotionEvent) {
      std::cout << "[GRAPHIC] Mouse motion event" << std::endl;
      notifyGraphicListeners(view::EventListener::Interaction::MouseMotion);
    }

    inline
    void GraphicContainer::onMouseButtonPressedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent) {
      // std::cout << "[GRAPHIC] Mouse button pressed event" << std::endl;
      notifyGraphicListeners(view::EventListener::Interaction::MouseButtonPressed);
    }

    inline
    void GraphicContainer::onMouseButtonReleasedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent) {
      // std::cout << "[GRAPHIC] Mouse button released event" << std::endl;
      notifyGraphicListeners(view::EventListener::Interaction::MouseButtonReleased);
    }

    inline
    void GraphicContainer::onMouseWheelEventPrivate(bool upWheel) {
      // std::cout << "[GRAPHIC] Wheel " << (upWheel ? "up" : "down") << " event" << std::endl;
      notifyGraphicListeners(upWheel ?
        view::EventListener::Interaction::MouseWheelUp :
        view::EventListener::Interaction::MouseWheelDown
      );
    }

    inline
    SDL_Surface* GraphicContainer::createContentPrivate() {
      // Create the background surface.
      return SDL_CreateRGBSurface(0, static_cast<int>(m_area.w()), static_cast<int>(m_area.h()), 32, 0, 0, 0, 0);
    }

    inline
    void GraphicContainer::clearContentPrivate(SDL_Surface* render) {
      // Check whether we can apply the background color.
      if (render != nullptr) {
        SDL_FillRect(render, nullptr, SDL_MapRGB(render->format, m_color.r, m_color.g, m_color.b));

        // Also perform the transparent settings if needed.
        if (m_transparent) {
          SDL_SetColorKey(render, SDL_SRCCOLORKEY, SDL_MapRGB(render->format, m_color.r, m_color.g, m_color.b));
        }
      }
    }

    inline
    void GraphicContainer::notifyGraphicListeners(const view::EventListener::Interaction::Mask& interaction) {
      std::for_each(m_listeners.cbegin(), m_listeners.cend(),
        [&interaction, this](const GraphicContainerListener* listener) {
          const_cast<GraphicContainerListener*>(listener)->onInteractionPerformed(getName(), interaction);
        }
      );
    }

    inline
    bool GraphicContainer::childrenChanged() const noexcept {
      std::unordered_map<std::string, std::shared_ptr<GraphicContainer>>::const_iterator child = m_children.cbegin();
      while (child != m_children.cend()) {
        if (child->second->hasChanged()) {
          return true;
        }
        ++child;
      }
      return false;
    }

    inline
    void GraphicContainer::createContent() {
      // Destroy existing content.
      destroyContent();

      // Create new area.
      m_panel = createContentPrivate();

      if (m_panel == nullptr) {
        const std::string errorMessage = std::string("Cannot create graphic container with dimensions ") +
          std::to_string(m_area.w()) + "x" + std::to_string(m_area.h());
        throw GraphicContainerException(errorMessage);
      }

      // Clear with background color.
      clearContentPrivate(m_panel);
    }

    inline
    void GraphicContainer::destroyContent() {
      if (m_panel != nullptr) {
        SDL_FreeSurface(m_panel);
        m_panel = nullptr;
      }
    }

    inline
    void GraphicContainer::drawChild(GraphicContainerShPtr child) {
      // Draw this object (caching is handled by the object itself).
      SDL_Surface* picture = child->draw();
      // Draw the picture at the corresponding place.
      utils::Area render = child->getRenderingArea();
      SDL_Rect dstArea;
      dstArea.x = static_cast<short int>(render.x());
      dstArea.y = static_cast<short int>(render.y());
      dstArea.w = static_cast<short int>(render.w());
      dstArea.h = static_cast<short int>(render.h());
      if (picture != nullptr) {
        SDL_BlitSurface(picture, nullptr, m_panel, &dstArea);
      }
    }

    inline
    const utils::Vector2f GraphicContainer::convertCoordinates(const utils::Vector2f& point) noexcept {
      utils::Area area = getRenderingArea();
      if (m_parent == nullptr) {
        return point - area.getCenter();
      }
      const utils::Vector2f par = m_parent->convertCoordinates(point);
      const utils::Vector2f thi = par - area.getCenter();
      return par - area.getCenter();
    }

  }
}

#endif // BUILDING_HXX_INCLUDED
