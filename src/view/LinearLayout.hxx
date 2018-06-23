#ifndef LINEARLAYOUT_HXX
#define LINEARLAYOUT_HXX

#include "LinearLayout.h"

namespace ogame {
  namespace view {

    const LinearLayout::Direction& LinearLayout::getDirection() const noexcept {
      return m_direction;
    }

    const float& LinearLayout::getMargin() const noexcept {
      return m_margin;
    }

    const float& LinearLayout::getComponentMargin() const noexcept {
      return m_componentMargin;
    }

  }
}

#endif // LINEARLAYOUT_HXX
