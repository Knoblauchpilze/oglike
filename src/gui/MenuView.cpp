
#include "MenuView.h"
#include "LinearLayout.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    MenuView::MenuView(const std::string& name, player::DataModel* model, const player::DataModel::View& initialView):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             std::make_shared<view::LinearLayout>(
                               view::LinearLayout::Direction::Vertical,
                               0.0f,
                               0.0f,
                               this
                             )),
      player::ActionListener(player::ActionListener::Action::ChangeView, model),
      m_highlightedView(initialView)
    {
      setBackgroundColor(SDL_Color{29, 34, 40, SDL_ALPHA_OPAQUE});

      createView();
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
      StateLabelContainerShPtr overview = createStateLabelPanel(player::DataModel::View::Overview, std::string("Overview"), colors);
      StateLabelContainerShPtr resources = createStateLabelPanel(player::DataModel::View::Resources, std::string("Resources"), colors);
      StateLabelContainerShPtr facilities = createStateLabelPanel(player::DataModel::View::Facilities, std::string("Facilities"), colors);
      StateLabelContainerShPtr research = createStateLabelPanel(player::DataModel::View::Research, std::string("Research"), colors);
      StateLabelContainerShPtr shipyard = createStateLabelPanel(player::DataModel::View::Shipyard, std::string("Shipyard"), colors);
      StateLabelContainerShPtr defense = createStateLabelPanel(player::DataModel::View::Defense, std::string("Defense"), colors);
      StateLabelContainerShPtr fleet = createStateLabelPanel(player::DataModel::View::Fleet, std::string("Fleet"), colors);
      StateLabelContainerShPtr galaxy = createStateLabelPanel(player::DataModel::View::Galaxy, std::string("Galaxy"), colors);
      StateLabelContainerShPtr alliance = createStateLabelPanel(player::DataModel::View::Alliance, std::string("Alliance"), colors);

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

  }
}
