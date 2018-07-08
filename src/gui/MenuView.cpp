
#include "MenuView.h"
#include "LinearLayout.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    MenuView::MenuView(const std::string& name, const View& initialView):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             std::make_shared<view::LinearLayout>(
                               view::LinearLayout::Direction::Vertical,
                               0.0f,
                               0.0f,
                               this
                             )),
      m_highlightedView(initialView)
    {
      setBackgroundColor(SDL_Color{29, 34, 40, SDL_ALPHA_OPAQUE});

      createView();
      highlightViewPrivate(initialView, false);
    }

    MenuView::~MenuView() {}

    void MenuView::createView() {
      // Add each option.
      LabelContainerShPtr overview = createLabelPanel(View::Overview, std::string("Overview"));
      LabelContainerShPtr resources = createLabelPanel(View::Resources, std::string("Resources"));
      LabelContainerShPtr facilities = createLabelPanel(View::Facilities, std::string("Facilities"));
      LabelContainerShPtr research = createLabelPanel(View::Research, std::string("Research"));
      LabelContainerShPtr shipyard = createLabelPanel(View::Shipyard, std::string("Shipyard"));
      LabelContainerShPtr defense = createLabelPanel(View::Defense, std::string("Defense"));
      LabelContainerShPtr fleet = createLabelPanel(View::Fleet, std::string("Fleet"));
      LabelContainerShPtr galaxy = createLabelPanel(View::Galaxy, std::string("Galaxy"));
      LabelContainerShPtr alliance = createLabelPanel(View::Alliance, std::string("Alliance"));

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
