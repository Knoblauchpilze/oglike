#ifndef MENUVIEW_HXX
#define MENUVIEW_HXX

#include "MenuView.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    void MenuView::onActionTriggered(const player::DataModel& model) {
      // No specific action should trigger the menu view.
    }

    inline
    StateLabelContainerShPtr MenuView::createStateLabelPanel(const player::DataModel::View& view,
                                                             const std::string& text,
                                                             const StateContainer::StateAssociation& colors) const
    {
      return ComponentFactory::createStateLabelPanel(
        getChildNameFromView(view),
        text,
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
    std::string MenuView::getChildNameFromView(const player::DataModel::View& view) const noexcept {
      std::string name;
      switch (view) {
        case player::DataModel::View::Resources:
          name = "resources_view";
          break;
        case player::DataModel::View::Facilities:
          name = "facilities_view";
          break;
        case player::DataModel::View::Research:
          name = "research_view";
          break;
        case player::DataModel::View::Shipyard:
          name = "shipyard_view";
          break;
        case player::DataModel::View::Defense:
          name = "defense_view";
          break;
        case player::DataModel::View::Fleet:
          name = "fleet_view";
          break;
        case player::DataModel::View::Galaxy:
          name = "galaxy_view";
          break;
        case player::DataModel::View::Alliance:
          name = "alliance_view";
          break;
        case player::DataModel::View::Overview:
        default:
          name = "over_view";
          break;
      }
      return name;
    }

  }
}

#endif // MENUVIEW_HXX
