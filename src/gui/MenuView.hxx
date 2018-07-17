#ifndef MENUVIEW_HXX
#define MENUVIEW_HXX

#include "MenuView.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    void MenuView::onActionTriggered(const player::DataModel& model) {
      // This slot is updated by internal children containers to update the active view.
      // We should propagate this information to the global data model.
      // First retrieve the active view based on the internal data model and set it as the new
      // active view of the global model.
      // In the meantime the data model will fire an action for the specified view so this is all good.
      setActiveView(model.getActiveView());
    }

    inline
    StateLabelContainerShPtr MenuView::createStateLabelPanel(const player::View& view,
                                                             const std::string& text,
                                                             const StateContainer::StateAssociation& colors) const
    {
      return ComponentFactory::createStateLabelPanel(
        getChildNameFromView(view),
        text,
        view,
        m_model.get(),
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/tahomabd.ttf"),
          128, 128, 128
        ),
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/tahomabd.ttf"),
          255, 255, 255
        ),
        colors
      );
    }

    inline
    std::string MenuView::getChildNameFromView(const player::View& view) const noexcept {
      std::string name;
      switch (view) {
        case player::View::Resources:
          name = "resources_view";
          break;
        case player::View::Facilities:
          name = "facilities_view";
          break;
        case player::View::Research:
          name = "research_view";
          break;
        case player::View::Shipyard:
          name = "shipyard_view";
          break;
        case player::View::Defense:
          name = "defense_view";
          break;
        case player::View::Fleet:
          name = "fleet_view";
          break;
        case player::View::Galaxy:
          name = "galaxy_view";
          break;
        case player::View::Alliance:
          name = "alliance_view";
          break;
        case player::View::Overview:
        default:
          name = "over_view";
          break;
      }
      return name;
    }

  }
}

#endif // MENUVIEW_HXX
