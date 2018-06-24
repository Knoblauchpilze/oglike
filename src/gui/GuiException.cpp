
#include "GuiException.h"

namespace ogame {
  namespace gui {

    GuiException::GuiException(const std::string& cause):
      OgameException(cause)
    {
      //ctor
    }

    GuiException::~GuiException()
    {
      //dtor
    }

  }
}
