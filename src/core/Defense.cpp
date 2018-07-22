
#include "Defense.h"

namespace ogame {
  namespace core {

    Defense::Defense(const Type& type):
      m_type(type),
      m_name(getNameFromType(m_type))
    {
      // Nothing to do here.
    }

    Defense::~Defense() {}

  }
}
