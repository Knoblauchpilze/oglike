#ifndef GALAXY_HXX
#define GALAXY_HXX

#include <vector>
#include <memory>

#include "System.h"

namespace ogame {
  namespace core {

    inline
    const unsigned& Galaxy::getIndex() const noexcept {
      return m_index;
    }

  }
}

#endif // GALAXY_HXX
