#ifndef SHIPSELECTIONPANEL_H
#define SHIPSELECTIONPANEL_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "BackgroundedLabel.h"
#include "Ship.h"

namespace ogame {
  namespace gui {

    class ShipSelectionPanel: public view::GraphicContainer
    {
      public:

        ShipSelectionPanel(const std::string& name,
                           const core::Ship::Type& type);

        virtual ~ShipSelectionPanel();

        void setCount(const unsigned& count);

      private:

        void createView(const core::Ship::Type& type);

      private:

        BackgroundedLabelShPtr createBackgroundedLabelContainer(const std::string& name,
                                                                const std::string& picture);

    };

    using ShipSelectionPanelShPtr = std::shared_ptr<ShipSelectionPanel>;
  }
}

#include "ShipSelectionPanel.hxx"

#endif // SHIPSELECTIONPANEL_H
