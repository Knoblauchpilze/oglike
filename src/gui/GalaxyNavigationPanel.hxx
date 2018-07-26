#ifndef GALAXYNAVIGATIONPANEL_HXX
#define GALAXYNAVIGATIONPANEL_HXX

#include "GalaxyNavigationPanel.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    inline
    void GalaxyNavigationPanel::onActionTriggered(const player::GeneralDataModel& model) {
      try {
        const unsigned& galaxyCoord = model.getActiveGalaxyCoordinate();
        const unsigned& systemCoord = model.getActiveSystemCoordinate();
        const core::Account& account = model.getActiveAccount();
        const core::Planet& planet = model.getActivePlanet();
        const core::System& activeSystem = account.getSystem(core::SystemCoordinates(galaxyCoord, systemCoord));
        populateWithSystemData(activeSystem);
        populateWithPlanetData(planet);
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[NAVIGATION] Caught exception while setting up galaxy navigation panel:" << std::endl << e.what() << std::endl;
      }
    }

    inline
    void GalaxyNavigationPanel::onInteractionPerformed(const std::string& origin, const view::EventListener::Interaction::Mask& mask) {
      // Determine the origin of the event (either galaxy or system selector) and update the corresponding value in the data model.
      if (origin == std::string("galaxy_selector")) {
        // Retrieve the value from the galaxy selector
        ValueSelector* galaxySelector = getChild<ValueSelector*>(std::string("galaxy_selector"));
        if (checkChild(galaxySelector, std::string("Galaxy selector"))) {
          setActiveGalaxyCoordinate(galaxySelector->getActiveOption());
        }
      }
      else if (origin == std::string("system_selector")) {
        // Retrieve the value from the galaxy selector
        ValueSelector* systemSelector = getChild<ValueSelector*>(std::string("system_selector"));
        if (checkChild(systemSelector, std::string("System selector"))) {
          setActiveSystemCoordinate(systemSelector->getActiveOption());
        }
      }
      else {
        std::cerr << "[NAVIGATION] Caught interaction in " << getName() << " from unknown origin " << origin << std::endl;
      }
    }

    inline
    LabelContainerShPtr GalaxyNavigationPanel::createLabelPanel(const std::string& name,
                                                                const std::string& text,
                                                                view::ColoredFontShPtr font) const
    {
      return ComponentFactory::createLabelPanel(name, text, font);
    }

    inline
    ValueSelectorShPtr GalaxyNavigationPanel::createValueSelector(const std::string& name,
                                                                  player::GeneralDataModel* model,
                                                                  view::ColoredFontShPtr font,
                                                                  const std::vector<std::string>& options) const
    {
      return ComponentFactory::createValueSelectorPanel(name, model, font, options);
    }

  }
}

#endif // GALAXYNAVIGATIONPANEL_HXX
