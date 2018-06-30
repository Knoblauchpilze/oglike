
#include "GuiException.h"

namespace ogame {
  namespace gui {

    GuiException::GuiException(const std::string& cause):
      ViewException(cause)
    {
      //ctor
    }

    GuiException::~GuiException()
    {
      //dtor
    }

  }
}
