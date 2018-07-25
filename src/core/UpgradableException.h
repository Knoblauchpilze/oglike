#ifndef UPGRADABLEEXCEPTION_H
#define UPGRADABLEEXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace core {

    class UpgradableException: public OgameException
    {
      public:

        UpgradableException(const std::string& cause);

        virtual ~UpgradableException();

      protected:

      private:
    };

  }
}

#endif // UPGRADABLEEXCEPTION_H
