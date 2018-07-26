#ifndef PLANET_HXX
#define PLANET_HXX

#include "Planet.h"
#include "PlanetException.h"
#include "DefenseFactory.h"
#include "ShipFactory.h"
#include "BuildingFactory.h"

namespace ogame {
  namespace core {

    inline
    bool Planet::operator==(const Planet& other) const noexcept {
      return other.m_index == m_index;
    }

    inline
    const std::string& Planet::getName() const noexcept {
      return m_name;
    }

    inline
    const bool Planet::isColonized() const noexcept {
      return m_account != nullptr;
    }

    inline
    const bool Planet::hasMoon() const noexcept {
      return false;
    }

    inline
    const bool Planet::hasWreckfield() const noexcept {
      return false;
    }

    inline
    const std::string Planet::generateRandomName(const unsigned& length) const noexcept {
      std::string name;
      name.resize(length);
      unsigned index = 0u;
      while (index < length) {
        name[index] = 'a' + std::rand() % ('z' - 'a');
        ++index;
      }
      return name;
    }

    inline
    const float Planet::getResourceQuantity(const std::string& name) const {
      // Search across the resource deposit for this planet.
      unsigned indexDeposit = 0u;
      while (indexDeposit < m_resources.size()) {
        if (m_resources[indexDeposit] != nullptr && m_resources[indexDeposit]->getResourceName() == name) {
          return m_resources[indexDeposit]->getValue();
        }
        ++indexDeposit;
      }

      // If no deposit for this resource exists on this planet, assume the quantity is 0.
      return 0.0f;
    }

    inline
    const System& Planet::getSystem() const {
      if (m_parent == nullptr) {
        throw PlanetException(std::string("Could not retrieve system of planet ") + std::to_string(m_index) + " no associated system");
      }
      return *m_parent;
    }

    inline
    const float& Planet::getDiameter() const noexcept {
      return m_diameter;
    }

    inline
    const float& Planet::getMinTemperature() const noexcept {
      return m_minTemperature;
    }

    inline
    const float& Planet::getMaxTemperature() const noexcept {
      return m_maxTemperature;
    }

    inline
    const std::string Planet::getCoordinates() const  {
      return "[" + std::to_string(getGalaxyIndex() + 1u) + ":" + std::to_string(getSystemIndex() + 1u) + ":" + std::to_string(getPositionInSystem() + 1u) + "]";
    }

    inline
    const unsigned Planet::getShipCount(const Ship::Type& type) const {
      // Traverse the set of ships.
      unsigned indexShip = 0u;
      while (indexShip < m_ships.size()) {
        if (m_ships[indexShip] != nullptr && m_ships[indexShip]->getType() == type) {
          return m_ships[indexShip]->getCount();
        }
        ++indexShip;
      }

      // Ship not found, assume 0 count.
      return 0u;
    }

    inline
    const core::Ship& Planet::getShipData(const Ship::Type& type) const {
      // Traverse the set of ships.
      unsigned indexShip = 0u;
      while (indexShip < m_ships.size()) {
        if (m_ships[indexShip] != nullptr && m_ships[indexShip]->getType() == type) {
          return *m_ships[indexShip];
        }
        ++indexShip;
      }

      // Ship not found, this is a problem.
      const std::string errorMessage = std::string("Cannot retrieve data for ship ") +
        std::to_string(static_cast<int>(type)) +
        ", data not available in planet " +
        getName();
      throw PlanetException(errorMessage);
    }

    inline
    const unsigned Planet::getDefenseCount(const Defense::Type& type) const {
      // Traverse the set of defenses.
      unsigned indexDefense = 0u;
      while (indexDefense < m_defenses.size()) {
        if (m_defenses[indexDefense] != nullptr && m_defenses[indexDefense]->getType() == type) {
          return m_defenses[indexDefense]->getCount();
        }
        ++indexDefense;
      }

      // Defense not found, assume 0 count.
      return 0u;
    }

    inline
    const core::Defense& Planet::getDefenseData(const Defense::Type& type) const {
      // Traverse the set of defenses.
      unsigned indexDefenses = 0u;
      while (indexDefenses < m_defenses.size()) {
        if (m_defenses[indexDefenses] != nullptr && m_defenses[indexDefenses]->getType() == type) {
          return *m_defenses[indexDefenses];
        }
        ++indexDefenses;
      }

      // Defense not found, this is a problem.
      const std::string errorMessage = std::string("Cannot retrieve data for defense ") +
        std::to_string(static_cast<int>(type)) +
        ", data not available in planet " +
        getName();
      throw PlanetException(errorMessage);
    }

