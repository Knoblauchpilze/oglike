#ifndef FLEETVIEW_HXX
#define FLEETVIEW_HXX

#include "FleetView.h"

namespace ogame {
  namespace gui {

    inline
    const std::string FleetView::getShipCountFromType(const core::Ship::Type& type, const core::Planet& planet) const noexcept {
      return std::to_string(planet.getShipCount(type));
    }

  }
}

#endif // FLEETVIEW_HXX
