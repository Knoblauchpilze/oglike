
#include "ResearchView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PictureContainer.h"
#include "ComponentFactory.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    ResearchView::ResearchView(const std::string& name, player::GeneralDataModelShPtr model):
      view::GraphicContainer(name,
                             view::utils::Area()),
      player::GeneralActionListener(model.get())
    {
      setBackgroundColor(SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE});

      createView(model);

      connectDataModel(model);
    }

    ResearchView::~ResearchView() {}

    void ResearchView::createView(player::GeneralDataModelShPtr model) {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(8u, 5u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create research view"));
      }

      PictureContainerShPtr image = ComponentFactory::createPicturePanel(std::string("image_panel"), std::string("data/img/research_bg.bmp"));

      std::string level0 = std::to_string(0);
      LabelledPictureShPtr energy = createLabelledPictureContainer(std::string("energy_tech"), std::string("data/img/energy_tech.bmp"), level0);
      LabelledPictureShPtr laser = createLabelledPictureContainer(std::string("laser_tech"), std::string("data/img/laser_tech.bmp"), level0);
      LabelledPictureShPtr ions = createLabelledPictureContainer(std::string("ions_tech"), std::string("data/img/ions_tech.bmp"), level0);
      LabelledPictureShPtr hyperspace = createLabelledPictureContainer(std::string("hyperspace_tech"), std::string("data/img/hyperspace_tech.bmp"), level0);
      LabelledPictureShPtr plasma = createLabelledPictureContainer(std::string("plasma_tech"), std::string("data/img/plasma_tech.bmp"), level0);
      LabelledPictureShPtr combustionDrive = createLabelledPictureContainer(std::string("combustion_drive_tech"), std::string("data/img/combustion_drive_tech.bmp"), level0);
      LabelledPictureShPtr impulseDrive = createLabelledPictureContainer(std::string("impulse_drive_tech"), std::string("data/img/impulse_drive_tech.bmp"), level0);
      LabelledPictureShPtr hyperspaceDrive = createLabelledPictureContainer(std::string("hyperspace_drive_tech"), std::string("data/img/hyperspace_drive_tech.bmp"), level0);
      LabelledPictureShPtr espionage = createLabelledPictureContainer(std::string("espionage_tech"), std::string("data/img/espionage_tech.bmp"), level0);
      LabelledPictureShPtr computer = createLabelledPictureContainer(std::string("computer_tech"), std::string("data/img/computer_tech.bmp"), level0);
      LabelledPictureShPtr astrophysics = createLabelledPictureContainer(std::string("astrophysics_tech"), std::string("data/img/astrophysics_tech.bmp"), level0);
      LabelledPictureShPtr irn = createLabelledPictureContainer(std::string("irn_tech"), std::string("data/img/intergalactic_research_network_tech.bmp"), level0);
      LabelledPictureShPtr graviton = createLabelledPictureContainer(std::string("graviton_tech"), std::string("data/img/graviton_tech.bmp"), level0);
      LabelledPictureShPtr weapon = createLabelledPictureContainer(std::string("weapon_tech"), std::string("data/img/weapon_tech.bmp"), level0);
      LabelledPictureShPtr shielding = createLabelledPictureContainer(std::string("shielding_tech"), std::string("data/img/shielding_tech.bmp"), level0);
      LabelledPictureShPtr armour = createLabelledPictureContainer(std::string("armour_tech"), std::string("data/img/armour_tech.bmp"), level0);

      if (image == nullptr ||
          energy == nullptr ||
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

      layout->addItem(image,            0u, 0u, 8u, 2u);
      addChild(image);
      layout->addItem(energy,           0u, 2u, 1u, 1u);
      addChild(energy);
      layout->addItem(laser,            1u, 2u, 1u, 1u);
      addChild(laser);
      layout->addItem(ions,             2u, 2u, 1u, 1u);
      addChild(ions);
      layout->addItem(hyperspace,       3u, 2u, 1u, 1u);
      addChild(hyperspace);
      layout->addItem(plasma,           4u, 2u, 1u, 1u);
      addChild(plasma);
      layout->addItem(combustionDrive,  5u, 2u, 1u, 1u);
      addChild(combustionDrive);
      layout->addItem(impulseDrive,     6u, 2u, 1u, 1u);
      addChild(impulseDrive);
      layout->addItem(hyperspaceDrive,  7u, 2u, 1u, 1u);
      addChild(hyperspaceDrive);
      layout->addItem(espionage,        0u, 3u, 1u, 1u);
      addChild(espionage);
      layout->addItem(computer,         1u, 3u, 1u, 1u);
      addChild(computer);
      layout->addItem(astrophysics,     2u, 3u, 1u, 1u);
      addChild(astrophysics);
      layout->addItem(irn,              3u, 3u, 1u, 1u);
      addChild(irn);
      layout->addItem(graviton,         4u, 3u, 1u, 1u);
      addChild(graviton);
      layout->addItem(weapon,           5u, 3u, 1u, 1u);
      addChild(weapon);
      layout->addItem(shielding,        6u, 3u, 1u, 1u);
      addChild(shielding);
      layout->addItem(armour,           7u, 3u, 1u, 1u);
      addChild(armour);

      setLayout(layout);
    }

    void ResearchView::connectDataModel(player::GeneralDataModelShPtr dataModel) {
      dataModel->registerForAction(player::Action::ChangePlanet, this);
    }

    void ResearchView::populateWithAccountData(const core::Account& account, const core::Planet& planet) {
      lock();

      // Update each information.
      LabelledPicture* energy = getChild<LabelledPicture*>(std::string("energy_tech"));
      if (checkChild(energy, "Planet energey technology")) {
        energy->setLabel(getDisplayForTech(core::Research::Type::Energy, account));
      }
      LabelledPicture* laser = getChild<LabelledPicture*>(std::string("laser_tech"));
      if (checkChild(laser, "Planet laser technology")) {
        laser->setLabel(getDisplayForTech(core::Research::Type::Laser, account));
      }
      LabelledPicture* ions = getChild<LabelledPicture*>(std::string("ions_tech"));
      if (checkChild(ions, "Planet ions technology")) {
        ions->setLabel(getDisplayForTech(core::Research::Type::Ion, account));
      }
      LabelledPicture* hyperspace = getChild<LabelledPicture*>(std::string("hyperspace_tech"));
      if (checkChild(hyperspace, "Planet hyperspace technology")) {
        hyperspace->setLabel(getDisplayForTech(core::Research::Type::Hyperspace, account));
      }
      LabelledPicture* plasma = getChild<LabelledPicture*>(std::string("plasma_tech"));
      if (checkChild(plasma, "Planet plasma technology")) {
        plasma->setLabel(getDisplayForTech(core::Research::Type::Plasma, account));
      }

      LabelledPicture* combustionDrive = getChild<LabelledPicture*>(std::string("combustion_drive_tech"));
      if (checkChild(combustionDrive, "Planet combustion drive technology")) {
        combustionDrive->setLabel(getDisplayForTech(core::Research::Type::CombustionDrive, account));
      }
      LabelledPicture* impulseDrive = getChild<LabelledPicture*>(std::string("impulse_drive_tech"));
      if (checkChild(impulseDrive, "Planet impulse drive technology")) {
        impulseDrive->setLabel(getDisplayForTech(core::Research::Type::ImpulseDrive, account));
      }
      LabelledPicture* hyperspaceDrive = getChild<LabelledPicture*>(std::string("hyperspace_drive_tech"));
      if (checkChild(hyperspaceDrive, "Planet hyperspace drive technology")) {
        hyperspaceDrive->setLabel(getDisplayForTech(core::Research::Type::HyperspaceDrive, account));
      }

      LabelledPicture* espionage = getChild<LabelledPicture*>(std::string("espionage_tech"));
      if (checkChild(espionage, "Planet space technology")) {
        espionage->setLabel(getDisplayForTech(core::Research::Type::Espionage, account));
      }
      LabelledPicture* computer = getChild<LabelledPicture*>(std::string("computer_tech"));
      if (checkChild(computer, "Planet computer technology")) {
        computer->setLabel(getDisplayForTech(core::Research::Type::Computer, account));
      }
      LabelledPicture* astrophysics = getChild<LabelledPicture*>(std::string("astrophysics_tech"));
      if (checkChild(astrophysics, "Planet space technology")) {
        astrophysics->setLabel(getDisplayForTech(core::Research::Type::Astrophysics, account));
      }
      LabelledPicture* irn = getChild<LabelledPicture*>(std::string("irn_tech"));
      if (checkChild(irn, "Planet intergalactic research network technology")) {
        irn->setLabel(getDisplayForTech(core::Research::Type::IRN, account));
      }
      LabelledPicture* graviton = getChild<LabelledPicture*>(std::string("graviton_tech"));
      if (checkChild(graviton, "Planet graviton technology")) {
        graviton->setLabel(getDisplayForTech(core::Research::Type::Graviton, account));
      }

      LabelledPicture* weapon = getChild<LabelledPicture*>(std::string("weapon_tech"));
      if (checkChild(weapon, "Planet weapon technology")) {
        weapon->setLabel(getDisplayForTech(core::Research::Type::Weapon, account));
      }
      LabelledPicture* shielding = getChild<LabelledPicture*>(std::string("shielding_tech"));
      if (checkChild(shielding, "Planet shielding technology")) {
        shielding->setLabel(getDisplayForTech(core::Research::Type::Shielding, account));
      }
      LabelledPicture* armour = getChild<LabelledPicture*>(std::string("armour_tech"));
      if (checkChild(armour, "Planet armour technology")) {
        armour->setLabel(getDisplayForTech(core::Research::Type::Armour, account));
      }

      makeDeepDirty();
      unlock();
    }
  }
}
