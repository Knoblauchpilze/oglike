#ifndef MENUVIEW_HXX
#define MENUVIEW_HXX

#include "MenuView.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    void MenuView::highlightView(const View& view) {
      highlightViewPrivate(view, true);
    }

    inline
    LabelContainerShPtr MenuView::createLabelPanel(const View& view, const std::string& text) const {
      return ComponentFactory::createLabelPanel(
        getChildNameFromView(view),
        text,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/tahomabd.ttf"),
          128, 128, 128
        ),
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/tahomabd.ttf"),
          255, 255, 255
        )
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

    inline
    void MenuView::highlightViewPrivate(const View& view, const bool smartHighlight) {
      lock();

      // Highlight only if the view is not already highlighted or if we want to force the highlight.
      if (view != m_highlightedView || !smartHighlight) {
        // Reset the selected node.
        if (view != m_highlightedView) {
          const std::string name = getChildNameFromView(m_highlightedView);
          LabelContainer* view = getChild<LabelContainer*>(name);
          if (checkChild(view, name)) {
            view->unhighlight();
          }
        }

        // Highlight the new view.
        const std::string name = getChildNameFromView(view);
        LabelContainer* hView = getChild<LabelContainer*>(name);
        if (checkChild(hView, name)) {
          hView->highlight();
        }

        // This is the new highlighted view.
        m_highlightedView = view;

        makeDirty();
      }

      unlock();
    }

  }
}

#endif // MENUVIEW_HXX
