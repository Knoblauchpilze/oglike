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
    const std::string SelectorPanel::getActiveChild() {
      lock();
      if (m_activeChild < 0) {
        unlock();
        throw GuiException("Cannot retrieve name of active child for selector " + getName() + ", no such element");
      }
      if (m_availableChildren[m_activeChild] == nullptr) {
        unlock();
        throw GuiException("Cannot retrieve name of active child for selector " + getName() + ", invalid null element");
      }
      const std::string activeChildName = m_availableChildren[m_activeChild]->getName();
      unlock();
      return activeChildName;
    }

    template <typename ContainerPtr>
    inline
    ContainerPtr SelectorPanel::getChildFromCompleteList(const std::string& name) const {
      std::unordered_map<std::string, int>::const_iterator child = m_indices.find(name);
      if (child == m_indices.cend()) {
        return nullptr;
      }
      return dynamic_cast<ContainerPtr>(m_availableChildren[child->second].get());
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
