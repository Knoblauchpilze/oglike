#ifndef OGAMEVIEW_H
#define OGAMEVIEW_H

#include <memory>
#include <unordered_map>
#include <SDL/SDL.h>
#include "OgameAbstractView.h"
#include "System.h"
#include "Planet.h"
#include "GraphicContainer.h"
#include "GalaxyView.h"
#include "SelectorPanel.h"
#include "MenuView.h"
#include "ResourcesView.h"
#include "OptionsView.h"
#include "PlanetsView.h"
#include "DataModel.h"

namespace ogame {
  namespace gui {

    class OgameView: public view::OgameAbstractView
    {
      public:

        OgameView(const unsigned& width,
                  const unsigned& height,
                  const unsigned& galaxyCount,
                  const unsigned& systemCount,
                  const unsigned& planetCount,
                  player::DataModelShPtr dataModel);

        virtual ~OgameView();

        void populateGalaxyView(const core::System& system);

        void populateResourcesView(const core::Planet& planet);

        void populateOptionsView(const core::Account& account);

      private:

          void createMainPanel(const float& margin);

          void createViews(const float& margin,
                           const unsigned& galaxyCount,
                           const unsigned& systemCount,
                           const unsigned& planetCount);

          void createMainLayout();

          void createThematicViews(const unsigned& galaxyCount,
                                   const unsigned& systemCount,
                                   const unsigned& planetCount);

          void connectDataModel(player::DataModelShPtr dataModel);

      private:

        // Main panel.
        view::GraphicContainerShPtr m_panel;
        // Left view (i.e. toggle between main views)
        MenuViewShPtr m_menuView;
        // Upper view to access highscores, options...)
        OptionsViewShPtr m_optionsView;
        // Upper view to display the resource of the current planet
        ResourcesViewShPtr m_resourcesView;
        // The list of the planets for this user.
        PlanetsViewShPtr m_planetsView;
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
