#ifndef SHIP_HXX
#define SHIP_HXX

#include "Ship.h"

namespace ogame {
  namespace core {

    inline
    const std::string& Ship::getName() const {
      return m_name;
    }

  }
}

#endif // SHIP_HXX
