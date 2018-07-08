
#include "FontException.h"

namespace ogame {
  namespace view {

    FontException::FontException(const std::string& cause):
      ViewException(cause)
    {
      //ctor
    }

    FontException::~FontException()
    {
      //dtor
    }

  }
}
