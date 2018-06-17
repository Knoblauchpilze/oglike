#ifndef SYSTEMEXCEPTION_H
#define SYSTEMEXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace core {

    class SystemException: public OgameException
    {
      public:

        SystemException(const std::string& cause);

        virtual ~SystemException();

      protected:

      private:
    };

  }
}

#endif // SYSTEMEXCEPTION_H
