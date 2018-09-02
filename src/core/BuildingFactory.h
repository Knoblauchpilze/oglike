#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Building.h"
#include "PowerPlant.h"
#include "ResourceMine.h"
#include "ResourceStorage.h"

namespace ogame {
  namespace core {

    class BuildingFactory
    {
      public:

        BuildingFactory() = default;

        virtual ~BuildingFactory() = default;

        static
        ResourceMineShPtr createMetalMine();

        static
        ResourceMineShPtr createCrystalMine();

        static
        ResourceMineShPtr createDeuteriumMine();

        static
        ResourceStorageShPtr createMetalStorage();

        static
        ResourceStorageShPtr createCrystalStorage();

        static
        ResourceStorageShPtr createDeuteriumStorage();

        static
        PowerPlantShPtr createSolarPlant();

        static
        PowerPlantShPtr createFusionPlant();

        static
        BuildingShPtr createRoboticsFactory();

        static
        BuildingShPtr createNaniteFactory();

        static
        BuildingShPtr createResearchLab();

        static
        BuildingShPtr createShipyard();

        static
        BuildingShPtr createSpaceDock();

        static
        BuildingShPtr createMissileSilo();

        static
        BuildingShPtr createAllianceDepot();

        static
        BuildingShPtr createTerraformer();

        static
        const Building::Type getMineTypeFromResource(const std::string& resource);

      private:

        static
        std::unordered_map<Resource, float> constructFromResources(const float& metal,
                                                                   const float& crystal,
                                                                   const float& deuterium,
                                                                   const float& energy);

        static
        void createResourceFromQuantityAndName(std::unordered_map<Resource, float>& resources,
                                               const std::string& name,
                                               const float& quantity);
    };

  }
}

#include "BuildingFactory.hxx"

#endif // BUILDINGFACTORY_H
