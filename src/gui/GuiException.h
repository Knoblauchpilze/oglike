#ifndef GUIEXCEPTION_H
#define GUIEXCEPTION_H

#include "ViewException.h"

namespace ogame {
  namespace gui {

    class GuiException: public view::ViewException
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