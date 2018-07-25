#ifndef RESEARCHFACTORY_H
#define RESEARCHFACTORY_H

#include "Research.h"

namespace ogame {
  namespace core {

    class ResearchFactory
    {
      public:

        ResearchFactory() = default;

        virtual ~ResearchFactory() = default;

        static
        ResearchShPtr createEnergyResearch();

        static
        ResearchShPtr createLaserResearch();

        static
        ResearchShPtr createIonsResearch();

        static
        ResearchShPtr createHyperspaceResearch();

        static
        ResearchShPtr createPlasmaResearch();

        static
        ResearchShPtr createCombustionDriveResearch();

        static
        ResearchShPtr createImpulseDriveResearch();

        static
        ResearchShPtr createHyperspaceDriveResearch();

        static
        ResearchShPtr createEspionageResearch();

        static
        ResearchShPtr createComputerResearch();

        static
        ResearchShPtr createAstrophysicsResearch();

        static
        ResearchShPtr createIRNResearch();

        static
        ResearchShPtr createGravitonResearch();

        static
        ResearchShPtr createWeaponResearch();

        static
        ResearchShPtr createShieldingResearch();

        static
        ResearchShPtr createArmourResearch();

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

#include "ResearchFactory.hxx"

#endif // RESEARCHFACTORY_H
