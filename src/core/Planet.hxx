#ifndef PLANET_HXX
#define PLANET_HXX

#include <algorithm>
#include <iostream>

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
    const float Planet::getProductionForResource(const std::string& resource, const float& hoursDuration) const {
      const Building::Type mineType = BuildingFactory::getMineTypeFromResource(resource);
      const Building& genericMineData = getBuildingData(mineType);
      const ResourceMine* mineData = genericMineData.asType<ResourceMine>();
      return hoursDuration * (getBasicProductionForMine(mineType) + mineData->getProduction(getMaxTemperature()));
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
    const unsigned& Planet::getFields() const noexcept {
      return m_fields;
    }

    inline
    const unsigned Planet::getUsedFields() const noexcept {
      unsigned usedFields = 0u;
      for (unsigned indexBuilding = 0u ; indexBuilding < m_buildings.size() ; ++indexBuilding) {
        if (m_buildings[indexBuilding] && m_buildings[indexBuilding]->getLevel() > 0u) {
          ++usedFields;
        }
      }
      return usedFields;
    }

    inline
    const std::string Planet::getCoordinates() const  {
      return "[" + std::to_string(getGalaxyIndex() + 1u) + ":" + std::to_string(getSystemIndex() + 1u) + ":" + std::to_string(getPositionInSystem() + 1u) + "]";
    }

    inline
    const unsigned Planet::getShipCount(const Ship::Type& type) const {
      return getShipData(type).getCount();
    }

    inline
    const core::Ship& Planet::getShipData(const Ship::Type& type) const {
      return *getDataOrThrow<Ship, Ship::Type>(type, m_ships);
    }

    inline
    const unsigned Planet::getDefenseCount(const Defense::Type& type) const {
      return getDefenseData(type).getCount();
    }

    inline
    const core::Defense& Planet::getDefenseData(const Defense::Type& type) const {
      return *getDataOrThrow<Defense, Defense::Type>(type, m_defenses);
    }

    inline
    const unsigned Planet::getBuildingLevel(const Building::Type& type) const {
      return getBuildingData(type).getLevel();
    }

    inline
    const Building& Planet::getBuildingData(const Building::Type& type) const {
      return *getDataOrThrow<Building, Building::Type>(type, m_buildings);
    }

    inline
    const std::vector<ResourceDepositShPtr>& Planet::getResourceDeposits() const noexcept {
      return m_resources;
    }

    inline
    const std::vector<std::shared_ptr<BuildingUpgradeAction>>& Planet::getBuildingUpgrades() const noexcept {
      return m_buildingUpgrades;
    }

    inline
    const std::vector<std::shared_ptr<ShipUpgradeAction>>& Planet::getShipUpgrades() const noexcept {
      return m_shipUpgrades;
    }

    inline
    const std::vector<std::shared_ptr<DefenseUpgradeAction>>& Planet::getDefenseUpgrades() const noexcept {
      return m_defenseUpgrades;
    }

    inline
    const bool Planet::canUpgrade(const Building& building) const {
      return building.canUpgrade(getResourceDeposits()) && m_buildingUpgrades.empty();
    }

    inline
    const bool Planet::canBuy(const FixedCostUnit& unit) const {
      return unit.canBuy(getResourceDeposits());
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

    template<typename Data, typename EnumClass>
    inline
    const unsigned Planet::getIndexForData(const EnumClass& type, const std::vector<std::shared_ptr<Data>>& elements) const noexcept {
      // Traverse the input vector.
      bool dataFound = false;
      unsigned indexData = 0u;
      while (indexData < elements.size() && !dataFound) {
        if (elements[indexData] != nullptr && elements[indexData]->getType() == type) {
          dataFound = true;
        }
        else {
          ++indexData;
        }
      }

      return indexData;
    }

    template<typename Data, typename EnumClass>
    inline
    std::shared_ptr<Data> Planet::getDataOrThrow(const EnumClass& type, const std::vector<std::shared_ptr<Data>>& elements) const {
      const unsigned indexData = getIndexForData(type, elements);

      if (indexData >= elements.size()) {
        const std::string errorMessage = std::string("Cannot retrieve data for value ") +
          std::to_string(static_cast<int>(type)) +
          ", data not available in planet " +
          getName();
        throw PlanetException(errorMessage);
      }

      if (elements[indexData] == nullptr) {
        const std::string errorMessage = std::string("Cannot retrieve data for value ") +
          std::to_string(static_cast<int>(type)) +
          ", invalid null data in planet " +
          getName();
        throw PlanetException(errorMessage);
      }

      return elements[indexData];
    }

    inline
    void Planet::decreaseResourceDepositFromCost(const std::unordered_map<Resource, float>& costs) {
      // Traverse the input map of resources.
      std::for_each(costs.cbegin(), costs.cend(),
        [this](const std::pair<Resource, float>& cost) {
          // Try to retrieve the corresponding resource deposit.
          ResourceDeposit* deposit = getDepositOrNullFromResource(cost.first);
          if (deposit == nullptr) {
            std::cerr << "[PLANET] Could not remove " << cost.second << " " << cost.first.getName() << " from planet " << getName() << std::endl;
          }
          else {
            deposit->decreaseValue(cost.second);
          }
        }
      );
    }

    inline
    const float Planet::getBasicProductionForMine(const Building::Type& mine) const noexcept {
      if (mine == Building::Type::MetalMine) {
        return 30.0f;
      }
      else if (mine == Building::Type::CrystalMine) {
        return 15.0f;
      }
      else {
        return 0.0f;
      }
    }

    inline
    ResourceDeposit* Planet::getDepositOrNullFromResource(const Resource& resource) {
      unsigned indexDeposit = 0u;
      while (indexDeposit < m_resources.size()) {
        if (m_resources[indexDeposit]->isOfResource(resource)) {
          return m_resources[indexDeposit].get();
        }
        ++indexDeposit;
      }
      return nullptr;
    }

  }
}

#endif // PLANET_HXX
