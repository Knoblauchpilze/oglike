
#include "GridLayout.h"

namespace ogame {
  namespace view {

    GridLayout::GridLayout(const unsigned& width, const unsigned& height, GraphicContainer* container):
      Layout(container),
      m_width(width),
      m_height(height)
    {
    }

    GridLayout::~GridLayout() {}

    void GridLayout::update() {
      // TODO.
    }

  }
}
