#ifndef SHIPFACTORY_H
#define SHIPFACTORY_H

#include "Ship.h"

namespace ogame {
  namespace core {

    class ShipFactory
    {
      public:

        ShipFactory() = default;

        virtual ~ShipFactory() = default;

        static
        ShipShPtr createLightFighter();

        static
        ShipShPtr createHeavyFighter();

        static
        ShipShPtr createCruiser();

        static
        ShipShPtr createBattleship();

        static
        ShipShPtr createBattlecruiser();

        static
        ShipShPtr createBomber();

        static
        ShipShPtr createDestroyer();

        static
        ShipShPtr createDeathstar();

        static
        ShipShPtr createSmallCargo();

        static
        ShipShPtr createLargeCargo();

        static
        ShipShPtr createColony();

        static
        ShipShPtr createRecycler();

        static
        ShipShPtr createEspionageProbe();

        static
        ShipShPtr createSolarSatellite();

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

#include "ShipFactory.hxx"

#endif // SHIPFACTORY_H
