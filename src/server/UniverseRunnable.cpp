
#include <iostream>
#include "UniverseRunnable.h"

namespace ogame {
  namespace server {

    UniverseRunnable::UniverseRunnable(core::UniverseShPtr universe):
      Runnable(),
      m_universe(universe)
    {
      // Nothing to do here.
    }

    UniverseRunnable::~UniverseRunnable() {}

    void UniverseRunnable::updateResourcesForUniverse(const float& hoursDuration) {
      // Traverse all the planet of the system.
      for (unsigned indexGalaxy = 0u ; indexGalaxy < m_universe->getGalaxiesCount() ; ++indexGalaxy) {
        core::Galaxy& galaxy = (*m_universe)[indexGalaxy];
        for (unsigned indexSystem = 0u ; indexSystem < galaxy.getSystemsCount() ; ++indexSystem) {
          core::System& system = galaxy[indexSystem];
          for (unsigned indexPlanet = 0u ; indexPlanet < system.getPlanetsCount() ; ++indexPlanet) {
            core::Planet& planet = system[indexPlanet];
            updateResourcesForPlanet(planet, hoursDuration);
          }
        }
      }
    }

    void UniverseRunnable::updateResourcesForPlanet(core::Planet& planet, const float& hoursDuration) {
      // Check whether this planet is colonized.
      if (!planet.isColonized()) {
        return;
      }

      try {
        // Retrieve the resources deposit for this planet.
        const std::vector<core::ResourceDepositShPtr>& planetDeposits = planet.getResourceDeposits();
        for (unsigned indexDeposit = 0u; indexDeposit < planetDeposits.size() ; ++indexDeposit) {
          // Retrieve the resource associated to this deposit.
          const core::ResourceDepositShPtr deposit = planetDeposits[indexDeposit];
          if (deposit == nullptr) {
            continue;
          }
          // Compute the increase in value for this resource.
          const float increase = planet.getProductionForResource(deposit->getResourceName(), hoursDuration);

          std::cout << "[UNIVERSE] " << deposit->getResourceName() << ": +" << increase << " for " << hoursDuration << "h (at " << planet.getName() << ")" << std::endl;

          // Update the deposit stock.
          deposit->increase(increase);
        }
      }
      catch (const std::bad_cast& e) {}
      catch (const ServerException& e) {
        std::cerr << "[UNIVERSE] Could not update planet " << planet.getName() << ":" << std::endl << e.what() << std::endl;
      }
    }

  }
}
