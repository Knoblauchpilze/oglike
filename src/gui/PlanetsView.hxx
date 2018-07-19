#ifndef PLANETSVIEW_HXX
#define PLANETSVIEW_HXX

#include "PlanetsView.h"

namespace ogame {
  namespace gui {

    inline
    PlanetViewLinkShPtr PlanetsView::createPlanetView(const unsigned& index) const {
      return std::make_shared<PlanetViewLink>(computePlanetPanelNameFromIndex(index), m_planetCount, m_colors);
    }

    inline
    PlanetViewLink* PlanetsView::getOrCreatePlanetView(const unsigned& index) {
      // Don't forget the planets count information label
      if (getChildCount() - 1u <= index) {
        // We need to create a new child.
        PlanetViewLinkShPtr planetView = createPlanetView(index);

        // Add this panel to the layout.
        addChild(planetView, 0u, 1u + 2u * index, 1u, 2u);

        // Return this panel.
        return planetView.get();
      }
      // Return the corresponding child.
      return getChild<PlanetViewLink*>(computePlanetPanelNameFromIndex(index));
    }

    inline
    std::string PlanetsView::computePlanetPanelNameFromIndex(const unsigned& index) const noexcept {
      return std::string("planet_") + std::to_string(index) + "_panel";
    }

  }
}

#endif // PLANETSVIEW_HXX
