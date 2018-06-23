#ifndef LINEARLAYOUT_HXX
#define LINEARLAYOUT_HXX

#include "LinearLayout.h"

namespace ogame {
  namespace view {

    const LinearLayout::Direction& LinearLayout::getDirection() const noexcept {
      return m_direction;
    }

  }
}

#endif // LINEARLAYOUT_HXX
