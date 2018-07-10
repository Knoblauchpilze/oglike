#ifndef MENUVIEW_HXX
#define MENUVIEW_HXX

#include "MenuView.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    StateLabelContainerShPtr MenuView::createStateLabelPanel(const View& view,
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
    std::string MenuView::getChildNameFromView(const View& view) const noexcept {
      std::string name;
      switch (view) {
        case View::Resources:
          name = "resources_view";
          break;
        case View::Facilities:
          name = "facilities_view";
          break;
        case View::Research:
          name = "research_view";
          break;
        case View::Shipyard:
          name = "shipyard_view";
          break;
        case View::Defense:
          name = "defense_view";
          break;
        case View::Fleet:
          name = "fleet_view";
          break;
        case View::Galaxy:
          name = "galaxy_view";
          break;
        case View::Alliance:
          name = "alliance_view";
          break;
        case View::Overview:
        default:
          name = "over_view";
          break;
      }
      return name;
    }

  }
}

#endif // MENUVIEW_HXX
