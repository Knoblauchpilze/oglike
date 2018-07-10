#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <string>
#include <memory>

#include "Planet.h"

namespace ogame {
  namespace core {

    class Galaxy;
    class Planet;

    class System
    {
      public:

        System(const unsigned& index, const unsigned& planetsCount, Galaxy* galaxy);

        virtual ~System();

        const Planet& operator[](const unsigned& index) const;

        Planet& operator[](const unsigned& index);

        const unsigned& getIndex() const noexcept;

        const unsigned getPlanetsCount() const noexcept;

        const unsigned& getGalaxyIndex() const;

        const int getPositionOf(const Planet& planet) const;

        const bool findPosition(unsigned& position,
                                const unsigned& minStartingPosition,
                                const unsigned& maxStartingPosition) const;

      protected:

        void create(const unsigned& planetsCount);

      private:

        const unsigned m_index;
        Galaxy* m_parent;
        std::vector<PlanetShPtr> m_planets;


    };

    using SystemShPtr = std::shared_ptr<System>;

  }
}

#include "System.hxx"

#endif // SYSTEM_H
