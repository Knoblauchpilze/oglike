#ifndef UNIVERSERUNNABLE_H
#define UNIVERSERUNNABLE_H

#include <memory>
#include "Runnable.h"
#include "Universe.h"

namespace ogame {
  namespace server {

    class UniverseRunnable: public Runnable
    {
      public:

        UniverseRunnable(core::UniverseShPtr universe);

        virtual ~UniverseRunnable();

        void simulate(const time::TimeManager& manager) override;

      private:

        void updateResourcesForUniverse(const float& hoursDuration);

        void updateResourcesForPlanet(core::Planet& planet, const float& hoursDuration);

      private:

        core::UniverseShPtr m_universe;

    };

    using UniverseRunnableShPtr = std::shared_ptr<UniverseRunnable>;
  }
}

#include "UniverseRunnable.hxx"

#endif // UNIVERSERUNNABLE_H