
#include <iostream>
#include "UniverseRunnable.h"
#include "SystemException.h"
#include "GalaxyException.h"

namespace ogame {
  namespace server {

    UniverseRunnable::UniverseRunnable(core::UniverseShPtr universe,
                                       player::GeneralDataModelShPtr model):
      Runnable(),
      m_universe(universe),
      m_model(model)
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
            // Retrieve the current account and check coherence.
            core::Planet& planet = system[indexPlanet];

            // Check whether this planet is colonized.
            if (!planet.isColonized()) {
              continue;
            }

            // Determine whether this is the active planet.
            const bool activePlanet = m_model->getActivePlanet() == planet;

            // Perform updates.
            bool resourcesModified = false;
            bool actionsModified = false;
            bool fleetsModified = false;
            bool planetModified = false;
            try {
              resourcesModified = updateResourcesForPlanet(planet, hoursDuration);
              actionsModified = updateUpgradeActionsForPlanet(planet, &planetModified);
              fleetsModified = updateFleetsForPlanet(planet, &planetModified);
            }
            catch (const core::PlanetException& e) {
              std::cerr << "[UNIVERSE] Could not update planet " << planet.getName() << ":" << std::endl << e.what() << std::endl;
            }
            catch (const core::SystemException& e) {
              std::cerr << "[UNIVERSE] Could not update planet " << planet.getName() << ":" << std::endl << e.what() << std::endl;
            }
            catch (const core::GalaxyException& e) {
              std::cerr << "[UNIVERSE] Could not update planet " << planet.getName() << ":" << std::endl << e.what() << std::endl;
            }

