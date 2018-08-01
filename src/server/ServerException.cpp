
#include "ServerException.h"

namespace ogame {
  namespace server {

    ServerException::ServerException(const std::string& cause):
      OgameException(cause)
    {
      //ctor
    }

    ServerException::~ServerException()
    {
      //dtor
    }

  }
}
