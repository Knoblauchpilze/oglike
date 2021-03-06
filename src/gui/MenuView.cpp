
#include "MenuView.h"
#include "LinearLayout.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    MenuView::MenuView(const std::string& name, player::GeneralDataModel* model, const player::View& initialView):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             false,
                             view::EventListener::Sensitivity::Local,
                             std::make_shared<view::LinearLayout>(
                               view::LinearLayout::Direction::Vertical,
                               0.0f,
                               0.0f,
                               this
                             ))
    {
      setBackgroundColor(SDL_Color{29, 34, 40, SDL_ALPHA_OPAQUE});

      createView(model);
    }

    MenuView::~MenuView() {}

    void MenuView::createView(player::GeneralDataModel* model) {
      // Create the colors for these state panels.
      const StateContainer::StateAssociation colors = {
        {StateContainer::State::Normal,       SDL_Color{29, 34, 40, SDL_ALPHA_OPAQUE}},
        {StateContainer::State::Highlighted,  SDL_Color{97, 154, 191, SDL_ALPHA_OPAQUE}},
        {StateContainer::State::Selected,     SDL_Color{97, 154, 191, SDL_ALPHA_OPAQUE}},
      };

      // Add each option.
      ActionProviderLabelStateContainerShPtr overview = createActionStateLabelPanel(
        player::View::Overview,
        std::string("Overview"),
        colors,
        model
      );
      ActionProviderLabelStateContainerShPtr resources = createActionStateLabelPanel(
        player::View::Resources,
        std::string("Resources"),
        colors,
        model
      );
      ActionProviderLabelStateContainerShPtr facilities = createActionStateLabelPanel(
        player::View::Facilities,
        std::string("Facilities"),
        colors,
        model
      );
      ActionProviderLabelStateContainerShPtr research = createActionStateLabelPanel(
        player::View::Research,
        std::string("Research"),
        colors,
        model
      );
      ActionProviderLabelStateContainerShPtr shipyard = createActionStateLabelPanel(
        player::View::Shipyard,
        std::string("Shipyard"),
        colors,
        model
      );
      ActionProviderLabelStateContainerShPtr defense = createActionStateLabelPanel(
        player::View::Defense,
        std::string("Defense"),
        colors,
        model
      );
      ActionProviderLabelStateContainerShPtr fleet = createActionStateLabelPanel(
        player::View::Fleet,
        std::string("Fleet"),
        colors,
        model
      );
      ActionProviderLabelStateContainerShPtr galaxy = createActionStateLabelPanel(
        player::View::Galaxy,
        std::string("Galaxy"),
        colors,
        model
      );
      ActionProviderLabelStateContainerShPtr alliance = createActionStateLabelPanel(
        player::View::Alliance,
        std::string("Alliance"),
        colors,
        model
      );

      if (overview == nullptr ||
          resources == nullptr ||
          facilities == nullptr ||
          research == nullptr ||
          shipyard == nullptr ||
          defense == nullptr ||
          fleet == nullptr ||
          galaxy == nullptr ||
          alliance == nullptr)
      {
        throw GuiException(std::string("Could not create one or more component for menu view"));
      }

      overview->setState(StateContainer::State::Selected);

      addChild(overview);
      addChild(resources);
      addChild(facilities);
      addChild(research);
      addChild(shipyard);
      addChild(defense);
      addChild(fleet);
      addChild(galaxy);
      addChild(alliance);
    }

  }
}
