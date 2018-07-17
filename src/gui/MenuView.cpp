
#include "MenuView.h"
#include "LinearLayout.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    MenuView::MenuView(const std::string& name, player::DataModel* model, const player::View& initialView):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             std::make_shared<view::LinearLayout>(
                               view::LinearLayout::Direction::Vertical,
                               0.0f,
                               0.0f,
                               this
                             )),
      player::ActionListener(model),
      m_model(std::make_shared<player::DataModel>(std::string("menu_view_model"), initialView))
    {
      setBackgroundColor(SDL_Color{29, 34, 40, SDL_ALPHA_OPAQUE});

      createView();

      connectDataModel();
    }

    MenuView::~MenuView() {}

    void MenuView::createView() {
      // Create the colors for these state panels.
      const StateContainer::StateAssociation colors = {
        {StateContainer::State::Normal,       SDL_Color{29, 34, 40, SDL_ALPHA_OPAQUE}},
        {StateContainer::State::Highlighted,  SDL_Color{97, 154, 191, SDL_ALPHA_OPAQUE}},
        {StateContainer::State::Selected,     SDL_Color{97, 154, 191, SDL_ALPHA_OPAQUE}},
      };

      // Add each option.
      StateLabelContainerShPtr overview = createStateLabelPanel(player::View::Overview, std::string("Overview"), colors);
      StateLabelContainerShPtr resources = createStateLabelPanel(player::View::Resources, std::string("Resources"), colors);
      StateLabelContainerShPtr facilities = createStateLabelPanel(player::View::Facilities, std::string("Facilities"), colors);
      StateLabelContainerShPtr research = createStateLabelPanel(player::View::Research, std::string("Research"), colors);
      StateLabelContainerShPtr shipyard = createStateLabelPanel(player::View::Shipyard, std::string("Shipyard"), colors);
      StateLabelContainerShPtr defense = createStateLabelPanel(player::View::Defense, std::string("Defense"), colors);
      StateLabelContainerShPtr fleet = createStateLabelPanel(player::View::Fleet, std::string("Fleet"), colors);
      StateLabelContainerShPtr galaxy = createStateLabelPanel(player::View::Galaxy, std::string("Galaxy"), colors);
      StateLabelContainerShPtr alliance = createStateLabelPanel(player::View::Alliance, std::string("Alliance"), colors);

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

      galaxy->setState(StateContainer::State::Selected);

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

    void MenuView::connectDataModel() {
      // Register this component as a listener of the change view property.
      m_model->registerForAction(player::Action::ChangeView, this);
    }

  }
}
