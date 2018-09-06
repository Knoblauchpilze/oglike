#ifndef FLEETEXCEPTION_H
#define FLEETEXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace core {

    class FleetException: public OgameException
    {
      public:

        FleetException(const std::string& cause);

        virtual ~FleetException();

      protected:

      private:
    };

  }
}

#endif // FLEETEXCEPTION_H
