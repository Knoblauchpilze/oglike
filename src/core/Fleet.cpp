
#include "Fleet.h"

namespace ogame {
  namespace core {

    Fleet::Fleet(const std::string& name,
                 const Planet* origin,
                 const Planet* target):
      m_name(name),
      m_originPlanet(origin),
      m_targetPlanet(target)
    {
      // Nothing to do here.
    }

    Fleet::~Fleet() {}

  }
}
