
#include "ViewException.h"

namespace ogame {
  namespace view {

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
