#ifndef GRIDLAYOUT_HXX
#define GRIDLAYOUT_HXX

#include <memory>
#include "GridLayout.h"

namespace ogame {
  namespace view {

    inline
    const unsigned& GridLayout::getWidth() const noexcept {
      return m_width;
    }

    inline
    const unsigned& GridLayout::getHeight() const noexcept {
      return m_height;
    }

    inline
    const float& GridLayout::getMargin() const noexcept {
      return m_margin;
    }

  }
}

#endif // GRIDLAYOUT_HXX
