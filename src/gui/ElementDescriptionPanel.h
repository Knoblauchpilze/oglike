#ifndef ELEMENTDESCRIPTIONPANEL_H
#define ELEMENTDESCRIPTIONPANEL_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"

namespace ogame {
  namespace gui {

    class ElementDescriptionPanel: public view::GraphicContainer
    {
      public:

        ElementDescriptionPanel(const std::string& name);

        virtual ~ElementDescriptionPanel();

      private:

    };

    using ElementDescriptionPanelShPtr = std::shared_ptr<ElementDescriptionPanel>;
  }
}

#include "ElementDescriptionPanel.hxx"

#endif // ELEMENTDESCRIPTIONPANEL_H