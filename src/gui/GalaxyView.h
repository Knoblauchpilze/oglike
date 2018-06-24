#ifndef GALAXYVIEW_H
#define GALAXYVIEW_H

#include <memory>
#include <vector>
#include <SDL/SDL.h>
#include "GraphicContainer.h"

namespace ogame {
  namespace gui {

    class GalaxyView: public view::GraphicContainer
    {
      public:

        GalaxyView(const unsigned& planetCount);
        
        virtual ~GalaxyView();

      private:

        void createView(const unsigned& planetCount);

        view::GraphicContainerShPtr createPlanetPanel(const unsigned& planetIndex) const;

      private:

        std::vector<view::GraphicContainerShPtr> m_planetsPanel;

    };

    using GalaxyViewShPtr = std::shared_ptr<GalaxyView>;
  }
}

#endif // GALAXYVIEW_H