            // Check whether an action should be triggered.
            if (activePlanet) {
              if (planetModified) {
                m_model->triggerAction(player::Action::ChangePlanet);
              }
              if (resourcesModified) {
                m_model->triggerAction(player::Action::ChangeResources);
              }
              if (actionsModified) {
                m_model->triggerAction(player::Action::ChangeUpgrade);
              }
              if (fleetsModified) {
                std::cout << "[UNIVERSE] Should update planet " << planet.getName() << " after update" << std::endl;
              }
            }
          }
        }
      }
    }

    const bool UniverseRunnable::updateResourcesForPlanet(core::Planet& planet, const float& hoursDuration) {
      bool modifiedResources = false;

      // Retrieve the resources deposit for this planet.
      const std::vector<core::ResourceDepositShPtr>& planetDeposits = planet.getResourceDeposits();
      for (unsigned indexDeposit = 0u; indexDeposit < planetDeposits.size() ; ++indexDeposit) {
        // Retrieve the resource associated to this deposit.
        const core::ResourceDepositShPtr deposit = planetDeposits[indexDeposit];
        if (deposit == nullptr) {
          continue;
        }

        // Compute the increase in value for this resource.
        const float increase = planet.getProductionForResource(
          deposit->getResourceName(),
          hoursDuration,
          m_universe->getSpeed()
        );

        const float decrease = planet.getConsumptionForResource(
          deposit->getResourceName(),
          hoursDuration,
          m_universe->getSpeed()
        );

        if (increase > 0.0f || decrease < 0.0f) {
          modifiedResources = true;
        }

        // Update the deposit stock.
        deposit->increase(increase + decrease);
      }

      // Notifyt modifications on this planet.
      return modifiedResources;
    }

    const bool UniverseRunnable::updateUpgradeActionsForPlanet(core::Planet& planet, bool* actionFinished) {
      // Upgrade each type of action.
      const bool buildingsModified = updateBuildingActionsForPlanet(planet, actionFinished);
      const bool shipsModified = updateShipActionsForPlanet(planet, actionFinished);
      const bool defensesModified = updateDefenseActionsForPlanet(planet, actionFinished);

      return buildingsModified || shipsModified || defensesModified;
    }

    const bool UniverseRunnable::updateBuildingActionsForPlanet(core::Planet& planet, bool* actionFinished) {
      // Retrieve the list of buildings upgrade.
      const std::vector<core::BuildingUpgradeActionShPtr>& buildings = planet.getBuildingUpgrades();

      std::vector<core::BuildingUpgradeActionShPtr> finished;
      for (unsigned indexBuildingUpgrade = 0u ; indexBuildingUpgrade < buildings.size() ; ++indexBuildingUpgrade) {
        core::BuildingUpgradeActionShPtr buildingUpgrade = buildings[indexBuildingUpgrade];
        std::cout << "[RUNNABLE] Still " << buildingUpgrade->getRemainingTime() << "s remaining for building upgrade " << std::endl;
        if (buildingUpgrade && buildingUpgrade->isFinished()) {
          finished.push_back(buildingUpgrade);
        }
      }

      for (unsigned indexFinished = 0u ; indexFinished < finished.size() ; ++indexFinished) {
        planet.upgrade(finished[indexFinished]->getType());
      }

      if (actionFinished && !finished.empty()) {
        *actionFinished = true;
      }

      // Notify modifications on this planet.
      return !buildings.empty();
    }

    const bool UniverseRunnable::updateShipActionsForPlanet(core::Planet& planet, bool* actionFinished) {
      // Retrieve the list of ships upgrade.
      const std::vector<core::ShipUpgradeActionShPtr>& ships = planet.getShipUpgrades();

      std::vector<core::ShipUpgradeActionShPtr> finished;
      for (unsigned indexShipUpgrade = 0u ; indexShipUpgrade < ships.size() ; ++indexShipUpgrade) {
        core::ShipUpgradeActionShPtr shipUpgrade = ships[indexShipUpgrade];
        std::cout << "[RUNNABLE] Still " << shipUpgrade->getRemainingTime() << "s remaining for ship upgrade " << std::endl;
        if (shipUpgrade && shipUpgrade->isFinished()) {
          finished.push_back(shipUpgrade);
        }
      }

      for (unsigned indexFinished = 0u ; indexFinished < finished.size() ; ++indexFinished) {
        planet.launchShip(finished[indexFinished]->getType());
      }

      if (actionFinished && !finished.empty()) {
        *actionFinished = true;
      }

      // Notify modifications on this planet.
      return !ships.empty();
    }

    const bool UniverseRunnable::updateDefenseActionsForPlanet(core::Planet& planet, bool* actionFinished) {
      // Retrieve the list of defense upgrade.
      const std::vector<core::DefenseUpgradeActionShPtr>& defenses = planet.getDefenseUpgrades();

      std::vector<core::DefenseUpgradeActionShPtr> finished;
      for (unsigned indexDefenseUpgrade = 0u ; indexDefenseUpgrade < defenses.size() ; ++indexDefenseUpgrade) {
        core::DefenseUpgradeActionShPtr defenseUpgrade = defenses[indexDefenseUpgrade];
        std::cout << "[RUNNABLE] Still " << defenseUpgrade->getRemainingTime() << "s remaining for defense upgrade " << std::endl;
        if (defenseUpgrade && defenseUpgrade->isFinished()) {
          finished.push_back(defenseUpgrade);
        }
      }

      for (unsigned indexFinished = 0u ; indexFinished < finished.size() ; ++indexFinished) {
        planet.launchDefense(finished[indexFinished]->getType());
      }

      if (actionFinished && !finished.empty()) {
        *actionFinished = true;
      }

      // Notify modifications on this planet.
      return !defenses.empty();
    }

    const bool UniverseRunnable::updateFleetsForPlanet(core::Planet& planet, bool* actionFinished) {
      // TODO.
      return false;
    }

    void UniverseRunnable::updateAccountsForUniverse() {
      const std::vector<core::AccountShPtr>& accounts = m_universe->getAccounts();
      for (unsigned indexAccount = 0u; indexAccount < accounts.size() ; ++indexAccount) {
        // Retrieve the current account and check coherence.
        const core::AccountShPtr account = accounts[indexAccount];
        if (account == nullptr) {
          continue;
        }

        // Determine whether this is the active account.
        const bool activeAccount = m_model->getActiveAccount() == *account;

        // Perform updates.
        bool actionsModified = false;
        bool accountModified = false;
        try {
          actionsModified = updateUpgradeActionsForAccount(*account, &accountModified);
        }
        catch (const core::AccountException& e) {
          std::cerr << "[UNIVERSE] Could not update account " << account->getPlayerName() << ":" << std::endl << e.what() << std::endl;
        }

        // Check whether an action should be triggered.
        if (activeAccount) {
          if (accountModified) {
            m_model->triggerAction(player::Action::ChangeAccount);
          }
          if (actionsModified) {
            m_model->triggerAction(player::Action::ChangeUpgrade);
          }
        }
      }
    }

    const bool UniverseRunnable::updateUpgradeActionsForAccount(core::Account& account, bool* actionFinished) {
      // Retrieve the list of defense upgrade.
      const std::vector<core::ResearchUpgradeActionShPtr>& researches = account.getResearchUpgrades();

      std::vector<core::ResearchUpgradeActionShPtr> finished;
      for (unsigned indexResearchUpgrade = 0u ; indexResearchUpgrade < researches.size() ; ++indexResearchUpgrade) {
        core::ResearchUpgradeActionShPtr researchUpgrade = researches[indexResearchUpgrade];
        std::cout << "[RUNNABLE] Still " << researchUpgrade->getRemainingTime() << "s remaining for research upgrade " << std::endl;
        if (researchUpgrade && researchUpgrade->isFinished()) {
          finished.push_back(researchUpgrade);
        }
      }

      for (unsigned indexFinished = 0u ; indexFinished < finished.size() ; ++indexFinished) {
        account.upgrade(finished[indexFinished]->getType());
      }

      if (actionFinished && !finished.empty()) {
        *actionFinished = true;
      }

      // Notify modifications on this account.
      return !researches.empty();
    }

  }
}
