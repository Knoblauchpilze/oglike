#ifndef GALAXYVIEW_HXX
#define GALAXYVIEW_HXX

#include "GalaxyView.h"

namespace ogame {
  namespace gui {

    inline
    void GalaxyView::onActionTriggered(const player::GeneralDataModel& model, const player::Action& action) {
      // Process this action.
      try {
        const unsigned& galaxyCoord = model.getActiveGalaxyCoordinate();
        const unsigned& systemCoord = model.getActiveSystemCoordinate();
        const core::Account& activeAccount = model.getActiveAccount();
        const core::System& activeSystem = activeAccount.getSystem(core::SystemCoordinates(galaxyCoord, systemCoord));
        populateWithSystemData(activeSystem);
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[GALAXY] Caught exception while setting up galaxy view:" << std::endl << e.what() << std::endl;
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[GALAXY] Caught exception while setting up galaxy view:" << std::endl << e.what() << std::endl;
      }
    }

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
