#ifndef DEFENSEFACTORY_H
#define DEFENSEFACTORY_H

#include "Defense.h"

namespace ogame {
  namespace core {

    class DefenseFactory
    {
      public:

        DefenseFactory() = default;

        virtual ~DefenseFactory() = default;

        static
        DefenseShPtr createMissileLauncher();

        static
        DefenseShPtr createLightLaser();

        static
        DefenseShPtr createHeavyLaser();

        static
        DefenseShPtr createGaussCannon();

        static
        DefenseShPtr createIonCannon();

        static
        DefenseShPtr createPlasmaTurret();

        static
        DefenseShPtr createSmallShieldDome();

        static
        DefenseShPtr createLargeShieldDome();

        static
        DefenseShPtr createAntiballisticMissile();

        static
        DefenseShPtr createInterplanetaryMissile();

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

#include "DefenseFactory.hxx"

#endif // DEFENSEFACTORY_H
