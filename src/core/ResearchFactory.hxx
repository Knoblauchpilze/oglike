#ifndef RESEARCHFACTORY_HXX
#define RESEARCHFACTORY_HXX

#include "ResearchFactory.h"

namespace ogame {
  namespace core {

    inline
    ResearchShPtr ResearchFactory::createEnergyResearch() {
      return std::make_shared<Research>(
        core::Research::Type::Energy,
        constructFromResources(0.0f, 800.0f, 400.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createLaserResearch() {
      return std::make_shared<Research>(
        core::Research::Type::Laser,
        constructFromResources(200.0f, 100.0f, 0.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createIonsResearch() {
      return std::make_shared<Research>(
        core::Research::Type::Ion,
        constructFromResources(1000.0f, 300.0f, 100.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createHyperspaceResearch() {
      return std::make_shared<Research>(
        core::Research::Type::Hyperspace,
        constructFromResources(0.0f, 4000.0f, 2000.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createPlasmaResearch() {
      return std::make_shared<Research>(
        core::Research::Type::Plasma,
        constructFromResources(2000.0f, 4000.0f, 1000.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createCombustionDriveResearch() {
      return std::make_shared<Research>(
        core::Research::Type::CombustionDrive,
        constructFromResources(400.0f, 0.0f, 600.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createImpulseDriveResearch() {
      return std::make_shared<Research>(
        core::Research::Type::ImpulseDrive,
        constructFromResources(2000.0f, 4000.0f, 600.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createHyperspaceDriveResearch() {
      return std::make_shared<Research>(
        core::Research::Type::HyperspaceDrive,
        constructFromResources(10000.0f, 20000.0f, 6000.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createEspionageResearch() {
      return std::make_shared<Research>(
        core::Research::Type::Espionage,
        constructFromResources(2000.0f, 1000.0f, 200.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createComputerResearch() {
      return std::make_shared<Research>(
        core::Research::Type::Computer,
        constructFromResources(0.0f, 400.0f, 600.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createAstrophysicsResearch() {
      return std::make_shared<Research>(
        core::Research::Type::Astrophysics,
        constructFromResources(4000.0f, 8000.0f, 4000.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createIRNResearch() {
      return std::make_shared<Research>(
        core::Research::Type::IRN,
        constructFromResources(240000.0f, 400000.0f, 160000.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createGravitonResearch() {
      return std::make_shared<Research>(
        core::Research::Type::Graviton,
        constructFromResources(0.0f, 0.0f, 0.0f, 300000.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createWeaponResearch() {
      return std::make_shared<Research>(
        core::Research::Type::Weapon,
        constructFromResources(800.0f, 200.0f, 0.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createShieldingResearch() {
      return std::make_shared<Research>(
        core::Research::Type::Shielding,
        constructFromResources(200.0f, 600.0f, 0.0f, 0.0f)
      );
    }

    inline
    ResearchShPtr ResearchFactory::createArmourResearch() {
      return std::make_shared<Research>(
        core::Research::Type::Armour,
        constructFromResources(1000.0f, 0.0f, 0.0f, 0.0f)
      );
    }

    inline
    std::unordered_map<Resource, float> ResearchFactory::constructFromResources(const float& metal,
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
    void ResearchFactory::createResourceFromQuantityAndName(std::unordered_map<Resource, float>& resources,
                                                            const std::string& name,
                                                            const float& quantity)
    {
      if (quantity > 0.001f) {
        resources[name] = quantity;
      }
    }

  }
}

#endif // RESEARCHFACTORY_H
