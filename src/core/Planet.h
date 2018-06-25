#ifndef PLANET_H
#define PLANET_H

#include <memory>
#include <string>
#include <vector>

#include "ResourceDeposit.h"

namespace ogame {
  namespace core {

    class Planet
    {
      public:

        Planet(const std::string& name);

        virtual ~Planet();

        const std::string& getName() const noexcept;

        const bool hasMoon() const noexcept;

        const bool hasWreckfield() const noexcept;

      protected:

        void create();

      private:

        std::string m_name;
        std::vector<ResourceDepositShPtr> m_resources;
    };

    using PlanetShPtr = std::shared_ptr<Planet>;

  }
}

#include "Planet.hxx"

#endif // PLANET_H
