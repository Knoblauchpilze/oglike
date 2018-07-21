#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <memory>

namespace ogame {
  namespace core {

    class Ship
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

        Ship(const Type& type);

        virtual ~Ship();

        const Type& getType() const noexcept;

        const std::string& getName() const noexcept;

        const unsigned getCount() const noexcept;

      private:

        const std::string getNameFromType(const Type& type) const noexcept;

      private:

        Type m_type;
        std::string m_name;
    };

    using ShipShPtr = std::shared_ptr<Ship>;

  }
}

#include "Ship.hxx"

#endif // SHIP_H
