#ifndef PLANETEXCEPTION_H
#define PLANETEXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace core {

    class PlanetException: public OgameException
    {
      public:

        PlanetException(const std::string& cause);

        virtual ~PlanetException();

      protected:

      private:
    };

  }
}

#endif // PLANETEXCEPTION_H
