
#include "BuildingsView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    BuildingsView::BuildingsView(const std::string& name, player::GeneralDataModelShPtr model):
      AbstractBuyingView(name,
                         model,
                         6u,
                         5u,
                         std::string("data/img/resources_bg.bmp"))
    {
      createView();

      connectDataModel(player::Action::ChangePlanet);
    }

    BuildingsView::~BuildingsView() {}

    void BuildingsView::createView() {
      // Create all elements.
      std::string level0 = std::to_string(0);
      LabelledPictureShPtr metal = createLabelledPictureContainer(
        std::string("metal_mine"),
        getPictureNameFromBuilding(core::Building::Type::MetalMine),
        level0
      );
      LabelledPictureShPtr crystal = createLabelledPictureContainer(
        std::string("crystal_mine"),
        getPictureNameFromBuilding(core::Building::Type::CrystalMine),
        level0
      );
      LabelledPictureShPtr deut = createLabelledPictureContainer(
        std::string("deut_synthesizer"),
        getPictureNameFromBuilding(core::Building::Type::DeuteriumMine),
        level0
      );
      LabelledPictureShPtr solarPlant = createLabelledPictureContainer(
        std::string("solar_plant"),
        getPictureNameFromBuilding(core::Building::Type::SolarPlant),
        level0
      );
      LabelledPictureShPtr fusionPlant = createLabelledPictureContainer(
        std::string("fusion_plant"),
        getPictureNameFromBuilding(core::Building::Type::FusionPlant),
        level0
      );
      LabelledPictureShPtr solarSatellite = createLabelledPictureContainer(
        std::string("solar_satellite"),
        getPictureNameFromBuilding(core::Building::Type::SolarPlant),
        level0
      );
      LabelledPictureShPtr metalStorage = createLabelledPictureContainer(
        std::string("metal_storage"),
        getPictureNameFromBuilding(core::Building::Type::MetalStorage),
        level0
      );
      LabelledPictureShPtr crystalStorage = createLabelledPictureContainer(
        std::string("crystal_storage"),
        getPictureNameFromBuilding(core::Building::Type::CrystalStorage),
        level0
      );
      LabelledPictureShPtr deutTank = createLabelledPictureContainer(
        std::string("deut_tank"),
        getPictureNameFromBuilding(core::Building::Type::DeuteriumStorage),
        level0
      );

      if (metal == nullptr ||
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

      addChild(metal,          0u, 2u, 1u, 1u);
      addChild(crystal,        1u, 2u, 1u, 1u);
      addChild(deut,           2u, 2u, 1u, 1u);
      addChild(solarPlant,     3u, 2u, 1u, 1u);
      addChild(fusionPlant,    4u, 2u, 1u, 1u);
      addChild(solarSatellite, 5u, 2u, 1u, 1u);
      addChild(metalStorage,   0u, 3u, 1u, 1u);
      addChild(crystalStorage, 1u, 3u, 1u, 1u);
      addChild(deutTank,       2u, 3u, 1u, 1u);
    }

    void BuildingsView::populateWithPlanetData(const core::Planet& planet) {
      lock();

      // Update each information.
      std::vector<std::pair<std::string, core::Building::Type>> buildings = {
        {std::string("metal_mine"), core::Building::Type::MetalMine},
        {std::string("crystal_mine"), core::Building::Type::CrystalMine},
        {std::string("deut_synthesizer"), core::Building::Type::DeuteriumMine},

        {std::string("solar_plant"), core::Building::Type::SolarPlant},
        {std::string("fusion_plant"), core::Building::Type::FusionPlant},
        {std::string("solar_satellite"), core::Building::Type::SolarPlant},

        {std::string("metal_storage"), core::Building::Type::MetalStorage},
        {std::string("crystal_storage"), core::Building::Type::CrystalStorage},
        {std::string("deut_tank"), core::Building::Type::DeuteriumStorage}
      };

      std::for_each(buildings.cbegin(), buildings.cend(),
        [this, &planet](const std::pair<std::string, core::Building::Type>& building) {
          LabelledPicture* buildingInfo = getChild<LabelledPicture*>(building.first);
          if (checkChild(buildingInfo, building.first)) {
            buildingInfo->setLabel(getDisplayForBuilding(building.second, planet));
          }
        }
      );

      makeDeepDirty();
      unlock();
    }
  }
}
