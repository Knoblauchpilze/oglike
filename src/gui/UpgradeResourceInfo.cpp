
#include "UpgradeResourceInfo.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "ComponentFactory.h"
#include "SwitchPictureContainer.h"

namespace ogame {
  namespace gui {

    UpgradeResourceInfo::UpgradeResourceInfo(const std::string& name):
      view::GraphicContainer(name,
                             view::utils::Area())
    {
      createView();
    }

    UpgradeResourceInfo::~UpgradeResourceInfo() {}

    void UpgradeResourceInfo::createView() {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(6u, 4u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create upgrade resource info panel"));
      }

      LabelContainerShPtr title = createLabelPanel(
        std::string("title"),
        std::string("Resources needed:"),
        SDL_Color{128, 128, 128, SDL_ALPHA_OPAQUE}
      );
      LabelledPictureShPtr metal = createLabelledPicturePanel(
        std::string("metal_needed"),
        std::string("data/img/metal.bmp"),
        std::to_string(0u)
      );
      LabelledPictureShPtr crystal = createLabelledPicturePanel(
        std::string("crystal_needed"),
        std::string("data/img/crystal.bmp"),
        std::to_string(0u)
      );
      LabelledPictureShPtr deut = createLabelledPicturePanel(
        std::string("deut_needed"),
        std::string("data/img/deuterium.bmp"),
        std::to_string(0u)
      );
      SwitchPictureContainerShPtr upgrade = ComponentFactory::createSwitchPicturePanel(
        std::string("upgrade_label"),
        std::string("data/img/button_ok.bmp"),
        std::string("data/img/button_nok.bmp")
      );
      upgrade->updateStatus(true);

      if (title == nullptr ||
          metal == nullptr ||
          crystal == nullptr ||
          deut == nullptr ||
          upgrade == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create upgrade resource info panel"));
      }

      layout->addItem(title,   0u, 0u, 6u, 1u);
      addChild(title);
      layout->addItem(metal,   0u, 1u, 1u, 2u);
      addChild(metal);
      layout->addItem(crystal, 1u, 1u, 1u, 2u);
      addChild(crystal);
      layout->addItem(deut,    2u, 1u, 1u, 2u);
      addChild(deut);
      layout->addItem(upgrade, 4u, 1u, 2u, 2u);
      addChild(upgrade);

      setLayout(layout);
    }

  }
}
