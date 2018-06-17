
#include "SystemException.h"

namespace ogame {
  namespace core {

    SystemException::SystemException(const std::string& cause):
      OgameException(cause)
    {
      //ctor
    }

    SystemException::~SystemException()
    {
      //dtor
    }

  }
}
