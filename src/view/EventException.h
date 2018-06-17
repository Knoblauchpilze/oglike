#ifndef EVENTEXCEPTION_H
#define EVENTEXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace view {

    class EventException: public ogame::core::OgameException
    {
      public:

        EventException(const std::string& cause);

        virtual ~EventException();

      protected:

      private:
    };

  }
}

#endif // EVENTEXCEPTION_H