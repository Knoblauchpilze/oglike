#ifndef SHIPSELECTIONPANEL_H
#define SHIPSELECTIONPANEL_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "LabelledPicture.h"
#include "Ship.h"

namespace ogame {
  namespace gui {

    class ShipSelectionPanel: public view::GraphicContainer
    {
      public:

        ShipSelectionPanel(const std::string& name,
                           const core::Ship::Type& type);

        virtual ~ShipSelectionPanel();

      private:

        void createView(const core::Ship::Type& type);

      private:

        LabelledPictureShPtr createLabelledPictureContainer(const std::string& name,
                                                            const std::string& picture);

        const std::string getPictureNameFromShip(const core::Ship::Type& type, const bool reduced = true) const noexcept;

    };

    using ShipSelectionPanelShPtr = std::shared_ptr<ShipSelectionPanel>;
  }
}

#include "ShipSelectionPanel.hxx"

#endif // SHIPSELECTIONPANEL_H
