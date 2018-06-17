
#include "EventException.h"

namespace ogame {
  namespace view {

    EventException::EventException(const std::string& cause):
      OgameException(cause)
    {
      //ctor
    }

    EventException::~EventException()
    {
      //dtor
    }

  }
}
