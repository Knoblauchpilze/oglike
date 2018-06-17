
#include "UniverseException.h"

namespace ogame {
  namespace core {

    UniverseException::UniverseException(const std::string& cause):
      OgameException(cause)
    {
      //ctor
    }

    UniverseException::~UniverseException()
    {
      //dtor
    }

  }
}
