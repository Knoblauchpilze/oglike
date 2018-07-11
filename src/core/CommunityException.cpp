
#include "CommunityException.h"

namespace ogame {
  namespace core {

    CommunityException::CommunityException(const std::string& cause):
      OgameException(cause)
    {
      //ctor
    }

    CommunityException::~CommunityException()
    {
      //dtor
    }

  }
}
