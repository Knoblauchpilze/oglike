#ifndef SELECTORPANEL_HXX
#define SELECTORPANEL_HXX

#include "SelectorPanel.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    inline
    void SelectorPanel::setActiveChild(const std::string& name) {
      lock();

      std::unordered_map<std::string, int>::const_iterator child = m_indices.find(name);
      if (child == m_indices.cend()) {
        unlock();
        throw GuiException(
          std::string("Cannot activate child ") + name +
          " in container " + getName() +
          ": child not found"
        );
      }
      if (child->second >= m_availableChildren.size()) {
        unlock();
        throw GuiException(
          std::string("Cannot activate child ") + name +
          " in container " + getName() +
          " invalid index " + std::to_string(child->second) +
          " while container only have " + std::to_string(m_availableChildren.size()) + " child(ren)"
        );
      }

      activateChild(child->second);

      makeDeepDirty();
      unlock();
    }

    inline
    void SelectorPanel::setActiveChild(const int& index) {
      lock();

      if (index >= m_availableChildren.size()) {
        unlock();
        throw GuiException(
          std::string("Cannot activate child ") + std::to_string(index) +
          " in container " + getName() +
          " only containing " + std::to_string(m_availableChildren.size()) + " child(ren)"
        );
      }

      activateChild(index);

      makeDeepDirty();
      unlock();
    }

    inline
    void SelectorPanel::activateChild(const int& index) {
      // Deactivate the current active child if any.
      if (m_activeChild >= 0) {
        GraphicContainer::removeChild(m_availableChildren[m_activeChild]);
      }

      // Activate the new one.
      GraphicContainer::addChild(m_availableChildren[index]);

      // The new child is now active.
      m_activeChild = index;
    }
  }
}

#endif // SELECTORPANEL_HXX
