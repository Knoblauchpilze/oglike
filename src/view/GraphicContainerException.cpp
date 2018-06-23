
#include "GraphicContainerException.h"

namespace ogame {
  namespace view {

    GraphicContainerException::GraphicContainerException(const std::string& cause):
      ViewException(cause)
    {
      //ctor
    }

    GraphicContainerException::~GraphicContainerException()
    {
      //dtor
    }

  }
}
