
#include "PlanetsView.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "ComponentFactory.h"
#include "FontFactory.h"
#include "GridLayout.h"

namespace ogame {
  namespace gui {

    PlanetsView::PlanetsView(const std::string& name,
                             player::GeneralDataModel* model,
                             const unsigned& planetCount,
                             const std::vector<core::Planet>& planets):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             false),
      player::GeneralActionListener(model),
      m_planetCount(planetCount)
    {
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});

      createView(planets);
    }

    PlanetsView::~PlanetsView() {}

    void PlanetsView::onActionTriggered(const player::GeneralDataModel& model) {
      lock();

      // Update each planet.
      try {
        const core::Account& account = model.getActiveAccount();

        LabelContainer* planetCount = getChild<LabelContainer*>(std::string("planet_count_info_panel"));
        if (checkChild(planetCount, std::string("Planet count information"))) {
          planetCount->setText(
            std::to_string(account.getOccupiedPlanetsSlots()) +
            "/" +
            std::to_string(account.getAvailablePlanetsSlots()) +
            " planet" + (account.getAvailablePlanetsSlots() > 1 ? "s" : "")
          );
        }

        if (account.getOccupiedPlanetsSlots() > m_planetCount) {
          std::cerr << "[PLANETS] Planets view will not be able to display " << account.getOccupiedPlanetsSlots() << " planets for player " << account.getPlayerName() << std::endl;
        }

        const std::vector<core::Planet*>& planets = account.getPlanets();
        // const core::Planet& activePlanet = model.getActivePlanet();
        // TODO: Highlight active planet

        view::GridLayout* grid = getLayout<view::GridLayout*>();
        if (!checkLayout(grid, "grid layout")) {
          throw GuiException(std::string("Could not retrieve grid layout to update planets view, this view may be incorrect"));
        }
        grid->setGrid(1u, 2u * m_planetCount + 1u);

        for (unsigned indexPlanet = 0u ; indexPlanet < planets.size() && indexPlanet < m_planetCount ; ++indexPlanet) {
          PlanetViewLink* planet = getOrCreatePlanetView(indexPlanet);
          if (planet == nullptr) {
            std::cerr << "[PLANETS] Coult not render planet link " << indexPlanet << ", planets view may be incorrect" << std::endl;
          }
          else {
            planet->populateWithPlanetData(*planets[indexPlanet]);
          }
        }

      }
      catch (const player::DataModelException& e) {
        std::cerr << "[PLANETS] Caught exception while setting planets information:" << std::endl << e.what() << std::endl;
      }
      catch (const GuiException& e) {
        std::cerr << "[PLANETS] Caught exception while setting planets information:" << std::endl << e.what() << std::endl;
      }

      makeDeepDirty();
      unlock();
    }

    void PlanetsView::createView(const std::vector<core::Planet>& planets)
    {
      // Create the main layout.
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(1u, 2u * m_planetCount + 1u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not create layout for container" ) + getName());
      }

      // Informative panel.
      LabelContainerShPtr info = ComponentFactory::createLabelPanel(
        std::string("planet_count_info_panel"),
        std::to_string(planets.size()) + "/" + std::to_string(m_planetCount) + " planet" + (m_planetCount > 1 ? "s" : ""),
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
          PlanetViewLinkShPtr planet = createPlanetView(indexPlanet);
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
