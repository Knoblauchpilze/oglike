
#include "Building.h"

namespace ogame {
  namespace core {

    Building::Building(const Type& type, const std::string& name):
      Upgradable(0u),
      m_type(type),
      m_name(name)
    {
      // Nothing to do here.
    }

    Building::~Building() {}

    void Building::upgrade(const std::vector<ResourceDepositShPtr>& resources) {}

  }
}
