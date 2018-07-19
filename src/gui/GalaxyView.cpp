
#include "GalaxyView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "PlanetGalaxyEntry.h"
#include "SystemException.h"
#include "GalaxyNavigationPanel.h"

namespace ogame {
  namespace gui {

    GalaxyView::GalaxyView(const std::string& name,
                           const unsigned& galaxyCount,
                           const unsigned& systemCount,
                           const unsigned& planetCount,
                           player::GeneralDataModelShPtr model):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::MouseButton),
      player::GeneralActionListener(model.get())
    {
      createView(4u, galaxyCount, systemCount, planetCount, model);

      connectDataModel(model);
    }

    GalaxyView::~GalaxyView() {}

    void GalaxyView::createView(const unsigned& navigationHeight,
                                const unsigned& galaxyCount,
                                const unsigned& systemCount,
                                const unsigned& planetCount,
                                player::GeneralDataModelShPtr model)
    {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(1u, navigationHeight + planetCount, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create galaxy view"));
      }

      // Create the navigation panel.
      GalaxyNavigationPanelShPtr navigation = std::make_shared<GalaxyNavigationPanel>(
        std::string("navigation_panel"),
        galaxyCount,
        systemCount,
        model
      );
      if (navigation == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create galaxy view navigation panel"));
      }
      layout->addItem(navigation, 0u, 0u, 1u, navigationHeight);
      addChild(navigation);

      // Create each row.
      for (int indexPlanet = 0 ; indexPlanet < planetCount ; ++indexPlanet) {
        // Create the planet panel.
        try {
          view::GraphicContainerShPtr planetPanel = createPlanetPanel(indexPlanet, planetCount);

          // Add it as a child of this view (to be able to propagate events): it will automatically added to the layout.
          layout->addItem(planetPanel, 0u, navigationHeight + indexPlanet, 1u, 1u);
          addChild(planetPanel);
        }
        catch (const GuiException& e) {
          std::cerr << "[GALAXY] Could not create planet " << indexPlanet + 1 << "'s panel, galaxy view may be wrong:" << std::endl << e.what() << std::endl;
        }
      }

      setLayout(layout);
    }

    void GalaxyView::populateWithSystemData(const core::System& system) {
      lock();

      // Update the navigation view.
      GalaxyNavigationPanel* navigation = getChild<GalaxyNavigationPanel*>(std::string("navigation_panel"));
      if (checkChild(navigation, std::string("Navigation panel"))) {
        navigation->populateWithSystemData(system);
      }

      // Traverse the system and populate each panel.
      for (unsigned indexPlanet = 0u ; indexPlanet < system.getPlanetsCount() ; ++indexPlanet) {
        PlanetGalaxyEntry* planetPanel = getChild<PlanetGalaxyEntry*>(getNameOfPlanetPanelFromIndex(indexPlanet));
        if (planetPanel != nullptr) {
          try {
            planetPanel->populateWithPlanetData(system[indexPlanet]);
          }
          catch (const core::SystemException& e) {
            std::cerr << "[GALAXY] Caught system exception while updating galaxy view for system " << system.getIndex() << ":" << std::endl << e.what() << std::endl;
          }
          catch (const GuiException& e) {
            std::cerr << "[GALAXY] Caught internal exception while updating galaxy view for system " << system.getIndex() << ":" << std::endl << e.what() << std::endl;
          }
        }
      }

      makeDeepDirty();
      unlock();
    }

    void GalaxyView::connectDataModel(player::GeneralDataModelShPtr dataModel) {
      dataModel->registerForAction(player::Action::ChangeSystem, this);
      dataModel->registerForAction(player::Action::ChangeGalaxy, this);
    }

  }
}
