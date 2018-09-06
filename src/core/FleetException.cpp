
#include "FleetException.h"

namespace ogame {
  namespace core {

    FleetException::FleetException(const std::string& cause):
      OgameException(cause)
    {
      //ctor
    }

    FleetException::~FleetException()
    {
      //dtor
    }

  }
}
