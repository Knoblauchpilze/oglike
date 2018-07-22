#ifndef DEFENSEVIEW_HXX
#define DEFENSEVIEW_HXX

#include "DefenseView.h"

namespace ogame {
  namespace gui {

    inline
    const std::string DefenseView::getDefenseCountFromType(const core::Defense::Type& type, const core::Planet& planet) const noexcept {
      return std::to_string(planet.getDefenseCount(type));
    }

  }
}

#endif // DEFENSEVIEW_HXX
