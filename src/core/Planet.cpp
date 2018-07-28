
#include <iostream>
#include "Planet.h"
#include "System.h"
#include "PlanetException.h"

namespace ogame {
  namespace core {

    Planet::Planet(const unsigned& index, const std::string& name, System* system):
      m_index(index),
      m_name(name),
      m_parent(system),
      m_account(nullptr),
      m_ships(),
      m_defenses(),
      m_buildings(),
      
      m_diameter(12346.0f),
      m_minTemperature(-30.0f),
      m_maxTemperature(150.0f),

      m_buildingUpgrades(),
      m_shipUpgrades(),
      m_defenseUpgrades()
    {
      create();
    }

    Planet::~Planet()
    {
      //dtor
    }

    const unsigned Planet::getPositionInSystem() const {
      return m_parent->getPositionOf(*this);
    }

    const unsigned& Planet::getSystemIndex() const {
      if (m_parent == nullptr) {
        throw PlanetException(std::string("Could not retrieve system of planet ") + std::to_string(m_index) + " no associated system");
      }
      return m_parent->getIndex();
    }

    const unsigned& Planet::getGalaxyIndex() const {
      if (m_parent == nullptr) {
        throw PlanetException(std::string("Could not retrieve galaxy of planet ") + std::to_string(m_index) + " no associated system");
      }
      return m_parent->getGalaxyIndex();
    }

    const std::string& Planet::getOwnerName() const {
      if (m_account == nullptr) {
        throw PlanetException(std::string("Could not retrieve inexisting owner's name"));
      }
      return m_account->getPlayerName();
    }

    void Planet::assignToAccount(AccountShPtr account) {
      // Check account's validity.
      if (account == nullptr) {
        const std::string errorMessage = std::string("Cannot assign invalid account to planet [") +
          std::to_string(getGalaxyIndex()) + ":" +
          std::to_string(getSystemIndex()) + ":" +
          std::to_string(m_index) + "]";
        throw PlanetException(errorMessage);
      }

      // Assign the account to this planet.
      m_account = account;

      // Assign a default name
      m_name = generateRandomName(15u);

      std::cout << "[PLANET] Assigned new planet "
                << m_name
                << " at [" << getGalaxyIndex() << ":" << getSystemIndex() << ":" << m_index << "]"
                << " to player " << account->getPlayerName()
                << std::endl;

      account->setHomePlanet(this);
    }

    void Planet::createUpgradeAction(const Building::Type& type) {
      BuildingShPtr building = getDataOrThrow<Building, Building::Type>(type, m_buildings);

      if (m_account == nullptr) {
        const std::string errorMessage = std::string("Cannot upgrade building ") + std::to_string(static_cast<int>(type)) +
          " for planet " + getName() +
          " no associated account";
        throw PlanetException(errorMessage);
      }

      m_buildingUpgrades.push_back(std::make_shared<BuildingUpgradeAction>(building.get(), *this, *m_account));
    }

    void Planet::createUpgradeAction(const Ship::Type& type) {
      ShipShPtr ship = getDataOrThrow<Ship, Ship::Type>(type, m_ships);

      if (m_account == nullptr) {
        const std::string errorMessage = std::string("Cannot upgrade ship ") + std::to_string(static_cast<int>(type)) +
          " for planet " + getName() +
          " no associated account";
        throw PlanetException(errorMessage);
      }

      m_shipUpgrades.push_back(std::make_shared<ShipUpgradeAction>(ship.get(), *this, *m_account));
    }

    void Planet::createUpgradeAction(const Defense::Type& type) {
      DefenseShPtr defense = getDataOrThrow<Defense, Defense::Type>(type, m_defenses);

      if (m_account == nullptr) {
        const std::string errorMessage = std::string("Cannot upgrade defense ") + std::to_string(static_cast<int>(type)) +
          " for planet " + getName() +
          " no associated account";
        throw PlanetException(errorMessage);
      }

      m_defenseUpgrades.push_back(std::make_shared<DefenseUpgradeAction>(defense.get(), *this, *m_account));
    }

    void Planet::create() {
      // Push initial resources.
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("metal"), 500.0f));
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("crystal"), 500.0f));
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("deuterium"), 0.0f));

      // Create ships.
      initializeShips();

      // And defenses.
      initializeDefenses();

      // And buildings.
      initializeBuildings();
    }

  }
}
