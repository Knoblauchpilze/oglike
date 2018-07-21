
#include "Ship.h"

namespace ogame {
  namespace core {

    Ship::Ship(const Type& type):
      m_type(type),
      m_name(getNameFromType(m_type))
    {
      // Nothing to do here.
    }

    Ship::~Ship() {}

  }
}
