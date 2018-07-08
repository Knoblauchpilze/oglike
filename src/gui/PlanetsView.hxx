#ifndef PLANETSVIEW_HXX
#define PLANETSVIEW_HXX

#include "PlanetsView.h"

namespace ogame {
  namespace gui {

    inline
    PlanetViewLinkShPtr PlanetsView::createPlanetView(const std::string& name, const unsigned& planetCount) const {
      return std::make_shared<PlanetViewLink>(name, planetCount);
    }

  }
}

#endif // PLANETSVIEW_HXX
