#ifndef GALAXY_HXX
#define GALAXY_HXX

#include <vector>
#include <memory>

#include "System.h"

namespace ogame {
  namespace core {

    inline
    bool Galaxy::operator==(const Galaxy& other) const noexcept {
      return other.m_index == m_index;
    }

    inline
    const unsigned& Galaxy::getIndex() const noexcept {
      return m_index;
    }

    inline
    const unsigned Galaxy::getSystemsCount() const noexcept {
      return m_systems.size();
    }

  }
}

#endif // GALAXY_HXX
