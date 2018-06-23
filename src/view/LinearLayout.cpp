
#include "LinearLayout.h"

namespace ogame {
  namespace view {

    LinearLayout::LinearLayout(const Direction& direction, GraphicContainer* container):
      Layout(container),
      m_direction(direction)
    {
    }

    LinearLayout::~LinearLayout() {}

    void LinearLayout::update() {
      // TODO.
    }

  }
}
