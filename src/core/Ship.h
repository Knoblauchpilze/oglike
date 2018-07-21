#ifndef SHIP_H
#define SHIP_H

#include <string>

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

  }
}

#include "Ship.hxx"

#endif // SHIP_H
