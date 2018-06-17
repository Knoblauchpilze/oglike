#ifndef VIEWEXCEPTION_H
#define VIEWEXCEPTION_H

#include "OgameException.h"

namespace ogame {
  namespace view {

    class ViewException: public ogame::core::OgameException
    {
      public:

        ViewException(const std::string& cause);

        virtual ~ViewException();

      protected:

      private:
    };

  }
}

#endif // VIEWEXCEPTION_H