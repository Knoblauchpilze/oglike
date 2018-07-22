#ifndef SHIPYARDVIEW_HXX
#define SHIPYARDVIEW_HXX

#include "ShipyardView.h"

namespace ogame {
  namespace gui {

    inline
    const std::string ShipyardView::getShipCountFromType(const core::Ship::Type& type, const core::Planet& planet) const noexcept {
      return std::to_string(planet.getShipCount(type));
    }

  }
}

#endif // SHIPYARDVIEW_HXX
