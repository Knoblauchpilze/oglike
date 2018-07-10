#ifndef ACCOUNTEXCEPTION_H
#define ACCOUNTEXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace core {

    class AccountException: public OgameException
    {
      public:

        AccountException(const std::string& cause);

        virtual ~AccountException();

      protected:

      private:
    };

  }
}

#endif // ACCOUNTEXCEPTION_H
