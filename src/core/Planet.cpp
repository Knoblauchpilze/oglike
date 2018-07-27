
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
      m_maxTemperature(150.0f)
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
      // Traverse the set of buildings.
      BuildingShPtr building = nullptr;
      unsigned indexBuildings = 0u;
      while (indexBuildings < m_buildings.size() && building == nullptr) {
        if (m_buildings[indexBuildings] != nullptr && m_buildings[indexBuildings]->getType() == type) {
          building = m_buildings[indexBuildings];
        }
        ++indexBuildings;
      }

      if (indexBuildings >= m_buildings.size() && building == nullptr) {
        const std::string errorMessage = std::string("Cannot create upgrade for buildings ") +
          std::to_string(static_cast<int>(type)) +
          ", data not available in planet " +
          getName();
        throw PlanetException(errorMessage);
      }

      //
    }

    void Planet::createUpgradeAction(const Ship::Type& type) {
      // Traverse the set of ships.
      ShipShPtr ship = nullptr;
      unsigned indexShip = 0u;
      while (indexShip < m_ships.size() && ship == nullptr) {
        if (m_ships[indexShip] != nullptr && m_ships[indexShip]->getType() == type) {
          ship = m_ships[indexShip];
        }
        ++indexShip;
      }

      if (indexShip >= m_ships.size() && ship == nullptr) {
        const std::string errorMessage = std::string("Cannot create upgrade for ship ") +
          std::to_string(static_cast<int>(type)) +
          ", data not available in planet " +
          getName();
        throw PlanetException(errorMessage);
      }

      //
    }

    void Planet::createUpgradeAction(const Defense::Type& type) {
      // Traverse the set of defenses.
      DefenseShPtr defense = nullptr;
      unsigned indexDefenses = 0u;
      while (indexDefenses < m_defenses.size() && defense == nullptr) {
        if (m_defenses[indexDefenses] != nullptr && m_defenses[indexDefenses]->getType() == type) {
          defense = m_defenses[indexDefenses];
        }
        ++indexDefenses;
      }

      if (indexDefenses >= m_defenses.size() || defense == nullptr) {
        const std::string errorMessage = std::string("Cannot create upgrade for defense ") +
          std::to_string(static_cast<int>(type)) +
          ", data not available in planet " +
          getName();
        throw PlanetException(errorMessage);
      }

      //
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
