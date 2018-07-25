#ifndef BUILDINGEXCEPTION_H
#define BUILDINGEXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace core {

    class BuildingException: public OgameException
    {
      public:

        BuildingException(const std::string& cause);

        virtual ~BuildingException();

      protected:

      private:
    };

  }
}

#endif // BUILDINGEXCEPTION_H
