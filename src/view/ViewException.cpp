
#include "ViewException.h"

namespace ogame {
  namespace core {

    ViewException::ViewException(const std::string& cause):
      OgameException(cause)
    {
      //ctor
    }

    ViewException::~ViewException()
    {
      //dtor
    }

  }
}
