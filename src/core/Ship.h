#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <memory>

namespace ogame {
  namespace core {

    class Ship
    {
      public:

        Ship(const std::string& name);

        virtual ~Ship();

        const std::string& getName() const;

      protected:

      private:

        std::string m_name;
    };

    using ShipShPtr = std::shared_ptr<Ship>;

  }
}

#include "Ship.hxx"

#endif // SHIP_H
