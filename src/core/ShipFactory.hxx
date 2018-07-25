#ifndef SHIPFACTORY_HXX
#define SHIPFACTORY_HXX

#include "ShipFactory.h"

namespace ogame {
  namespace core {

    inline
    ShipShPtr ShipFactory::createLightFighter() {
      return std::make_shared<Ship>(
        core::Ship::Type::LightFighter,
        constructFromResources(3000.0f, 1000.0f, 0.0f, 0.0f)
      );
    }

    inline
    ShipShPtr ShipFactory::createHeavyFighter() {
      return std::make_shared<Ship>(
        core::Ship::Type::HeavyFighter,
        constructFromResources(6000.0f, 4000.0f, 0.0f, 0.0f)
      );
    }

    inline
    ShipShPtr ShipFactory::createCruiser() {
      return std::make_shared<Ship>(
        core::Ship::Type::Cruiser,
        constructFromResources(20000.0f, 7000.0f, 2000.0f, 0.0f)
      );
    }

    inline
    ShipShPtr ShipFactory::createBattleship() {
      return std::make_shared<Ship>(
        core::Ship::Type::Battleship,
        constructFromResources(45000.0f, 15000.0f, 0.0f, 0.0f)
      );
    }

    inline
    ShipShPtr ShipFactory::createBattlecruiser() {
      return std::make_shared<Ship>(
        core::Ship::Type::Battlecruiser,
        constructFromResources(30000.0f, 40000.0f, 15000.0f, 0.0f)
      );
    }

    inline
    ShipShPtr ShipFactory::createBomber() {
      return std::make_shared<Ship>(
        core::Ship::Type::Bomber,
        constructFromResources(50000.0f, 25000.0f, 15000.0f, 0.0f)
      );
    }

    inline
    ShipShPtr ShipFactory::createDestroyer() {
      return std::make_shared<Ship>(
        core::Ship::Type::Destroyer,
        constructFromResources(60000.0f, 50000.0f, 15000.0f, 0.0f)
      );
    }

    inline
    ShipShPtr ShipFactory::createDeathstar() {
      return std::make_shared<Ship>(
        core::Ship::Type::Deathstar,
        constructFromResources(5000000.0f, 40000000.0f, 1000000.0f, 0.0f)
      );
    }

    inline
    ShipShPtr ShipFactory::createSmallCargo() {
      return std::make_shared<Ship>(
        core::Ship::Type::SmallCargo,
        constructFromResources(2000.0f, 2000.0f, 0.0f, 0.0f)
      );
    }

    inline
    ShipShPtr ShipFactory::createLargeCargo() {
      return std::make_shared<Ship>(
        core::Ship::Type::LargeCargo,
        constructFromResources(6000.0f, 6000.0f, 0.0f, 0.0f)
      );
    }

    inline
    ShipShPtr ShipFactory::createColony() {
      return std::make_shared<Ship>(
        core::Ship::Type::ColonyShip,
        constructFromResources(10000.0f, 20000.0f, 10000.0f, 0.0f)
      );
    }

    inline
    ShipShPtr ShipFactory::createRecycler() {
      return std::make_shared<Ship>(
        core::Ship::Type::Recycler,
        constructFromResources(10000.0f, 6000.0f, 2000.0f, 0.0f)
      );
    }

    inline
    ShipShPtr ShipFactory::createEspionageProbe() {
      return std::make_shared<Ship>(
        core::Ship::Type::EspionageProbe,
        constructFromResources(0.0f, 1000.0f, 0.0f, 0.0f)
      );
    }

    inline
    ShipShPtr ShipFactory::createSolarSatellite() {
      return std::make_shared<Ship>(
        core::Ship::Type::SolarSatellite,
        constructFromResources(0.0f, 2000.0f, 500.0f, 0.0f)
      );
    }

    inline
    std::unordered_map<Resource, float> ShipFactory::constructFromResources(const float& metal,
                                                                            const float& crystal,
                                                                            const float& deuterium,
                                                                            const float& energy)
    {
      std::unordered_map<Resource, float> resources;
      createResourceFromQuantityAndName(resources, std::string("metal"), metal);
      createResourceFromQuantityAndName(resources, std::string("crystal"), crystal);
      createResourceFromQuantityAndName(resources, std::string("deuterium"), deuterium);
      createResourceFromQuantityAndName(resources, std::string("energy"), energy);
      return resources;
    }

    inline
    void ShipFactory::createResourceFromQuantityAndName(std::unordered_map<Resource, float>& resources,
                                                        const std::string& name,
                                                        const float& quantity)
    {
      if (quantity > 0.001f) {
        resources[name] = quantity;
      }
    }

  }
}

#endif // SHIPFACTORY_HXX
