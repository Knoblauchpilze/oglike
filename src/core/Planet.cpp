
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
      
      m_diameter(0.0f),
      m_fields(0u),
      m_minTemperature(0.0f),
      m_maxTemperature(0.0f),

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

      // Decrease the amount of resources in the deposit of this planet.
      decreaseResourceDepositFromCost(building->getUpgradeCost());

      // Add the building upgrade action.
      m_buildingUpgrades.push_back(std::make_shared<BuildingUpgradeAction>(building.get(), *this, *m_account));
    }

    void Planet::createUpgradeAction(const Ship::Type& type, const unsigned& number) {
      ShipShPtr ship = getDataOrThrow<Ship, Ship::Type>(type, m_ships);

      if (m_account == nullptr) {
        const std::string errorMessage = std::string("Cannot upgrade ship ") + std::to_string(static_cast<int>(type)) +
          " for planet " + getName() +
          " no associated account";
        throw PlanetException(errorMessage);
      }

      // Decrease the amount of resources in the deposit of this planet.
      decreaseResourceDepositFromCost(ship->getCost());

      // Add the ship upgrade action.
      m_shipUpgrades.push_back(std::make_shared<ShipUpgradeAction>(
        ship.get(),
        *this,
        *m_account,
        number
      ));
    }

    void Planet::createUpgradeAction(const Defense::Type& type, const unsigned& number) {
      DefenseShPtr defense = getDataOrThrow<Defense, Defense::Type>(type, m_defenses);

      if (m_account == nullptr) {
        const std::string errorMessage = std::string("Cannot upgrade defense ") + std::to_string(static_cast<int>(type)) +
          " for planet " + getName() +
          " no associated account";
        throw PlanetException(errorMessage);
      }

      // Decrease the amount of resources in the deposit of this planet.
      decreaseResourceDepositFromCost(defense->getCost());

      // Add the defense upgrade action.
      m_defenseUpgrades.push_back(std::make_shared<DefenseUpgradeAction>(
        defense.get(),
        *this,
        *m_account,
        number
      ));
    }

    const bool Planet::canResearch(const Research& research) const {
      return research.canUpgrade(getResourceDeposits()) && (!m_account || m_account->canResearch(research));
    }

    void Planet::launchShip(const Ship::Type& ship) {
      // Retrieve the corresponding ship and upgrade it.
      Ship& shipElement = getShipDataPrivate(ship);
      shipElement.launchUnit();

      // Find the first occurrence of this upgrade action and handle the upgrade.
      unsigned indexShip = 0u;
      while (indexShip < m_shipUpgrades.size() && m_shipUpgrades[indexShip]->getType() != ship) {
        ++indexShip;
      }

      if (indexShip < m_shipUpgrades.size()) {
        m_shipUpgrades[indexShip]->decreaseCount();
        if (m_shipUpgrades[indexShip]->isFinished()) {
          m_shipUpgrades.erase(m_shipUpgrades.cbegin() + indexShip);
        }
      }
      else {
        throw PlanetException(std::string("Cannot upgrade ship ") + std::to_string(static_cast<int>(ship)) + " not found in planet " + getName() + " upgrade actions");
      }
    }

    void Planet::create() {
      // Push initial resources.
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("metal"), 15500.0f));
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("crystal"), 25500.0f));
      m_resources.push_back(std::make_shared<ResourceDeposit>(std::string("deuterium"), 3000.0f));

      initializeShips();

      initializeDefenses();

      initializeBuildings();

      initializePhysicalCharacteristics();
    }

    void Planet::initializePhysicalCharacteristics() {
      m_fields = 96u + std::rand() % (262u - 96u);
      m_diameter = 12742.0f * m_fields / 163.0f;
      m_minTemperature = -150.0f + (200.0f + 150.0f) / std::max(1.0f, 1.0f * (m_parent->getPlanetsCount() - m_index));
      m_maxTemperature = -110.0f + (240.0f + 110.0f) / std::max(1.0f, 1.0f * (m_parent->getPlanetsCount() - m_index));
    }

  }
}
