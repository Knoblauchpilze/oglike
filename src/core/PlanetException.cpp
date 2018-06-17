
#include "PlanetException.h"

namespace ogame {
  namespace core {

    PlanetException::PlanetException(const std::string& cause):
      OgameException(cause)
    {
      //ctor
    }

    PlanetException::~PlanetException()
    {
      //dtor
    }

  }
}
