#ifndef UNIVERSEEXCEPTION_H
#define UNIVERSEEXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace core {

    class UniverseException: public OgameException
    {
      public:

        UniverseException(const std::string& cause);

        virtual ~UniverseException();

      protected:

      private:
    };

  }
}

#endif // UNIVERSEEXCEPTION_H
