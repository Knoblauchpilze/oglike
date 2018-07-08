#ifndef GALAXYVIEW_H
#define GALAXYVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "System.h"
#include "PlanetGalaxyEntry.h"

namespace ogame {
  namespace gui {

    class GalaxyView: public view::GraphicContainer
    {
      public:

        GalaxyView(const unsigned& galaxyCount,
                   const unsigned& systemCount,
                   const unsigned& planetCount);

        virtual ~GalaxyView();

        void populateWithSystemData(const core::System& system);

      private:

        void createView(const unsigned& navigationHeight,
                        const unsigned& galaxyCount,
                        const unsigned& systemCount,
                        const unsigned& planetCount);

        PlanetGalaxyEntryShPtr createPlanetPanel(const unsigned& planetIndex, const unsigned& planetCount) const;

        std::string getNameOfPlanetPanelFromIndex(const unsigned& planetIndex) const noexcept;

      private:

    };

    using GalaxyViewShPtr = std::shared_ptr<GalaxyView>;
  }
}

#include "GalaxyView.hxx"

#endif // GALAXYVIEW_H
