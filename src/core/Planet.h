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

namespace ogame {
  namespace core {

    class System;
    class Account;

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

        const System& getSystem() const;

        const float& getDiameter() const noexcept;

        const float& getMinTemperature() const noexcept;

        const float& getMaxTemperature() const noexcept;

        const std::string getCoordinates() const;

        const unsigned getShipCount(const Ship::Type& type) const;

        const Ship& getShipData(const Ship::Type& type) const;

        const unsigned getDefenseCount(const Defense::Type& type) const;

        const Defense& getDefenseData(const Defense::Type& type) const;

        const unsigned getBuildingLevel(const Building::Type& type) const;

        const Building& getBuildingData(const Building::Type& type) const;

        const std::vector<ResourceDepositShPtr>& getResourceDeposits() const noexcept;

        void createUpgradeAction(const Building::Type& type);

        void createUpgradeAction(const Ship::Type& type);

        void createUpgradeAction(const Defense::Type& type);

      private:

        void create();

        const std::string generateRandomName(const unsigned& length) const noexcept;

        void initializeShips();

        void initializeDefenses();

        void initializeBuildings();

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
        float m_minTemperature;
        float m_maxTemperature;
    };

    using PlanetShPtr = std::shared_ptr<Planet>;

  }
}

#include "Planet.hxx"

#endif // PLANET_H
