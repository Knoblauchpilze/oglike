
#include "GalaxyView.h"
#include "LinearLayout.h"
#include "GuiException.h"
#include "PlanetGalaxyEntry.h"
#include "SystemException.h"

namespace ogame {
  namespace gui {

    GalaxyView::GalaxyView(const unsigned& planetCount):
      view::GraphicContainer(std::string("Galaxy view"),
                             view::utils::Area(),
                             view::EventListener::Interaction::MouseButton,
                             std::make_shared<view::LinearLayout>(view::LinearLayout::Direction::Vertical,
                                                                  0.0f,
                                                                  1.0f,
                                                                  this)),
      m_planetsPanel()
    {
      createView(planetCount);
    }

    GalaxyView::~GalaxyView() {}

    void GalaxyView::populateWithSystemData(const core::System& system) {
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
    }

    void GalaxyView::createView(const unsigned& planetCount) {
      // Create each row.
      for (int indexPlanet = 0 ; indexPlanet < planetCount ; ++indexPlanet) {
        // Create the planet panel.
        try {
          view::GraphicContainerShPtr planetPanel = createPlanetPanel(indexPlanet, planetCount);

          // Add it as a child of this view (to be able to propagate events): it will automatically added to the layout.
          addChild(planetPanel);

          // Save it for further use.
          m_planetsPanel.push_back(planetPanel);
        }
        catch (const GuiException& e) {
          std::cerr << "[GALAXY] Could not create planet " << indexPlanet + 1 << "'s panel, galaxy view may be wrong:" << std::endl << e.what() << std::endl;
        }
      }
    }

  }
}
