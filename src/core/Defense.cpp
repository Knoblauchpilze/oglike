
#include "Defense.h"

namespace ogame {
  namespace core {

    Defense::Defense(const Type& type,
                     const std::unordered_map<Resource, float>& cost):
      FixedCostUnit(getNameFromType(type), cost),
      m_type(type)
    {
      // Nothing to do here.
    }

    Defense::~Defense() {}

  }
}
