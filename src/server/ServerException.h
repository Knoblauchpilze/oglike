#ifndef SERVEREXCEPTION_H
#define SERVEREXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace server {

    class ServerException: public ogame::core::OgameException
    {
      public:

        ServerException(const std::string& cause);

        virtual ~ServerException();

      protected:

      private:
    };

  }
}

#endif // SERVEREXCEPTION_H