
#include "PlanetsView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    PlanetsView::PlanetsView(const std::string& name,
                             const unsigned& planetCount,
                             const std::vector<core::Planet>& planets):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction)
    {
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});

      createView(planetCount, planets);
    }

    PlanetsView::~PlanetsView() {}

    void PlanetsView::populateWithPlayerData(/* TODO */) {}

    void PlanetsView::createView(const unsigned& planetCount,
                                 const std::vector<core::Planet>& planets)
    {
      // Create the main layout.
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(1u, 2u * planetCount + 1u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not create layout for container" ) + getName());
      }

      // Informative panel.
      LabelContainerShPtr info = ComponentFactory::createLabelPanel(
        std::string("planet_count_info_panel"),
        std::to_string(planets.size()) + "/" + std::to_string(planetCount) + " planet" + (planetCount > 1 ? "s" : ""),
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/times.ttf"),
          85, 126, 148, SDL_ALPHA_OPAQUE,
          15
        )
      );

      if (info == nullptr) {
        throw GuiException(std::string("Could not create informative panel for planets count in ") + getName());
      }
      layout->addItem(info, 0u, 0u, 1u, 1u);
      addChild(info);


      // Create each planet data.
      for (unsigned indexPlanet = 0u ; indexPlanet < planets.size() ; ++indexPlanet) {
        try {
          PlanetViewLinkShPtr planet = createPlanetView(std::string("planet_") + std::to_string(indexPlanet) + "_panel", planetCount);
          if (planet != nullptr) {
            // Update the data.
            planet->populateWithPlanetData(planets[indexPlanet]);

            // Add this item to the layout and to the panel.
            layout->addItem(planet, 0u, 1u + 2u * indexPlanet, 1u, 2u);
            addChild(planet);
          }
        }
        catch (const GuiException& e) {
          std::cerr << "[PLANETS] Could not create image for planet " << indexPlanet << ":" << std::endl << e.what() << std::endl;
        }
      }

      setLayout(layout);
    }

  }
}
