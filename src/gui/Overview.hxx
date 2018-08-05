#ifndef OVERVIEW_HXX
#define OVERVIEW_HXX

#include "Overview.h"
#include "PlanetException.h"
#include "DataModelException.h"

namespace ogame {
  namespace gui {

    inline
    void OverView::onActionTriggered(const player::GeneralDataModel& model, const player::Action& action) {
      // Process this action.
      try {
        if (action == player::Action::ChangeAccount) {
          const core::Account& account = model.getActiveAccount();
          populateWithAccountData(account);
        }

        if (action == player::Action::ChangePlanet) {
          const core::Planet& planet = model.getActivePlanet();
          populateWithPlanetData(planet);
        }

        if (action == player::Action::ChangeUpgrade) {
          const core::Planet& planet = model.getActivePlanet();
          populateWithPlanetData(planet);
          const core::Account& account = model.getActiveAccount();
          populateWithAccountData(account);
        }
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
