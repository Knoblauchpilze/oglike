
#include "SystemCoordinates.h"

namespace ogame {
  namespace core {

    SystemCoordinates::SystemCoordinates(const unsigned& galaxy, const unsigned system):
      m_galaxy(galaxy),
      m_system(system)
    {
      // Nothing to do here.
    }

    SystemCoordinates::~SystemCoordinates() {}

  }
}
