#ifndef PLANET_H
#define PLANET_H

#include <memory>
#include <string>
#include <vector>

#include "ResourceDeposit.h"
#include "Account.h"
#include "Ship.h"
#include "Defense.h"
#include "Building.h"
#include "BuildingUpgradeAction.h"
#include "ResearchUpgradeAction.h"
#include "ShipUpgradeAction.h"
#include "DefenseUpgradeAction.h"

namespace ogame {
  namespace core {

    class System;
    class Account;

    class ShipUpgradeAction;

    class Planet
    {
      public:

        Planet(const unsigned& index, const std::string& name, System* system);

        virtual ~Planet();

        bool operator==(const Planet& other) const noexcept;

        const std::string& getName() const noexcept;

        const bool isColonized() const noexcept;

        const bool hasMoon() const noexcept;

        const bool hasWreckfield() const noexcept;

        const unsigned getPositionInSystem() const;

        const unsigned& getSystemIndex() const;

        const unsigned& getGalaxyIndex() const;

        const std::string& getOwnerName() const;

        void assignToAccount(std::shared_ptr<Account> account);

        const float getResourceQuantity(const std::string& name) const;

        const float getProductionForResource(const std::string& resource,
                                             const float& hoursDuration,
                                             const unsigned& universeSpeed) const;

        const System& getSystem() const;

        const float& getDiameter() const noexcept;

        const float& getMinTemperature() const noexcept;

        const float& getMaxTemperature() const noexcept;

        const unsigned& getFields() const noexcept;

        const unsigned getUsedFields() const noexcept;

        const std::string getCoordinates() const;

        const unsigned getShipCount(const Ship::Type& type) const;

        const Ship& getShipData(const Ship::Type& type) const;

        const unsigned getDefenseCount(const Defense::Type& type) const;

        const Defense& getDefenseData(const Defense::Type& type) const;

        const unsigned getBuildingLevel(const Building::Type& type) const;

        const Building& getBuildingData(const Building::Type& type) const;

        const std::vector<ResourceDepositShPtr>& getResourceDeposits() const noexcept;

        void createUpgradeAction(const Building::Type& type);

        void createUpgradeAction(const Ship::Type& type, const unsigned& number);

        void createUpgradeAction(const Defense::Type& type, const unsigned& number);

        const std::vector<std::shared_ptr<BuildingUpgradeAction>>& getBuildingUpgrades() const noexcept;

        const std::vector<std::shared_ptr<ShipUpgradeAction>>& getShipUpgrades() const noexcept;

        const std::vector<std::shared_ptr<DefenseUpgradeAction>>& getDefenseUpgrades() const noexcept;

        const bool canUpgrade(const Building& building) const;

        const bool canResearch(const Research& research) const;

        const bool canBuy(const FixedCostUnit& unit) const;

        void upgrade(const Building::Type& building);

        void launchShip(const Ship::Type& ship);

        void launchDefense(const Defense::Type& defense);

      private:

        void create();

        const std::string generateRandomName(const unsigned& length) const noexcept;

        void initializeShips();

        void initializeDefenses();

        void initializeBuildings();

        void initializePhysicalCharacteristics();

        template<typename Data, typename EnumClass>
        const unsigned getIndexForData(const EnumClass& type, const std::vector<std::shared_ptr<Data>>& elements) const noexcept;

        template<typename Data, typename EnumClass>
        std::shared_ptr<Data> getDataOrThrow(const EnumClass& type, const std::vector<std::shared_ptr<Data>>& elements) const;

        void decreaseResourceDepositFromCost(const std::unordered_map<Resource, float>& costs);

        const float getBasicProductionForMine(const Building::Type& mine, const unsigned& universeSpeed) const noexcept;

        ResourceDeposit* getDepositOrNullFromResource(const Resource& resource);

        Ship& getShipDataPrivate(const Ship::Type& type);

        Defense& getDefenseDataPrivate(const Defense::Type& type);

        Building& getBuildingDataPrivate(const Building::Type& type);

      private:

        unsigned m_index;
        std::string m_name;
        System* m_parent;
        std::vector<ResourceDepositShPtr> m_resources;
        std::shared_ptr<Account> m_account;
        std::vector<ShipShPtr> m_ships;
        std::vector<DefenseShPtr> m_defenses;
        std::vector<BuildingShPtr> m_buildings;

        float m_diameter;
        unsigned m_fields;
        float m_minTemperature;
        float m_maxTemperature;

        std::vector<std::shared_ptr<BuildingUpgradeAction>> m_buildingUpgrades;
        std::vector<std::shared_ptr<ShipUpgradeAction>> m_shipUpgrades;
        std::vector<std::shared_ptr<DefenseUpgradeAction>> m_defenseUpgrades;
    };

    using PlanetShPtr = std::shared_ptr<Planet>;

  }
}

#include "Planet.hxx"

#endif // PLANET_H
