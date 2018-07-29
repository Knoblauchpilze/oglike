
#include "Overview.h"
#include "GridLayout.h"
#include "PlanetDescription.h"
#include "GuiException.h"
#include "LabelContainer.h"
#include "ComponentFactory.h"
#include "FontFactory.h"
#include "PictureContainer.h"
#include "ConditionalPictureContainer.h"
#include "UpgradeActionContainer.h"

namespace ogame {
  namespace gui {

    OverView::OverView(const std::string& name, player::GeneralDataModelShPtr model):
      PictureContainer(name,
                       std::string("data/img/overview_bg.bmp")),
      player::GeneralActionListener(model.get())
    {
      setBackgroundColor(SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE});

      createView(model);

      connectDataModel(model);
    }

    OverView::~OverView() {}

    void OverView::createView(player::GeneralDataModelShPtr model) {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(6u, 10u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create overview"));
      }

      // Create the navigation panel.
      ConditionalPictureContainerShPtr moonLink = ComponentFactory::createConditionalPicturePanel(
        std::string("moon_link"),
        std::string("data/img/moon_link.bmp"),
        view::EventListener::Interaction::Mouse,
        true
      );

      LabelContainerShPtr name = ComponentFactory::createLabelPanel(
        std::string("planet_name"),
        std::string("Overview - Default planet name"),
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/tahomabd.ttf"),
          128, 128, 128
        ),
        LabelContainer::Alignment::Center,
        SDL_Color{0, 0, 0, SDL_ALPHA_OPAQUE}
      );
      PlanetDescriptionShPtr description = std::make_shared<PlanetDescription>(std::string("planet_description"), model);

      UpgradeActionContainerShPtr building = std::make_shared<UpgradeActionContainer>(std::string("building_upgrade"));
      UpgradeActionContainerShPtr research = std::make_shared<UpgradeActionContainer>(std::string("research_upgrade"));
      UpgradeActionContainerShPtr shipyard = std::make_shared<UpgradeActionContainer>(std::string("shipyard_upgrade"), true);

      if (moonLink == nullptr ||
          name == nullptr ||
          description == nullptr ||
          building == nullptr ||
          research == nullptr ||
          shipyard == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create overview"));
      }

      layout->addItem(moonLink,    0u, 0u, 2u, 3u);
      addChild(moonLink);
      layout->addItem(name,        2u, 0u, 4u, 1u);
      addChild(name);
      layout->addItem(description, 2u, 3u, 4u, 3u);
      addChild(description);
      layout->addItem(building,    0u, 7u, 2u, 3u);
      addChild(building);
      layout->addItem(research,    2u, 7u, 2u, 3u);
      addChild(research);
      layout->addItem(shipyard,    4u, 7u, 2u, 3u);
      addChild(shipyard);

      setLayout(layout);
    }

    void OverView::connectDataModel(player::GeneralDataModelShPtr dataModel) {
      dataModel->registerForAction(player::Action::ChangePlanet, this);
      dataModel->registerForAction(player::Action::ChangeAccount, this);
    }

    void OverView::populateWithPlanetData(const core::Planet& planet) {
      lock();

      // Update each information.
      ConditionalPictureContainer* moonLink = getChild<ConditionalPictureContainer*>(std::string("moon_link"));
      if (checkChild(moonLink, "Planet moon link")) {
        moonLink->setActive(planet.hasMoon());
      }

      LabelContainer* name = getChild<LabelContainer*>(std::string("planet_name"));
      if (checkChild(name, "Planet name overview")) {
        name->setText(std::string("Overview - ") + planet.getName());
      }

      UpgradeActionContainer* building = getChild<UpgradeActionContainer*>(std::string("building_upgrade"));
      if (checkChild(building, "Building upgrade container")) {
        building->populateWithBuildingData(planet);
      }

      UpgradeActionContainer* shipyard = getChild<UpgradeActionContainer*>(std::string("shipyard_upgrade"));
      if (checkChild(shipyard, "Shipyard upgrade container")) {
        shipyard->populateWithShipyardData(planet);
      }

      makeDeepDirty();
      unlock();
    }

    void OverView::populateWithAccountData(const core::Account& account) {
      lock();

      UpgradeActionContainer* research = getChild<UpgradeActionContainer*>(std::string("research_upgrade"));
      if (checkChild(research, "Research upgrade container")) {
        research->populateWithResearchData(account);
      }

      makeDeepDirty();
      unlock();
    }
  }
}
