
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

    void LinearLayout::update() {
      // Check if a container is assigned to this layout.
      if (m_container == nullptr) {
        return;
      }
      // And if some items are managed by this layout.
      if (m_items.empty()) {
        return;
      }

      // Retrieve available dimensions.
      utils::Area window = m_container->getRenderingArea();

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
      std::for_each(m_items.begin(), m_items.end(),
        [cw, ch](GraphicContainer* item) {
          item->setSize(cw, ch);
        }
      );
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
