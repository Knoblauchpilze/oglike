
#include "BuildingException.h"

namespace ogame {
  namespace core {

    BuildingException::BuildingException(const std::string& cause):
      OgameException(cause)
    {
      //ctor
    }

    BuildingException::~BuildingException()
    {
      //dtor
    }

  }
}
