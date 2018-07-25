
#include "Research.h"

namespace ogame {
  namespace core {

    Research::Research(const Type& type,
                       const std::unordered_map<Resource, float>& initResources):
      AbstractUpgradable(0u, initResources, (type == Type::Astrophysics ? 1.75f : 2.0f)),
      m_type(type),
      m_name(getNameFromType(m_type))
    {
      // Nothing to do here.
    }

    Research::~Research() {}

  }
}
