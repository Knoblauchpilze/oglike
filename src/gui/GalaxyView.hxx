#ifndef GALAXYVIEW_HXX
#define GALAXYVIEW_HXX

#include "GalaxyView.h"

namespace ogame {
  namespace gui {

    inline
    PlanetGalaxyEntryShPtr GalaxyView::createPlanetPanel(const unsigned& planetIndex, const unsigned& planetCount) const {
      return std::make_shared<PlanetGalaxyEntry>(planetIndex + 1u, planetCount, getNameOfPlanetPanelFromIndex(planetIndex));
    }

    inline
    std::string GalaxyView::getNameOfPlanetPanelFromIndex(const unsigned& planetIndex) const noexcept {
      return std::string("Planet ") + std::to_string(planetIndex) + " view";
    }

  }
}

#endif // GALAXYVIEW_HXX
