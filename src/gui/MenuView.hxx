#ifndef MENUVIEW_HXX
#define MENUVIEW_HXX

#include "MenuView.h"
#include "ComponentFactory.h"
#include "FontFactory.h"
#include "DataModelException.h"

namespace ogame {
  namespace gui {

    inline
    ActionProviderLabelStateContainerShPtr MenuView::createActionStateLabelPanel(const player::View& view,
                                                                                 const std::string& text,
                                                                                 const StateContainer::StateAssociation& colors,
                                                                                 player::GeneralDataModel* model) const
    {
      return ComponentFactory::createActionProviderLabelStatePanel(
        getChildNameFromView(view),
        text,
        view,
        model,
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
