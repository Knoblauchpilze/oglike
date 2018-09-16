
#include "ResearchView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    ResearchView::ResearchView(const std::string& name, player::GeneralDataModelShPtr model):
      AbstractBuyingView(name,
                         model,
                         8u,
                         5u,
                         std::string("data/img/research_bg.bmp"))
    {
      createView();

      connectDataModel(player::Action::ChangePlanet);
      connectDataModel(player::Action::ChangeAccount);
    }

    ResearchView::~ResearchView() {}

    void ResearchView::createView() {
      // Create all elements.
      std::string level0 = std::to_string(0);
      LabelledPictureShPtr energy = createLabelledPictureContainer(
        std::string("energy_tech"),
        getPictureNameFromResearch(core::Research::Type::Energy),
        level0
      );
      LabelledPictureShPtr laser = createLabelledPictureContainer(
        std::string("laser_tech"),
        getPictureNameFromResearch(core::Research::Type::Laser),
        level0
      );
      LabelledPictureShPtr ions = createLabelledPictureContainer(
        std::string("ions_tech"),
        getPictureNameFromResearch(core::Research::Type::Ion),
        level0
      );
      LabelledPictureShPtr hyperspace = createLabelledPictureContainer(
        std::string("hyperspace_tech"),
        getPictureNameFromResearch(core::Research::Type::Hyperspace),
        level0
      );
      LabelledPictureShPtr plasma = createLabelledPictureContainer(
        std::string("plasma_tech"),
        getPictureNameFromResearch(core::Research::Type::Plasma),
        level0
      );
      LabelledPictureShPtr combustionDrive = createLabelledPictureContainer(
        std::string("combustion_drive_tech"),
        getPictureNameFromResearch(core::Research::Type::CombustionDrive),
        level0
      );
      LabelledPictureShPtr impulseDrive = createLabelledPictureContainer(
        std::string("impulse_drive_tech"),
        getPictureNameFromResearch(core::Research::Type::ImpulseDrive),
        level0
      );
      LabelledPictureShPtr hyperspaceDrive = createLabelledPictureContainer(
        std::string("hyperspace_drive_tech"),
        getPictureNameFromResearch(core::Research::Type::HyperspaceDrive),
        level0
      );
      LabelledPictureShPtr espionage = createLabelledPictureContainer(
        std::string("espionage_tech"),
        getPictureNameFromResearch(core::Research::Type::Espionage),
        level0
      );
      LabelledPictureShPtr computer = createLabelledPictureContainer(
        std::string("computer_tech"),
        getPictureNameFromResearch(core::Research::Type::Computer),
        level0
      );
      LabelledPictureShPtr astrophysics = createLabelledPictureContainer(
        std::string("astrophysics_tech"),
        getPictureNameFromResearch(core::Research::Type::Astrophysics),
        level0
      );
      LabelledPictureShPtr irn = createLabelledPictureContainer(
        std::string("irn_tech"),
        getPictureNameFromResearch(core::Research::Type::IRN),
        level0
      );
      LabelledPictureShPtr graviton = createLabelledPictureContainer(
        std::string("graviton_tech"),
        getPictureNameFromResearch(core::Research::Type::Graviton),
        level0
      );
      LabelledPictureShPtr weapon =
      createLabelledPictureContainer(
        std::string("weapon_tech"),
        getPictureNameFromResearch(core::Research::Type::Weapon),
        level0
      );
      LabelledPictureShPtr shielding = createLabelledPictureContainer(
        std::string("shielding_tech"),
        getPictureNameFromResearch(core::Research::Type::Shielding),
        level0
      );
      LabelledPictureShPtr armour = createLabelledPictureContainer(
        std::string("armour_tech"),
        getPictureNameFromResearch(core::Research::Type::Armour),
        level0
      );

      if (energy == nullptr ||
          laser == nullptr ||
          ions == nullptr ||
          hyperspace == nullptr ||
          plasma == nullptr ||
          combustionDrive == nullptr ||
          impulseDrive == nullptr ||
          hyperspaceDrive == nullptr ||
          espionage == nullptr ||
          computer == nullptr ||
          astrophysics == nullptr ||
          irn == nullptr ||
          graviton == nullptr ||
          weapon == nullptr ||
          shielding == nullptr ||
          armour == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create research view"));
      }

      addChild(energy,          0u, 2u, 1u, 1u);
      addChild(laser,           1u, 2u, 1u, 1u);
      addChild(ions,            2u, 2u, 1u, 1u);
      addChild(hyperspace,      3u, 2u, 1u, 1u);
      addChild(plasma,          4u, 2u, 1u, 1u);
      addChild(combustionDrive, 5u, 2u, 1u, 1u);
      addChild(impulseDrive,    6u, 2u, 1u, 1u);
      addChild(hyperspaceDrive, 7u, 2u, 1u, 1u);
      addChild(espionage,       0u, 3u, 1u, 1u);
      addChild(computer,        1u, 3u, 1u, 1u);
      addChild(astrophysics,    2u, 3u, 1u, 1u);
      addChild(irn,             3u, 3u, 1u, 1u);
      addChild(graviton,        4u, 3u, 1u, 1u);
      addChild(weapon,          5u, 3u, 1u, 1u);
      addChild(shielding,       6u, 3u, 1u, 1u);
      addChild(armour,          7u, 3u, 1u, 1u);
    }

    void ResearchView::populateWithAccountData(const core::Account& account) {
      lock();

      // Update each information.
      std::vector<std::pair<std::string, core::Research::Type>> researches = {
        {std::string("energy_tech"), core::Research::Type::Energy},
        {std::string("laser_tech"), core::Research::Type::Laser},
        {std::string("ions_tech"), core::Research::Type::Ion},
        {std::string("hyperspace_tech"), core::Research::Type::Hyperspace},
        {std::string("plasma_tech"), core::Research::Type::Plasma},

        {std::string("combustion_drive_tech"), core::Research::Type::CombustionDrive},
        {std::string("impulse_drive_tech"), core::Research::Type::ImpulseDrive},
        {std::string("hyperspace_drive_tech"), core::Research::Type::HyperspaceDrive},

        {std::string("espionage_tech"), core::Research::Type::Espionage},
        {std::string("computer_tech"), core::Research::Type::Computer},
        {std::string("astrophysics_tech"), core::Research::Type::Astrophysics},
        {std::string("irn_tech"), core::Research::Type::IRN},
        {std::string("graviton_tech"), core::Research::Type::Graviton},

        {std::string("weapon_tech"), core::Research::Type::Weapon},
        {std::string("shielding_tech"), core::Research::Type::Shielding},
        {std::string("armour_tech"), core::Research::Type::Armour}
      };

      std::for_each(researches.cbegin(), researches.cend(),
        [this, &account](const std::pair<std::string, core::Research::Type>& research) {
          LabelledPicture* researchInfo = getChild<LabelledPicture*>(research.first);
          if (checkChild(researchInfo, research.first)) {
            researchInfo->setLabel(getDisplayForTech(research.second, account));
          }
        }
      );

      makeDeepDirty();
      unlock();
    }
  }
}
