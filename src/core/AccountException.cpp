
#include "AccountException.h"

namespace ogame {
  namespace core {

    AccountException::AccountException(const std::string& cause):
      OgameException(cause)
    {
      //ctor
    }

    AccountException::~AccountException()
    {
      //dtor
    }

  }
}
