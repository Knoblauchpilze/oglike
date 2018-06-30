#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <string>
#include <vector>
#include <memory>

#include "Galaxy.h"

namespace ogame {
  namespace core {

    class Universe
    {
      public:

        Universe(const unsigned& index,
                 const unsigned& galaxiesCount,
                 const unsigned& systemsCount,
                 const unsigned& planetsCount);

        virtual ~Universe();

        bool operator==(const Universe& other) const;

        bool operator<(const Universe& other) const;

        const Galaxy& operator[](const unsigned& index) const;

      protected:

        void create(const unsigned& galaxiesCount,
                    const unsigned& systemsCount,
                    const unsigned& planetsCount);

      private:

        const unsigned m_index;
        std::vector<GalaxyShPtr> m_galaxies;

    };

    using UniverseShPtr = std::shared_ptr<Universe>;

  }
}

#endif // UNIVERSE_H