    inline
    const unsigned Planet::getBuildingLevel(const Building::Type& type) const {
      // Traverse the set of buildings.
      unsigned indexBuildings = 0u;
      while (indexBuildings < m_buildings.size()) {
        if (m_buildings[indexBuildings] != nullptr && m_buildings[indexBuildings]->getType() == type) {
          return m_buildings[indexBuildings]->getLevel();
        }
        ++indexBuildings;
      }

      // Building not found, assume 0 level.
      return 0u;
    }

    inline
    const Building& Planet::getBuildingData(const Building::Type& type) const {
      // Traverse the set of buildings.
      unsigned indexBuildings = 0u;
      while (indexBuildings < m_buildings.size()) {
        if (m_buildings[indexBuildings] != nullptr && m_buildings[indexBuildings]->getType() == type) {
          return *m_buildings[indexBuildings];
        }
        ++indexBuildings;
      }

      // Building not found, this is a problem.
      const std::string errorMessage = std::string("Cannot retrieve data for building ") +
        std::to_string(static_cast<int>(type)) +
        ", data not available in planet " +
        getName();
      throw PlanetException(errorMessage);
    }

    inline
    const std::vector<ResourceDepositShPtr>& Planet::getResourceDeposits() const noexcept {
      return m_resources;
    }

    inline
    void Planet::initializeShips() {
      // Create all ships on this planet.
      m_ships.push_back(ShipFactory::createLightFighter());
      m_ships.push_back(ShipFactory::createHeavyFighter());
      m_ships.push_back(ShipFactory::createCruiser());
      m_ships.push_back(ShipFactory::createBattleship());

      m_ships.push_back(ShipFactory::createSmallCargo());
      m_ships.push_back(ShipFactory::createLargeCargo());
      m_ships.push_back(ShipFactory::createColony());

      m_ships.push_back(ShipFactory::createBattlecruiser());
      m_ships.push_back(ShipFactory::createBomber());
      m_ships.push_back(ShipFactory::createDestroyer());
      m_ships.push_back(ShipFactory::createDeathstar());

      m_ships.push_back(ShipFactory::createRecycler());
      m_ships.push_back(ShipFactory::createEspionageProbe());
      m_ships.push_back(ShipFactory::createSolarSatellite());
    }

    inline
    void Planet::initializeDefenses() {
      m_defenses.push_back(DefenseFactory::createMissileLauncher());
      m_defenses.push_back(DefenseFactory::createLightLaser());
      m_defenses.push_back(DefenseFactory::createHeavyLaser());
      m_defenses.push_back(DefenseFactory::createGaussCannon());
      m_defenses.push_back(DefenseFactory::createIonCannon());
      m_defenses.push_back(DefenseFactory::createPlasmaTurret());
      m_defenses.push_back(DefenseFactory::createSmallShieldDome());
      m_defenses.push_back(DefenseFactory::createLargeShieldDome());
      m_defenses.push_back(DefenseFactory::createAntiballisticMissile());
      m_defenses.push_back(DefenseFactory::createInterplanetaryMissile());
    }

    inline
    void Planet::initializeBuildings() {
      m_buildings.push_back(BuildingFactory::createMetalMine());
      m_buildings.push_back(BuildingFactory::createCrystalMine());
      m_buildings.push_back(BuildingFactory::createDeuteriumMine());

      m_buildings.push_back(BuildingFactory::createMetalStorage());
      m_buildings.push_back(BuildingFactory::createCrystalStorage());
      m_buildings.push_back(BuildingFactory::createDeuteriumStorage());

      m_buildings.push_back(BuildingFactory::createSolarPlant());
      m_buildings.push_back(BuildingFactory::createFusionPlant());

      m_buildings.push_back(BuildingFactory::createRoboticsFactory());
      m_buildings.push_back(BuildingFactory::createShipyard());
      m_buildings.push_back(BuildingFactory::createResearchLab());
      m_buildings.push_back(BuildingFactory::createAllianceDepot());
      m_buildings.push_back(BuildingFactory::createMissileSilo());
      m_buildings.push_back(BuildingFactory::createNaniteFactory());
      m_buildings.push_back(BuildingFactory::createTerraformer());
      m_buildings.push_back(BuildingFactory::createSpaceDock());
    }

  }
}

#endif // PLANET_HXX
