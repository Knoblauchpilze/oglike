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

    inline
    const std::string System::generateRandomName(const unsigned& length) const noexcept {
      std::string name;
      name.resize(length);
      unsigned index = 0u;
      while (index < length) {
        name[index] = 'a' + std::rand() % ('z' - 'a');
        ++index;
      }
      return name;
    }

  }
}

#endif // SYSTEM_HXX
