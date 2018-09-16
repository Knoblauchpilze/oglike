
#include "ShipSelectionPanel.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "LabelledPicture.h"
#include "ValueSelector.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    ShipSelectionPanel::ShipSelectionPanel(const std::string& name,
                                           const core::Ship::Type& type):
      view::GraphicContainer(name,
                             view::utils::Area())
    {
      createView(type);
    }

    ShipSelectionPanel::~ShipSelectionPanel() {}

    void ShipSelectionPanel::createView(const core::Ship::Type& type) {
      // Create the layout.
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(1u, 5u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create view ") + getName());
      }

      // Assign the layout.
      setLayout(layout);

      LabelledPictureShPtr shipPicture = createLabelledPictureContainer(
        std::string("image"),
        getPictureNameFromShip(type)
      );

      std::vector<std::string> options = { std::to_string(0) };

      ValueSelectorShPtr shipDispatchNumber = ComponentFactory::createValueSelectorPanel(
        std::string("count"),
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/upcfb.ttf"),
          219, 140, 40, SDL_ALPHA_OPAQUE
        ),
        options,
        ValueSelector::Alignment::VerticalRight
      );

      if (shipPicture == nullptr ||
          shipDispatchNumber == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create ship selection panel"));
      }

      // Add the images panel to the layout.
      addChild(shipPicture,         0u, 0u, 1u, 4u);
      addChild(shipDispatchNumber,  0u, 4u, 1u, 1u);
    }

  }
}
