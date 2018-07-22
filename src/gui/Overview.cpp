
#include "Overview.h"
#include "GridLayout.h"
#include "PlanetDescription.h"
#include "GuiException.h"
#include "LabelContainer.h"
#include "ComponentFactory.h"
#include "FontFactory.h"
#include "PictureContainer.h"
#include "ConditionalPictureContainer.h"

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
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(4u, 6u, 0.0f);
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

      if (moonLink == nullptr ||
          name == nullptr ||
          description == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create overview"));
      }

      layout->addItem(moonLink,    0u, 0u, 1u, 2u);
      addChild(moonLink);
      layout->addItem(name,        1u, 0u, 3u, 1u);
      addChild(name);
      layout->addItem(description, 1u, 3u, 3u, 3u);
      addChild(description);

      setLayout(layout);
    }

    void OverView::connectDataModel(player::GeneralDataModelShPtr dataModel) {
      dataModel->registerForAction(player::Action::ChangePlanet, this);
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

      makeDeepDirty();
      unlock();
    }
  }
}
