
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

    void UniverseRunnable::updatePlanetsForUniverse(const float& hoursDuration) {
      // Traverse all the planet of the system.
      for (unsigned indexGalaxy = 0u ; indexGalaxy < m_universe->getGalaxiesCount() ; ++indexGalaxy) {
        core::Galaxy& galaxy = (*m_universe)[indexGalaxy];
        for (unsigned indexSystem = 0u ; indexSystem < galaxy.getSystemsCount() ; ++indexSystem) {
          core::System& system = galaxy[indexSystem];
          for (unsigned indexPlanet = 0u ; indexPlanet < system.getPlanetsCount() ; ++indexPlanet) {
            core::Planet& planet = system[indexPlanet];

            // Check whether this planet is colonized.
            if (!planet.isColonized()) {
              continue;
            }

            try {
              updateResourcesForPlanet(planet, hoursDuration);
              updateUpgradeActionsForPlanet(planet);
            }
            catch (const ServerException& e) {
              std::cerr << "[UNIVERSE] Could not update planet " << planet.getName() << ":" << std::endl << e.what() << std::endl;
            }
          }
        }
      }
    }

    void UniverseRunnable::updateResourcesForPlanet(core::Planet& planet, const float& hoursDuration) {
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

    void UniverseRunnable::updateUpgradeActionsForPlanet(core::Planet& planet) {
      // Upgrade each type of action.
      upgradeBuildingActionsForPlanet(planet);
      upgradeShipActionsForPlanet(planet);
      upgradeDefenseActionsForPlanet(planet);
    }

    void UniverseRunnable::upgradeBuildingActionsForPlanet(core::Planet& planet) {
      // Retrieve the list of buildings upgrade.
      const std::vector<core::BuildingUpgradeActionShPtr>& buildings = planet.getBuildingUpgrades();

      std::vector<core::BuildingUpgradeActionShPtr> finished;
      for (unsigned indexBuildingUpgrade = 0u ; indexBuildingUpgrade < buildings.size() ; ++indexBuildingUpgrade) {
        core::BuildingUpgradeActionShPtr buildingUpgrade = buildings[indexBuildingUpgrade];
        std::cout << "[BUILDING] Still " << buildingUpgrade->getRemainingTime() << "s remaining for building upgrade " << std::endl;
        if (buildingUpgrade && buildingUpgrade->isFinished()) {
          finished.push_back(buildingUpgrade);
        }
      }

      for (unsigned indexFinished = 0u ; indexFinished < finished.size() ; ++indexFinished) {
        planet.upgrade(finished[indexFinished]->getType());
      }
    }

    void UniverseRunnable::upgradeShipActionsForPlanet(core::Planet& planet) {
      // Retrieve the list of ships upgrade.
      const std::vector<core::ShipUpgradeActionShPtr>& ships = planet.getShipUpgrades();

      std::vector<core::ShipUpgradeActionShPtr> finished;
      for (unsigned indexShipUpgrade = 0u ; indexShipUpgrade < ships.size() ; ++indexShipUpgrade) {
        core::ShipUpgradeActionShPtr shipUpgrade = ships[indexShipUpgrade];
        std::cout << "[BUILDING] Still " << shipUpgrade->getRemainingTime() << "s remaining for ship upgrade " << std::endl;
        if (shipUpgrade && shipUpgrade->isFinished()) {
          finished.push_back(shipUpgrade);
        }
      }

      for (unsigned indexFinished = 0u ; indexFinished < finished.size() ; ++indexFinished) {
        planet.launchShip(finished[indexFinished]->getType());
      }
    }

    void UniverseRunnable::upgradeDefenseActionsForPlanet(core::Planet& planet) {
      // Retrieve the list of defense upgrade.
      const std::vector<core::DefenseUpgradeActionShPtr>& defenses = planet.getDefenseUpgrades();

      std::vector<core::DefenseUpgradeActionShPtr> finished;
      for (unsigned indexDefenseUpgrade = 0u ; indexDefenseUpgrade < defenses.size() ; ++indexDefenseUpgrade) {
        core::DefenseUpgradeActionShPtr defenseUpgrade = defenses[indexDefenseUpgrade];
        std::cout << "[BUILDING] Still " << defenseUpgrade->getRemainingTime() << "s remaining for defense upgrade " << std::endl;
        if (defenseUpgrade && defenseUpgrade->isFinished()) {
          finished.push_back(defenseUpgrade);
        }
      }

      for (unsigned indexFinished = 0u ; indexFinished < finished.size() ; ++indexFinished) {
        planet.launchDefense(finished[indexFinished]->getType());
      }
    }

    void UniverseRunnable::updateAccountsForUniverse() {}

  }
}
