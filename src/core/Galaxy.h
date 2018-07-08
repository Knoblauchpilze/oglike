#ifndef GALAXY_H
#define GALAXY_H

#include <vector>
#include <memory>

#include "System.h"

namespace ogame {
  namespace core {

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

      protected:

        void create(const unsigned& systemsCount,
                    const unsigned& planetsCount);

      private:

        unsigned m_index;
        std::vector<SystemShPtr> m_systems;
    };

    using GalaxyShPtr = std::shared_ptr<Galaxy>;

  }
}

#include "Galaxy.hxx"

#endif // GALAXY_H
