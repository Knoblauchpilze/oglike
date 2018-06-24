#ifndef GUIEXCEPTION_H
#define GUIEXCEPTION_H

#include "ViewException.h"

namespace ogame {
  namespace gui {

    class GuiException: public ogame::core::OgameException
    {
      public:

        GuiException(const std::string& cause);

        virtual ~GuiException();

      protected:

      private:
    };

  }
}

#endif // GUIEXCEPTION_H