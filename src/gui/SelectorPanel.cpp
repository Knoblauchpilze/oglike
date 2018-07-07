
#include "SelectorPanel.h"
#include "LinearLayout.h"

namespace ogame {
  namespace gui {

    SelectorPanel::SelectorPanel(const std::string& name):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             std::make_shared<view::LinearLayout>(
                               view::LinearLayout::Direction::Horizontal,
                               0.0f,
                               0.0f,
                               this
                             )),
      m_activeChild(-1),
      m_indices(),
      m_availableChildren()
    {
      // Nothing to do.
    }

    SelectorPanel::~SelectorPanel() {}

    void SelectorPanel::addChild(view::GraphicContainerShPtr child) {
      // Handle the creation of this child in the internal tables.
      bool replacedActiveChild = false;
      int indexToActivate = m_activeChild;
      if (child != nullptr) {
        // Remove existing child with similar name if any.
        std::unordered_map<std::string, int>::const_iterator childIterator = m_indices.find(child->getName());
        if (childIterator != m_indices.cend()) {
          if (childIterator->second < m_availableChildren.size()) {
            replacedActiveChild = (childIterator->second == m_activeChild);
            removeChild(m_availableChildren[childIterator->second]);
          }
          else {
            m_indices.erase(childIterator);
          }
        }

        // Add this child to the internal tables.
        m_indices[child->getName()] = m_availableChildren.size();
        indexToActivate = m_availableChildren.size();
        m_availableChildren.push_back(child);
      }

      // Check whether we should reactivate this child.
      if (replacedActiveChild) {
        setActiveChild(indexToActivate);
      }
    }

    void SelectorPanel::removeChild(view::GraphicContainerShPtr child) {
      // Handle the removal of this child in the internal tables.
      if (child != nullptr) {
        // Remove this child from internal tables.
        std::unordered_map<std::string, int>::const_iterator childIterator = m_indices.find(child->getName());
        if (childIterator != m_indices.cend()) {
          if (childIterator->second < m_availableChildren.size()) {
            if (m_activeChild == childIterator->second) {
              activateChild(-1);
            }
            m_availableChildren.erase(m_availableChildren.begin() + childIterator->second);
          }
          m_indices.erase(childIterator);
        }
      }
    }
  }
}
