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

        static
        std::string getNameFromType(const Type& type) noexcept;

        static
        Type getTypeFromName(const std::string& name) noexcept;

        static
        std::string getPictureNameFromShip(const core::Ship::Type& type, const bool reduced = true) noexcept;

      private:

        Type m_type;
    };

    using ShipShPtr = std::shared_ptr<Ship>;

  }
}

#include "Ship.hxx"

#endif // SHIP_H
