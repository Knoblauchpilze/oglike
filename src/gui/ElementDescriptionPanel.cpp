
#include "ElementDescriptionPanel.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"
#include "UpgradeInfo.h"
#include "UpgradeResourceInfo.h"

namespace ogame {
  namespace gui {

    ElementDescriptionPanel::ElementDescriptionPanel(const std::string& name,
                                                     player::GeneralDataModelShPtr model):
      view::GraphicContainer(name,
                             view::utils::Area())
    {
      createView(model);
    }

    ElementDescriptionPanel::~ElementDescriptionPanel() {}

    void ElementDescriptionPanel::createView(player::GeneralDataModelShPtr model) {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(3u, 5u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create element description panel"));
      }

      // Create both the picture and the buying action.
      PictureContainerShPtr image = ComponentFactory::createPicturePanel(std::string("image_panel"), std::string("data/img/crystal_mine.bmp"));
      UpgradeInfoShPtr upgradeInfo = std::make_shared<UpgradeInfo>(std::string("upgrade_info"));
      UpgradeResourceInfoShPtr neededResources = std::make_shared<UpgradeResourceInfo>(std::string("need_resources"), model);
      view::GraphicContainerShPtr info = std::make_shared<view::GraphicContainer>(std::string("info_panel"), view::utils::Area());

      if (image == nullptr ||
          upgradeInfo == nullptr ||
          neededResources == nullptr ||
          info == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create element description panel"));
      }

      layout->addItem(image,           0u, 0u, 1u, 4u);
      addChild(image);
      layout->addItem(upgradeInfo,     1u, 0u, 2u, 2u);
      addChild(upgradeInfo);
      layout->addItem(neededResources, 1u, 2u, 2u, 2u);
      addChild(neededResources);
      layout->addItem(info,            0u, 0u, 3u, 1u);
      addChild(info);

      setLayout(layout);
    }

  }
}
