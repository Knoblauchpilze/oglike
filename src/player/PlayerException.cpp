
#include "PlayerException.h"

namespace ogame {
  namespace player {

    PlayerException::PlayerException(const std::string& cause):
      core::OgameException(cause)
    {
      //ctor
    }

    PlayerException::~PlayerException()
    {
      //dtor
    }

  }
}
