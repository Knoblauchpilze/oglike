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
