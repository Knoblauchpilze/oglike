#ifndef PLANETSVIEW_H
#define PLANETSVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "PlanetViewLink.h"
#include "Planet.h"

namespace ogame {
  namespace gui {

    class PlanetsView: public view::GraphicContainer
    {
      public:

        PlanetsView(const std::string& name,
                    const unsigned& planetCount,
                    const std::vector<core::Planet>& planets = std::vector<core::Planet>());

        virtual ~PlanetsView();

        void populateWithPlayerData(/* TODO */);

      private:

        void createView(const unsigned& planetCount,
                        const std::vector<core::Planet>& planets);

        PlanetViewLinkShPtr createPlanetView(const std::string& name, const unsigned& planetCount) const;

      private:

    };

    using PlanetsViewShPtr = std::shared_ptr<PlanetsView>;
  }
}

#include "PlanetsView.hxx"

#endif // PLANETSVIEW_H
