#ifndef GRIDLAYOUT_HXX
#define GRIDLAYOUT_HXX

#include <memory>
#include "GridLayout.h"

namespace ogame {
  namespace view {

    const unsigned& GridLayout::getWidth() const noexcept {
      return m_width;
    }

    const unsigned& GridLayout::getHeight() const noexcept {
      return m_height;
    }

    const float& GridLayout::getMargin() const noexcept {
      return m_margin;
    }

  }
}

#endif // GRIDLAYOUT_HXX
