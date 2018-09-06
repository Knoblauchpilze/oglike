#ifndef FLEET_H
#define FLEET_H

#include <string>
#include <memory>
#include "Planet.h"

namespace ogame {
  namespace core {

    class Planet;

    class Fleet
    {
      public:

        Fleet(const std::string& name,
              const Planet* origin,
              const Planet* target);

        virtual ~Fleet();

        const std::string& getName() const noexcept;

        const Planet& getOrigin() const;

        const Planet& getTarget() const;

      private:

        std::string m_name;
        const Planet* m_originPlanet;
        const Planet* m_targetPlanet;
    };

    using FleetShPtr = std::shared_ptr<Fleet>;

  }
}

#include "Fleet.hxx"

#endif // FLEET_H
