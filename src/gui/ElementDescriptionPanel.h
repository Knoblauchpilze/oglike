#ifndef ELEMENTDESCRIPTIONPANEL_H
#define ELEMENTDESCRIPTIONPANEL_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"
#include "Account.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class ElementDescriptionPanel: public view::GraphicContainer
    {
      public:

        ElementDescriptionPanel(const std::string& name,
                                player::GeneralDataModelShPtr model);

        virtual ~ElementDescriptionPanel();

        void setImagePath(const std::string& path);

        void triggerUnitCount();

        template <typename Element>
        inline
        void populateInformationFromElement(const Element& element,
                                            const core::Planet& planet,
                                            const core::Account& account);

      private:

        void createView(player::GeneralDataModelShPtr model);

      private:

    };

    using ElementDescriptionPanelShPtr = std::shared_ptr<ElementDescriptionPanel>;
  }
}

#include "ElementDescriptionPanel.hxx"

#endif // ELEMENTDESCRIPTIONPANEL_H