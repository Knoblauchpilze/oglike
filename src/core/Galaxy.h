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

        Galaxy(const unsigned& index, const unsigned& systemsCount);

        virtual ~Galaxy();

        const System& operator[](const unsigned& index) const;

      protected:

        void create(const unsigned& systemsCount);

      private:

        unsigned m_index;
        std::vector<SystemShPtr> m_systems;
    };

    using GalaxyShPtr = std::shared_ptr<Galaxy>;

  }
}

#endif // GALAXY_H
