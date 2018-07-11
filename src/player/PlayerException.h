#ifndef PLAYEREXCEPTION_H
#define PLAYEREXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace player {

    class PlayerException: public core::OgameException
    {
      public:

        PlayerException(const std::string& cause);

        virtual ~PlayerException();

      protected:

      private:
    };

  }
}

#endif // PLAYEREXCEPTION_H
