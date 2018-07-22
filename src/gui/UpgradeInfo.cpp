
#include "UpgradeInfo.h"
#include "GridLayout.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    UpgradeInfo::UpgradeInfo(const std::string& name):
      view::GraphicContainer(name,
                             view::utils::Area())
    {
      createView();
    }

    UpgradeInfo::~UpgradeInfo() {}

    void UpgradeInfo::createView() {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(4u, 5u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create upgrade info panel"));
      }

      LabelContainerShPtr title = createLabelPanel(
        std::string("title"),
        std::string("Default action panel:"),
        SDL_Color{214, 154, 38, SDL_ALPHA_OPAQUE}
      );
      LabelContainerShPtr productionTime = createLabelPanel(
        std::string("production_time"),
        std::string("Production duration: 0s"),
        SDL_Color{255, 255, 255, SDL_ALPHA_OPAQUE}
      );
      LabelContainerShPtr energyNeeded = createLabelPanel(
        std::string("energy_needed"),
        std::string("Energy needed: 0"),
        SDL_Color{255, 255, 255, SDL_ALPHA_OPAQUE}
      );
      LabelContainerShPtr number = createLabelPanel(
        std::string("number"),
        std::string("Number:"),
        SDL_Color{128, 128, 128, SDL_ALPHA_OPAQUE}
      );
      LabelContainerShPtr unitNumber = createLabelPanel(
        std::string("unit_number"),
        std::string(""),
        SDL_Color{0, 0, 0, SDL_ALPHA_OPAQUE},
        SDL_Color{255, 255, 255, SDL_ALPHA_OPAQUE},
        false
      );

      if (title == nullptr ||
          productionTime == nullptr ||
          energyNeeded == nullptr ||
          number == nullptr ||
          unitNumber == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create upgrade info panel"));
      }

      layout->addItem(title,          0u, 0u, 2u, 1u);
      addChild(title);
      layout->addItem(productionTime, 0u, 1u, 2u, 1u);
      addChild(productionTime);
      layout->addItem(energyNeeded,   0u, 2u, 2u, 1u);
      addChild(energyNeeded);
      layout->addItem(number,         2u, 1u, 1u, 1u);
      addChild(number);
      layout->addItem(unitNumber,     2u, 2u, 1u, 2u);
      addChild(unitNumber);

      setLayout(layout);
    }

  }
}
