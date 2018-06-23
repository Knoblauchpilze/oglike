#ifndef GRAPHICCONTAINEREXCEPTION_H
#define GRAPHICCONTAINEREXCEPTION_H

#include "ViewException.h"

namespace ogame {
  namespace view {

    class GraphicContainerException: public ViewException
    {
      public:

        GraphicContainerException(const std::string& cause);

        virtual ~GraphicContainerException();

      protected:

      private:
    };

  }
}

#endif // GRAPHICCONTAINEREXCEPTION_H