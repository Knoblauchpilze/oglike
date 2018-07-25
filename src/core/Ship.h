#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <memory>
#include "FixedCostUnit.h"

namespace ogame {
  namespace core {

    class Ship: public FixedCostUnit
    {
      public:

        // Convenience define for the type of a ship.
        enum class Type {
          LightFighter,
          HeavyFighter,
          Cruiser,
          Battleship,
          Battlecruiser,
          Bomber,
          Destroyer,
          Deathstar,
          SmallCargo,
          LargeCargo,
          ColonyShip,
          Recycler,
          EspionageProbe,
          SolarSatellite
        };

        Ship(const Type& type,
             const std::unordered_map<Resource, float>& cost);

        virtual ~Ship();

        const Type& getType() const noexcept;

        const unsigned getCount() const noexcept;

      private:

        const std::string getNameFromType(const Type& type) const noexcept;

      private:

        Type m_type;
    };

    using ShipShPtr = std::shared_ptr<Ship>;

  }
}

#include "Ship.hxx"

#endif // SHIP_H
