#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <string>
#include <memory>

#include "Planet.h"

namespace ogame {
  namespace core {

    class System
    {
      public:

        System(const unsigned& index, const unsigned& planetsCount);

        virtual ~System();

        const Planet& operator[](const unsigned& index) const;

      protected:

        void create(const unsigned& planetsCount);

      private:

        const unsigned m_index;
        std::vector<PlanetShPtr> m_planets;


    };

    using SystemShPtr = std::shared_ptr<System>;

  }
}

#endif // SYSTEM_H
