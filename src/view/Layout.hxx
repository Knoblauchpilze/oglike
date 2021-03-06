#ifndef LAYOUT_HXX
#define LAYOUT_HXX

#include "Layout.h"
#include "GraphicContainer.h"

namespace ogame {
  namespace view {

    inline
    int Layout::addItem(std::shared_ptr<GraphicContainer> item) {
      if (item != nullptr && getContainerOrNull(item) == nullptr) {
        m_items.push_back(item);
        return m_items.size() - 1;
      }
      return -1;
    }

    inline
    int Layout::addItem(std::shared_ptr<GraphicContainer> item,
                        const unsigned& x,
                        const unsigned& y,
                        const unsigned& w,
                        const unsigned& h)
    {
      // No specialization at this level.
      return addItem(item);
    }

    inline
    void Layout::removeItem(std::shared_ptr<GraphicContainer> item) {
      int index = 0;
      getContainerOrNull(item, &index);
      if (index < m_items.size()) {
        m_items.erase(m_items.cbegin() + index);
      }
    }

    inline
    std::shared_ptr<GraphicContainer> Layout::getContainerOrNull(std::shared_ptr<GraphicContainer> item, int* index) const {
      std::vector<std::shared_ptr<GraphicContainer>>::const_iterator itemToFind = m_items.cbegin();
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
