
#include "UpgradeInfo.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    UpgradeInfo::UpgradeInfo(const std::string& name,
                             player::GeneralDataModelShPtr model):
      view::GraphicContainer(name,
                             view::utils::Area()),
      player::GeneralActionListener(model.get())
    {
      createView();
    }

    UpgradeInfo::~UpgradeInfo() {}

    void UpgradeInfo::createView() {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(4u, 5u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create upgrade info panel"));
      }

      std::vector<std::string> options(999);
      for (unsigned value = 1u ; value < 1000u ; ++value) {
        options[value - 1u] = std::to_string(value);
      }

      LabelContainerShPtr title = createLabelPanel(
        std::string("title"),
        std::string("Default action panel:"),
        SDL_Color{214, 154, 38, SDL_ALPHA_OPAQUE}
      );
      LabelContainerShPtr level = createLabelPanel(
        std::string("level"),
        std::string("Level 0"),
        SDL_Color{214, 154, 38, SDL_ALPHA_OPAQUE},
        SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE},
        true,
        LabelContainer::Alignment::Right
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
      LabelContainerShPtr productionIncrease = createLabelPanel(
        std::string("production_increase"),
        std::string("Production increase: 0"),
        SDL_Color{255, 255, 255, SDL_ALPHA_OPAQUE}
      );
      LabelContainerShPtr number = createLabelPanel(
        std::string("number"),
        std::string("Number:"),
        SDL_Color{128, 128, 128, SDL_ALPHA_OPAQUE},
        SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE},
        true,
        LabelContainer::Alignment::Left
      );
      ValueSelectorShPtr unitNumber = ComponentFactory::createValueSelectorPanel(
        std::string("unit_number"),
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/upcfb.ttf"),
          0, 0, 0, SDL_ALPHA_OPAQUE
        ),
        options,
        ValueSelector::Alignment::VerticalRight
      );

      if (title == nullptr ||
          level == nullptr ||
          productionTime == nullptr ||
          energyNeeded == nullptr ||
          productionIncrease == nullptr ||
          number == nullptr ||
          unitNumber == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create upgrade info panel"));
      }

      layout->addItem(title,              0u, 0u, 2u, 1u);
      addChild(title);
      layout->addItem(level,              3u, 0u, 1u, 1u);
      addChild(level);
      layout->addItem(productionTime,     0u, 1u, 3u, 1u);
      addChild(productionTime);
      layout->addItem(energyNeeded,       0u, 2u, 3u, 1u);
      addChild(energyNeeded);
      layout->addItem(productionIncrease, 0u, 3u, 3u, 1u);
      addChild(productionIncrease);
      layout->addItem(number,             3u, 1u, 1u, 1u);
      addChild(number);
      layout->addItem(unitNumber,         3u, 2u, 1u, 2u);
      addChild(unitNumber);

      setLayout(layout);

      unitNumber->addEventListener(this);
    }

  }
}
