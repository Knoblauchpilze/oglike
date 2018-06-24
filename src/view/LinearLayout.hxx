#ifndef LINEARLAYOUT_HXX
#define LINEARLAYOUT_HXX

#include "LinearLayout.h"

namespace ogame {
  namespace view {

    inline
    const LinearLayout::Direction& LinearLayout::getDirection() const noexcept {
      return m_direction;
    }

    inline
    const float& LinearLayout::getMargin() const noexcept {
      return m_margin;
    }

    inline
    const float& LinearLayout::getComponentMargin() const noexcept {
      return m_componentMargin;
    }

  }
}

#endif // LINEARLAYOUT_HXX
