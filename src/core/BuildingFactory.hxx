#ifndef BUILDINGFACTORY_HXX
#define BUILDINGFACTORY_HXX

#include "BuildingFactory.h"

namespace ogame {
  namespace core {

    inline
    ResourceMineShPtr BuildingFactory::createMetalMine() {
      return std::make_shared<ResourceMine>(
        Resource(std::string("metal")),
        constructFromResources(60.0f, 15.0f, 0.0f, 0.0f)
      );
    }

    inline
    ResourceMineShPtr BuildingFactory::createCrystalMine() {
      return std::make_shared<ResourceMine>(
        Resource(std::string("crystal")),
        constructFromResources(48.0f, 24.0f, 0.0f, 0.0f)
      );
    }

    inline
    ResourceMineShPtr BuildingFactory::createDeuteriumMine() {
      return std::make_shared<ResourceMine>(
        Resource(std::string("deuterium")),
        constructFromResources(225.0f, 75.0f, 0.0f, 0.0f)
      );
    }

    inline
    ResourceStorageShPtr BuildingFactory::createMetalStorage() {
      return std::make_shared<ResourceStorage>(
        Resource(std::string("metal")),
        10000.0f,
        constructFromResources(1000.0f, 0.0f, 0.0f, 0.0f)
      );
    }

    inline
    ResourceStorageShPtr BuildingFactory::createCrystalStorage() {
      return std::make_shared<ResourceStorage>(
        Resource(std::string("crystal")),
        10000.0f,
        constructFromResources(1000.0f, 500.0f, 0.0f, 0.0f)
      );
    }

    inline
    ResourceStorageShPtr BuildingFactory::createDeuteriumStorage() {
      return std::make_shared<ResourceStorage>(
        Resource(std::string("deuterium")),
        10000.0f,
        constructFromResources(1000.0f, 1000.0f, 0.0f, 0.0f)
      );
    }

    inline
    BuildingShPtr BuildingFactory::createSolarPlant() {
      return std::make_shared<Building>(
        Building::Type::SolarPlant,
        std::string("Solar plant"),
        constructFromResources(75.0f, 30.0f, 0.0f, 0.0f),
        1.5f
      );
    }

    inline
    BuildingShPtr BuildingFactory::createFusionPlant() {
      return std::make_shared<Building>(
        Building::Type::FusionPlant,
        std::string("Fusion plant"),
        constructFromResources(900.0f, 360.0f, 180.0f, 0.0f),
        1.8f
      );
    }

    inline
    BuildingShPtr BuildingFactory::createRoboticsFactory() {
      return std::make_shared<Building>(
        Building::Type::RoboticsFactory,
        std::string("Robotics factory"),
        constructFromResources(400.0f, 120.0f, 200.0f, 0.0f),
        2.0f
      );
    }

    inline
    BuildingShPtr BuildingFactory::createNaniteFactory() {
      return std::make_shared<Building>(
        Building::Type::NaniteFactory,
        std::string("Nanite factory"),
        constructFromResources(1000000.0f, 500000.0f, 100000.0f, 0.0f),
        2.0f
      );
    }

    inline
    BuildingShPtr BuildingFactory::createResearchLab() {
      return std::make_shared<Building>(
        Building::Type::ResearchLab,
        std::string("Research laboratory"),
        constructFromResources(200.0f, 400.0f, 200.0f, 0.0f),
        2.0f
      );
    }

    inline
    BuildingShPtr BuildingFactory::createShipyard() {
      return std::make_shared<Building>(
        Building::Type::Shipyard,
        std::string("Shipyard"),
        constructFromResources(400.0f, 200.0f, 100.0f, 0.0f),
        2.0f
      );
    }

    inline
    BuildingShPtr BuildingFactory::createSpaceDock() {
      return std::make_shared<Building>(
        Building::Type::SpaceDock,
        std::string("Space dock"),
        constructFromResources(200.0f, 400.0f, 200.0f, 0.0f),
        2.0f
      );
    }

    inline
    BuildingShPtr BuildingFactory::createMissileSilo() {
      return std::make_shared<Building>(
        Building::Type::MissileSilo,
        std::string("Missile silo"),
        constructFromResources(20000.0f, 20000.0f, 1000.0f, 0.0f),
        2.0f
      );
    }

    inline
    BuildingShPtr BuildingFactory::createAllianceDepot() {
      return std::make_shared<Building>(
        Building::Type::AllianceDepot,
        std::string("Alliance depot"),
        constructFromResources(20000.0f, 40000.0f, 0.0f, 0.0f),
        2.0f
      );
    }

    inline
    BuildingShPtr BuildingFactory::createTerraformer() {
      return std::make_shared<Building>(
        Building::Type::Terraformer,
        std::string("Terraformer"),
        constructFromResources(0.0f, 50000.0f, 100000.0f, 0.0f),
        2.0f
      );
    }

    inline
    std::unordered_map<Resource, float> BuildingFactory::constructFromResources(const float& metal,
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
    void BuildingFactory::createResourceFromQuantityAndName(std::unordered_map<Resource, float>& resources,
                                                            const std::string& name,
                                                            const float& quantity)
    {
      if (quantity > 0.001f) {
        resources[name] = quantity;
      }
    }
    
  }
}

#endif // BUILDINGFACTORY_HXX
