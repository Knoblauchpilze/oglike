#ifndef UNIVERSERUNNABLE_HXX
#define UNIVERSERUNNABLE_HXX

#include "UniverseRunnable.h"
#include "ServerException.h"

namespace ogame {
  namespace server {

    inline
    void UniverseRunnable::simulate(const time::TimeManager& manager) {
      const float lastStepDuration = manager.getLastStepDuration(time::Unit::Hour);
      updatePlanetsForUniverse(lastStepDuration);
      updateAccountsForUniverse();
    }

  }
}

#endif // UNIVERSERUNNABLE_HXX