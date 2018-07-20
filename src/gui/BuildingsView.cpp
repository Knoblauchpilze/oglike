
#include "BuildingsView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    BuildingsView::BuildingsView(const std::string& name, player::GeneralDataModelShPtr model):
      view::GraphicContainer(name,
                             view::utils::Area()),
      player::GeneralActionListener(model.get())
    {
      setBackgroundColor(SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE});

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

    void BuildingsView::populateWithPlanetData(const core::Planet& planet) {
      lock();

      makeDeepDirty();
      unlock();
    }
  }
}
