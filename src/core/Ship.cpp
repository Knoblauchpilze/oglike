
#include "Ship.h"

namespace ogame {
  namespace core {

    Ship::Ship(const Type& type,
               const std::unordered_map<Resource, float>& cost):
      FixedCostUnit(Ship::getNameFromType(type), cost),
      m_type(type)
    {
      // Nothing to do here.
    }

    Ship::~Ship() {}

  }
}
