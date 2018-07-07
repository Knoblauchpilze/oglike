#ifndef OGAMEVIEW_H
#define OGAMEVIEW_H

#include <memory>
#include <unordered_map>
#include <SDL/SDL.h>
#include "OgameAbstractView.h"
#include "System.h"
#include "GraphicContainer.h"
#include "GalaxyView.h"
#include "SelectorPanel.h"

namespace ogame {
  namespace gui {

    class OgameView: public view::OgameAbstractView
    {
      public:

        OgameView(const unsigned& width,
                  const unsigned& height,
                  const unsigned& galaxyCount,
                  const unsigned& systemCount,
                  const unsigned& planetCount);
        
        virtual ~OgameView();

        void populateGalaxyView(const core::System& system);

      private:

          void initializeTTFLib();

          void createMainPanel(const float& margin);

          void createViews(const float& margin,
                           const unsigned& galaxyCount,
                           const unsigned& systemCount,
                           const unsigned& planetCount);

          void createMainLayout();

          view::GraphicContainerShPtr createGraphicContainer(const std::string& name) const;

          void createThematicViews(const unsigned& galaxyCount,
                                   const unsigned& systemCount,
                                   const unsigned& planetCount);

      private:

        // Main panel.
        view::GraphicContainerShPtr m_panel;
        // Left view (i.e. toggle between main views)
        view::GraphicContainerShPtr m_menuView;
        // Upper view to access highscores, options...)
        view::GraphicContainerShPtr m_optionsView;
        // Upper view to display the resource of the current planet
        view::GraphicContainerShPtr m_resourcesView;
        // The list of the planets for this user.
        view::GraphicContainerShPtr m_planetsView;
        // The main view displayed.
        SelectorPanelShPtr m_generalView;

        // Galaxy view display.
        GalaxyViewShPtr m_galaxyView;

    };

    using OgameViewShPtr = std::shared_ptr<OgameView>;
  }
}

#include "OgameView.hxx"

#endif // OGAMEVIEW_H
