
#include "UniverseRunnable.h"

namespace ogame {
  namespace server {

    UniverseRunnable::UniverseRunnable(core::UniverseShPtr universe):
      Runnable(),
      m_universe(universe)
    {
      // Nothing to do here.
    }

    UniverseRunnable::~UniverseRunnable() {}

  }
}
