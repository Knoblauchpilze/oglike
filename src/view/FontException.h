#ifndef FONTEXCEPTION_H
#define FONTEXCEPTION_H

#include "ViewException.h"

namespace ogame {
  namespace view {

    class FontException: public ViewException
    {
      public:

        FontException(const std::string& cause);

        virtual ~FontException();

      protected:

      private:
    };

  }
}

#endif // FONTEXCEPTION_H