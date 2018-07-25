
#include "UpgradableException.h"

namespace ogame {
  namespace core {

    UpgradableException::UpgradableException(const std::string& cause):
      OgameException(cause)
    {
      //ctor
    }

    UpgradableException::~UpgradableException()
    {
      //dtor
    }

  }
}
