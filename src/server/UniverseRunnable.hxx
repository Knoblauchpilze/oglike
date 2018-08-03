#ifndef UNIVERSERUNNABLE_HXX
#define UNIVERSERUNNABLE_HXX

#include "UniverseRunnable.h"
#include "ServerException.h"

namespace ogame {
  namespace server {

    inline
    void UniverseRunnable::simulate(const time::TimeManager& manager) {
      // Retrieve the time delta since last frame.
      const float lastStepDuration = manager.getLastStepDuration(time::Unit::Hour);

      // Updated resources for each planet.
      updateResourcesForUniverse(lastStepDuration);
    }

  }
}

#endif // UNIVERSERUNNABLE_HXX