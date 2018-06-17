#ifndef GALAXYEXCEPTION_H
#define GALAXYEXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace core {

    class GalaxyException: public OgameException
    {
      public:

        GalaxyException(const std::string& cause);

        virtual ~GalaxyException();

      protected:

      private:
    };

  }
}

#endif // GALAXYEXCEPTION_H
