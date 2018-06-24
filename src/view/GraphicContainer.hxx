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
    utils::Area GraphicContainer::getRenderingArea() {
      utils::Area area;
      lock();
      area = m_area;
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
    void GraphicContainer::setParent(GraphicContainer* parent) {
      m_parent = parent;
    }

    inline
    void GraphicContainer::onKeyPressedEvent(const SDL_KeyboardEvent& keyEvent) {
      // Pass this event to children in case they can handle it.
      std::for_each(m_children.cbegin(), m_children.cend(),
        [&keyEvent](const std::pair<std::string, GraphicContainer*>& child) {
          child.second->onKeyPressedEvent(keyEvent);
        }
      );

      // Process the event internally.
      if (isRelevant(EventListener::Interaction::KeyPressed)) {
        onKeyPressedEventPrivate(keyEvent);
      }
    }

    inline
    void GraphicContainer::onKeyReleasedEvent(const SDL_KeyboardEvent& keyEvent) {
      // Pass this event to children in case they can handle it.
      std::for_each(m_children.cbegin(), m_children.cend(),
        [&keyEvent](const std::pair<std::string, GraphicContainer*>& child) {
          child.second->onKeyReleasedEvent(keyEvent);
        }
      );

      // Process the event internally.
      if (isRelevant(EventListener::Interaction::KeyReleased)) {
        onKeyReleasedEventPrivate(keyEvent);
      }
    }

    inline
    void GraphicContainer::onMouseMotionEvent(const SDL_MouseMotionEvent& mouseMotionEvent) {
      // Pass this event to children in case they can handle it.
      std::for_each(m_children.cbegin(), m_children.cend(),
        [&mouseMotionEvent](const std::pair<std::string, GraphicContainer*>& child) {
          child.second->onMouseMotionEvent(mouseMotionEvent);
        }
      );

      // Process the event internally.
      if (isRelevant(EventListener::Interaction::MouseMotion)) {
        onMouseMotionEventPrivate(mouseMotionEvent);
      }
    }

    inline
    void GraphicContainer::onMouseButtonPressedEvent(const SDL_MouseButtonEvent& mouseButtonEvent) {
      // Pass this event to children in case they can handle it.
      std::for_each(m_children.cbegin(), m_children.cend(),
        [&mouseButtonEvent](const std::pair<std::string, GraphicContainer*>& child) {
          child.second->onMouseButtonPressedEvent(mouseButtonEvent);
        }
      );

      // Process the event internally.
      if (isRelevant(EventListener::Interaction::MouseButtonPressed)) {
        onMouseButtonPressedEventPrivate(mouseButtonEvent);
      }
    }

    inline
    void GraphicContainer::onMouseButtonReleasedEvent(const SDL_MouseButtonEvent& mouseButtonEvent) {
      // Pass this event to children in case they can handle it.
      std::for_each(m_children.cbegin(), m_children.cend(),
        [&mouseButtonEvent](const std::pair<std::string, GraphicContainer*>& child) {
          child.second->onMouseButtonReleasedEvent(mouseButtonEvent);
        }
      );

      // Process the event internally.
      if (isRelevant(EventListener::Interaction::MouseButtonReleased)) {
        onMouseButtonReleasedEventPrivate(mouseButtonEvent);
      }
    }

    inline
    void GraphicContainer::onMouseWheelEvent(bool upWheel) {
      // Pass this event to children in case they can handle it.
      std::for_each(m_children.cbegin(), m_children.cend(),
        [&upWheel](const std::pair<std::string, GraphicContainer*>& child) {
          child.second->onMouseWheelEvent(upWheel);
        }
      );

      // Process the event internally.
      if (isRelevant(EventListener::Interaction::MouseWheel)) {
        onMouseWheelEventPrivate(upWheel);
      }
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
    void GraphicContainer::onKeyPressedEventPrivate(const SDL_KeyboardEvent& keyEvent) {}

    inline
    void GraphicContainer::onKeyReleasedEventPrivate(const SDL_KeyboardEvent& keyEvent) {}

    inline
    void GraphicContainer::onMouseMotionEventPrivate(const SDL_MouseMotionEvent& mouseMotionEvent) {}

    inline
    void GraphicContainer::onMouseButtonPressedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent) {}

    inline
    void GraphicContainer::onMouseButtonReleasedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent) {}

    inline
    void GraphicContainer::onMouseWheelEventPrivate(bool upWheel) {}

    inline
    void GraphicContainer::makeDirty() {
      m_dirty = true;
    }

    inline
    void GraphicContainer::makeDeepDirty() {
      m_deepDirty = true;
    }

    inline
    bool GraphicContainer::childrenChanged() const noexcept {
      std::unordered_map<std::string, GraphicContainer*>::const_iterator child = m_children.cbegin();
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
      m_panel = SDL_CreateRGBSurface(0,
                                     static_cast<int>(m_area.w()),
                                     static_cast<int>(m_area.h()),
                                     32,
                                     0,
                                     0,
                                     0,
                                     0);
      if (m_panel == nullptr) {
        const std::string errorMessage = std::string("Cannot create graphic container with dimensions ") +
          std::to_string(m_area.w()) + "x" + std::to_string(m_area.h());
        throw GraphicContainerException(errorMessage);
      }

      // Clear with background color.
      clearContent();
    }

    inline
    void GraphicContainer::clearContent() {
      if (m_panel != nullptr) {
        SDL_FillRect(m_panel, nullptr, SDL_MapRGB(m_panel->format, m_color.r, m_color.g, m_color.b));
      }
    }

    inline
    void GraphicContainer::destroyContent() {
      if (m_panel != nullptr) {
        SDL_FreeSurface(m_panel);
      }
    }

    inline
    void GraphicContainer::drawChild(GraphicContainer* child) {
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

  }
}

#endif // BUILDING_HXX_INCLUDED
