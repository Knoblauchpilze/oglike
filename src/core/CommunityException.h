#ifndef COMMUNITYEXCEPTION_H
#define COMMUNITYEXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace core {

    class CommunityException: public OgameException
    {
      public:

        CommunityException(const std::string& cause);

        virtual ~CommunityException();

      protected:

      private:
    };

  }
}

#endif // COMMUNITYEXCEPTION_H
