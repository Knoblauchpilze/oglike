#ifndef DEFENSEFACTORY_HXX
#define DEFENSEFACTORY_HXX

#include "DefenseFactory.h"

namespace ogame {
  namespace core {

    inline
    DefenseShPtr DefenseFactory::createMissileLauncher() {
      return std::make_shared<Defense>(
        core::Defense::Type::MissileLauncher,
        constructFromResources(2000.0f, 0.0f, 0.0f, 0.0f)
      );
    }

    inline
    DefenseShPtr DefenseFactory::createLightLaser() {
      return std::make_shared<Defense>(
        core::Defense::Type::LightLaser,
        constructFromResources(1500.0f, 500.0f, 0.0f, 0.0f)
      );
    }

    inline
    DefenseShPtr DefenseFactory::createHeavyLaser() {
      return std::make_shared<Defense>(
        core::Defense::Type::HeavyLaser,
        constructFromResources(6000.0f, 2000.0f, 0.0f, 0.0f)
      );
    }

    inline
    DefenseShPtr DefenseFactory::createGaussCannon() {
      return std::make_shared<Defense>(
        core::Defense::Type::GaussCannon,
        constructFromResources(20000.0f, 15000.0f, 2000.0f, 0.0f)
      );
    }

    inline
    DefenseShPtr DefenseFactory::createIonCannon() {
      return std::make_shared<Defense>(
        core::Defense::Type::IonCannon,
        constructFromResources(2000.0f, 6000.0f, 0.0f, 0.0f)
      );
    }

    inline
    DefenseShPtr DefenseFactory::createPlasmaTurret() {
      return std::make_shared<Defense>(
        core::Defense::Type::PlasmaTurret,
        constructFromResources(50000.0f, 50000.0f, 30000.0f, 0.0f)
      );
    }

    inline
    DefenseShPtr DefenseFactory::createSmallShieldDome() {
      return std::make_shared<Defense>(
        core::Defense::Type::SmallShieldDome,
        constructFromResources(10000.0f, 10000.0f, 0.0f, 0.0f)
      );
    }

    inline
    DefenseShPtr DefenseFactory::createLargeShieldDome() {
      return std::make_shared<Defense>(
        core::Defense::Type::LargeShieldDome,
        constructFromResources(50000.0f, 50000.0f, 0.0f, 0.0f)
      );
    }

    inline
    DefenseShPtr DefenseFactory::createAntiballisticMissile() {
      return std::make_shared<Defense>(
        core::Defense::Type::AntiballisticMissile,
        constructFromResources(8000.0f, 0.0f, 2000.0f, 0.0f)
      );
    }

    inline
    DefenseShPtr DefenseFactory::createInterplanetaryMissile() {
      return std::make_shared<Defense>(
        core::Defense::Type::InterplanetaryMissile,
        constructFromResources(12500.0f, 2500.0f, 10000.0f, 0.0f)
      );
    }

    inline
    std::unordered_map<Resource, float> DefenseFactory::constructFromResources(const float& metal,
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
    void DefenseFactory::createResourceFromQuantityAndName(std::unordered_map<Resource, float>& resources,
                                                           const std::string& name,
                                                           const float& quantity)
    {
      if (quantity > 0.001f) {
        resources[name] = quantity;
      }
    }

  }
}

#include "DefenseFactory.hxx"

#endif // DEFENSEFACTORY_HXX
