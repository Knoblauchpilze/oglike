
#include "LinearLayout.h"
#include "Area.h"

namespace ogame {
  namespace view {

    LinearLayout::LinearLayout(const Direction& direction, const float& margin, const float& interMargin, GraphicContainer* container):
      Layout(container),
      m_direction(direction),
      m_margin(margin),
      m_componentMargin(interMargin)
    {
      // Nothing to do.
    }

    LinearLayout::~LinearLayout() {}

    void LinearLayout::updatePrivate(const utils::Area& window) {
      // Split the available space according to the number of elements to space.
      float cw, ch;
      switch(m_direction) {
        case Direction::Horizontal:
          handleHorizontalLayout(window, cw, ch);
          break;
        case Direction::Vertical:
        default:
          handleVerticalLayout(window, cw, ch);
          break;
      }

      // Apply the computed dimensions to each item handled by the layout.
      for (int indexItem = 0 ; indexItem < m_items.size() ; ++indexItem) {
        // Compute the position of the component.
        const float x = m_margin + (m_direction == Direction::Horizontal ? (indexItem - 1) * (cw + m_componentMargin) : 0.0f);
        const float y = m_margin + (m_direction == Direction::Vertical   ? (indexItem - 1) * (ch + m_componentMargin) : 0.0f);

        // Apply the final rendering area.
        m_items[indexItem]->setRenderingArea(utils::Area(x, y, cw, ch));
      }
    }

    void LinearLayout::handleHorizontalLayout(const utils::Area& totalArea, float& cw, float& ch) const {
      cw = (totalArea.w() - 2.0f * m_margin - (m_items.size() * m_componentMargin)) / (1.0f * m_items.size());
      ch = totalArea.h() - 2.0f * m_margin;
    }

    void LinearLayout::handleVerticalLayout(const utils::Area& totalArea, float& cw, float& ch) const {
      cw = totalArea.w() - 2.0f * m_margin;
      ch = (totalArea.h() - 2.0f * m_margin - (m_items.size() * m_componentMargin)) / (1.0f * m_items.size());
    }

  }
}
