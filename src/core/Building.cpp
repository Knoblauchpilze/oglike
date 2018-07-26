
#include "Building.h"

namespace ogame {
  namespace core {

    Building::Building(const Type& type,
                       const std::string& name,
                       const std::unordered_map<Resource, float>& initResources,
                       const float& factor):
      AbstractUpgradable(0u, initResources, factor),
      m_type(type),
      m_name(name)
    {
      // Nothing to do here.
    }

    Building::~Building() {}

  }
}
