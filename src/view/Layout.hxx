#ifndef LAYOUT_HXX
#define LAYOUT_HXX

#include "Layout.h"
#include "GraphicContainer.h"

namespace ogame {
  namespace view {

    inline
    void Layout::addItem(GraphicContainer* item) {
      if (getContainerOrNull(item) != nullptr) {
        m_items.push_back(item);
      }
    }

    inline
    void Layout::removeItem(GraphicContainer* item) {
      int index = 0;
      getContainerOrNull(item, &index);
      if (index < m_items.size()) {
        m_items.erase(m_items.cbegin() + index);
      }
    }

    inline
    GraphicContainer* Layout::getContainerOrNull(GraphicContainer* item, int* index) const {
      std::vector<GraphicContainer*>::const_iterator itemToFind = m_items.cbegin();
      int itemId = 0;
      while (itemToFind != m_items.cend() && item != *itemToFind) {
        ++itemToFind;
        ++itemId;
      }
      if (index != nullptr) {
        *index = itemId;
      }
      if (itemToFind == m_items.cend()) {
        return nullptr;
      }
      return *itemToFind;
    }

  }
}

#endif // LAYOUT_HXX
