#ifndef BUILDING_HXX
#define BUILDING_HXX

#include "Building.h"

namespace ogame {
  namespace core {

    inline
    const Building::Type& Building::getType() const noexcept {
      return m_type;
    }

    inline
    const std::string& Building::getName() const noexcept {
      return m_name;
    }

  }
}

#endif // BUILDING_HXX
