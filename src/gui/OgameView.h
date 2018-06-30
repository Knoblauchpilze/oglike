#ifndef OGAMEVIEW_H
#define OGAMEVIEW_H

#include <memory>
#include <unordered_map>
#include <SDL/SDL.h>
#include "OgameAbstractView.h"
#include "LinearLayout.h"
#include "System.h"
#include "GalaxyView.h"

namespace ogame {
  namespace gui {

    class OgameView: public view::OgameAbstractView
    {
      public:

        OgameView(const unsigned& width,
                  const unsigned& height,
                  const unsigned& planetCount);
        
        virtual ~OgameView();

        void populateGalaxyView(const core::System& system);

      private:

          void initializeTTFLib();

          void createViews(const float& margin, const unsigned& planetCount);

          void createGalaxyView(const unsigned& planetCount);

      private:

        view::GraphicContainerShPtr m_panel;
        GalaxyViewShPtr m_galaxyView;

    };

    using OgameViewShPtr = std::shared_ptr<OgameView>;
  }
}

#include "OgameView.hxx"

#endif // OGAMEVIEW_H
