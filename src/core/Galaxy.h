#ifndef GALAXY_H
#define GALAXY_H

#include <vector>
#include <memory>

#include "System.h"

namespace ogame {
  namespace core {

    class System;

    class Galaxy
    {
      public:

        Galaxy(const unsigned& index,
               const unsigned& systemsCount,
               const unsigned& planetsCount,
               const bool instantiate = true);

        virtual ~Galaxy();

        const unsigned& getIndex() const noexcept;

        const System& operator[](const unsigned& index) const;

        System& operator[](const unsigned& index);

        const bool findPosition(unsigned& system,
                                unsigned& position,
                                const unsigned& minStartingPosition,
                                const unsigned& maxStartingPosition) const;

      protected:

        void create(const unsigned& systemsCount,
                    const unsigned& planetsCount);

      private:

        unsigned m_index;
        std::vector<std::shared_ptr<System>> m_systems;
    };

    using GalaxyShPtr = std::shared_ptr<Galaxy>;

  }
}

#include "Galaxy.hxx"

#endif // GALAXY_H
