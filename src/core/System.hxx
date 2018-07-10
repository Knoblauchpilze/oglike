#ifndef SYSTEM_HXX
#define SYSTEM_HXX

#include "System.h"

namespace ogame {
  namespace core {

    inline
    const unsigned& System::getIndex() const noexcept {
      return m_index;
    }

    inline
    const unsigned System::getPlanetsCount() const noexcept {
      return m_planets.size();
    }

  }
}

#endif // SYSTEM_HXX
