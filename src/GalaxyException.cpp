
#include "GalaxyException.h"

namespace ogame {
  namespace core {

    GalaxyException::GalaxyException(const std::string& cause):
      OgameException(cause)
    {
      //ctor
    }

    GalaxyException::~GalaxyException()
    {
      //dtor
    }

  }
}
