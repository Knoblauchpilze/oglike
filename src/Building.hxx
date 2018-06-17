#ifndef BUILDING_HXX_INCLUDED
#define BUILDING_HXX_INCLUDED

#include "Building.h"

namespace ogame {
  namespace core {

    inline
    const unsigned& Building::getLevel() const {
      return m_level;
    }

  }
}

#endif // BUILDING_HXX_INCLUDED
