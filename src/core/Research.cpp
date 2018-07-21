
#include "Research.h"

namespace ogame {
  namespace core {

    Research::Research(const Type& type):
      m_type(type),
      m_name(getNameFromType(m_type))
    {
      // Nothing to do here.
    }

    Research::~Research() {}

  }
}
