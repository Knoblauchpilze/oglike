#ifndef OVERVIEW_HXX
#define OVERVIEW_HXX

#include "Overview.h"
#include "PlanetException.h"
#include "DataModelException.h"

namespace ogame {
  namespace gui {

    inline
    void OverView::onActionTriggered(const player::GeneralDataModel& model) {
      // Process this action.
      try {
        const core::Planet& planet = model.getActivePlanet();
        populateWithPlanetData(planet);

        const core::Account& account = model.getActiveAccount();
        populateWithAccountData(account);
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[OVERVIEW] Caught exception while setting up overview:" << std::endl << e.what() << std::endl;
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[OVERVIEW] Caught exception while setting up overview:" << std::endl << e.what() << std::endl;
      }
    }

  }
}

#endif // OVERVIEW_HXX
