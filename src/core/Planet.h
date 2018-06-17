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

      protected:

        void create();

      private:

        std::string m_name;
        std::vector<ResourceDepositShPtr> m_resources;
    };

    using PlanetShPtr = std::shared_ptr<Planet>;

  }
}

#endif // PLANET_H
