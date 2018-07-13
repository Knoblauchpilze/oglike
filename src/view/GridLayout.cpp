
#include "GridLayout.h"

namespace ogame {
  namespace view {

    GridLayout::GridLayout(const unsigned& width, const unsigned& height, const float& margin, GraphicContainer* container):
      Layout(container),
      m_width(width),
      m_height(height),
      m_margin(margin),
      m_itemsLocation()
    {
      // Nothing to do.
    }

    GridLayout::~GridLayout() {}

    void GridLayout::updatePrivate(const utils::Area& window) {
      // Compute available dimensions.
      const float cw = (window.w() - 2.0f * m_margin) / m_width;
      const float ch = (window.h() - 2.0f * m_margin) / m_height;

      // Apply the new size to each item based on its proportion of the total area occupied by this component.
      for (std::unordered_map<int, ItemInfo>::const_iterator item = m_itemsLocation.cbegin() ;
           item != m_itemsLocation.cend() ;
           ++item)
      {
        m_items[item->first]->setRenderingArea(utils::Area(
          m_margin + item->second.x * cw,
          m_margin + item->second.y * ch,
          cw * item->second.w,
          ch * item->second.h
        ));
      }
    }

    int GridLayout::addItem(std::shared_ptr<GraphicContainer> container,
                             const unsigned& x,
                             const unsigned& y,
                             const unsigned& w,
                             const unsigned& h)
    {
      int containerIndex = Layout::addItem(container);
      m_itemsLocation[containerIndex] = {
        1.0f * std::min(m_width - 1, x),
        1.0f * std::min(m_height - 1, y),
        1.0f * std::min(m_width - x, w),
        1.0f * std::min(m_height - y, h)
      };
      return containerIndex;
    }

  }
}
