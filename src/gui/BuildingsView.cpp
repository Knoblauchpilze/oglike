
#include "BuildingsView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    BuildingsView::BuildingsView(const std::string& name, player::GeneralDataModelShPtr model):
      AbstractBuyingView(name, model)
    {
      createView(model);

      connectDataModel(model);
    }

    BuildingsView::~BuildingsView() {}

    void BuildingsView::createView(player::GeneralDataModelShPtr model) {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(6u, 5u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create buildings view"));
      }

      PictureContainerShPtr image = ComponentFactory::createPicturePanel(std::string("image_panel"), std::string("data/img/resources_bg.bmp"));

      std::string level0 = std::to_string(0);
      LabelledPictureShPtr metal = createLabelledPictureContainer(std::string("metal_mine"), std::string("data/img/metal_mine.bmp"), level0);
      LabelledPictureShPtr crystal = createLabelledPictureContainer(std::string("crystal_mine"), std::string("data/img/crystal_mine.bmp"), level0);
      LabelledPictureShPtr deut = createLabelledPictureContainer(std::string("deut_synthesizer"), std::string("data/img/deuterium_synthesizer.bmp"), level0);
      LabelledPictureShPtr solarPlant = createLabelledPictureContainer(std::string("solar_plant"), std::string("data/img/solar_plant.bmp"), level0);
      LabelledPictureShPtr fusionPlant = createLabelledPictureContainer(std::string("fusion_plant"), std::string("data/img/fusion_plant.bmp"), level0);
      LabelledPictureShPtr solarSatellite = createLabelledPictureContainer(std::string("solar_satellite"), std::string("data/img/solar_satellite.bmp"), level0);
      LabelledPictureShPtr metalStorage = createLabelledPictureContainer(std::string("metal_storage"), std::string("data/img/metal_storage.bmp"), level0);
      LabelledPictureShPtr crystalStorage = createLabelledPictureContainer(std::string("crystal_storage"), std::string("data/img/crystal_storage.bmp"), level0);
      LabelledPictureShPtr deutTank = createLabelledPictureContainer(std::string("deut_tank"), std::string("data/img/deuterium_tank.bmp"), level0);

      if (image == nullptr ||
          metal == nullptr ||
          crystal == nullptr ||
          deut == nullptr ||
          solarPlant == nullptr ||
          fusionPlant == nullptr ||
          solarSatellite == nullptr ||
          metalStorage == nullptr ||
          crystalStorage == nullptr ||
          deutTank == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create buildings view"));
      }

      layout->addItem(image,          0u, 0u, 6u, 2u);
      addChild(image);
      layout->addItem(metal,          0u, 2u, 1u, 1u);
      addChild(metal);
      layout->addItem(crystal,        1u, 2u, 1u, 1u);
      addChild(crystal);
      layout->addItem(deut,           2u, 2u, 1u, 1u);
      addChild(deut);
      layout->addItem(solarPlant,     3u, 2u, 1u, 1u);
      addChild(solarPlant);
      layout->addItem(fusionPlant,    4u, 2u, 1u, 1u);
      addChild(fusionPlant);
      layout->addItem(solarSatellite, 5u, 2u, 1u, 1u);
      addChild(solarSatellite);
      layout->addItem(metalStorage,   0u, 3u, 1u, 1u);
      addChild(metalStorage);
      layout->addItem(crystalStorage, 1u, 3u, 1u, 1u);
      addChild(crystalStorage);
      layout->addItem(deutTank,       2u, 3u, 1u, 1u);
      addChild(deutTank);

      setLayout(layout);
    }

    void BuildingsView::connectDataModel(player::GeneralDataModelShPtr dataModel) {
      dataModel->registerForAction(player::Action::ChangePlanet, this);
    }

    void BuildingsView::populateWithData(const core::Planet& planet, const core::Account& account) {
      lock();

      // Update each information.
      LabelledPicture* metal = getChild<LabelledPicture*>(std::string("metal_mine"));
      if (checkChild(metal, "Planet metal mine")) {
        metal->setLabel(getDisplayForBuilding(core::Building::Type::ResourceMine, planet));
      }
      LabelledPicture* crystal = getChild<LabelledPicture*>(std::string("crystal_mine"));
      if (checkChild(crystal, "Planet crystal mine")) {
        crystal->setLabel(getDisplayForBuilding(core::Building::Type::ResourceMine, planet));
      }
      LabelledPicture* deut = getChild<LabelledPicture*>(std::string("deut_synthesizer"));
      if (checkChild(deut, "Planet deuterium synthesizer")) {
        deut->setLabel(getDisplayForBuilding(core::Building::Type::ResourceMine, planet));
      }

      LabelledPicture* solarPlant = getChild<LabelledPicture*>(std::string("solar_plant"));
      if (checkChild(solarPlant, "Planet solar plant")) {
        solarPlant->setLabel(getDisplayForBuilding(core::Building::Type::Plant, planet));
      }
      LabelledPicture* fusionPlant = getChild<LabelledPicture*>(std::string("fusion_plant"));
      if (checkChild(fusionPlant, "Planet fusion plant")) {
        fusionPlant->setLabel(getDisplayForBuilding(core::Building::Type::Plant, planet));
      }
      LabelledPicture* solarSatellite = getChild<LabelledPicture*>(std::string("solar_satellite"));
      if (checkChild(solarSatellite, "Planet solar satellite")) {
        solarSatellite->setLabel(getDisplayForBuilding(core::Building::Type::Plant, planet));
      }

      LabelledPicture* metalStorage = getChild<LabelledPicture*>(std::string("metal_storage"));
      if (checkChild(metalStorage, "Planet metal storage")) {
        metalStorage->setLabel(getDisplayForBuilding(core::Building::Type::Storage, planet));
      }
      LabelledPicture* crystalStorage = getChild<LabelledPicture*>(std::string("crystal_storage"));
      if (checkChild(crystalStorage, "Planet crystal storage")) {
        crystalStorage->setLabel(getDisplayForBuilding(core::Building::Type::Storage, planet));
      }
      LabelledPicture* deutTank = getChild<LabelledPicture*>(std::string("deut_tank"));
      if (checkChild(deutTank, "Planet deuterium tank")) {
        deutTank->setLabel(getDisplayForBuilding(core::Building::Type::Storage, planet));
      }

      makeDeepDirty();
      unlock();
    }
  }
}
