#ifndef GRAPHICCONTAINER_HXX_INCLUDED
#define GRAPHICCONTAINER_HXX_INCLUDED

#include "GraphicContainer.h"
#include <algorithm>

namespace ogame {
  namespace view {

    inline
    const std::string& GraphicContainer::getName() const noexcept {
      return m_name;
    }

    inline
    void GraphicContainer::addChild(GraphicContainer* child) {
      if (child != nullptr) {
        m_children[child->getName()] = child;
      }
    }

    inline
    void GraphicContainer::removeChild(GraphicContainer* child) {
      if (child != nullptr) {
        m_children.erase(child->getName());
      }
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
      makeDirty();
      unlock();
    }

    inline
    void GraphicContainer::setSize(const float& width, const float& height) {
      lock();
      m_area.w() = width;
      m_area.h() = height;
      makeDirty();
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
      return m_dirty;
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
    void GraphicContainer::makeDirty() {
      m_dirty = true;
    }

  }
}

#endif // BUILDING_HXX_INCLUDED
