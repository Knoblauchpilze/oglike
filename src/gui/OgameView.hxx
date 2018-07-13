#ifndef OGAMEVIEW_HXX
#define OGAMEVIEW_HXX

#include "OgameView.h"
#include "GuiException.h"
#include "Planet.h"
#include "PlanetException.h"

namespace ogame {
  namespace gui {

    inline
    void OgameView::onActionTriggered(const player::DataModel& model) {
      // Update each view.
      try {
        const core::Planet& planet = model.getActivePlanet();
        m_galaxyView->populateWithSystemData(planet.getSystem());
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[OGAME] Caught exception while setting up general view:" << std::endl << e.what() << std::endl;
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[OGAME] Caught exception while setting up general view:" << std::endl << e.what() << std::endl;
      }
    }

    inline
    void OgameView::createMainPanel(const float& margin) {
      // Create the main panel in which views will be displayed.
      m_panel = std::make_shared<view::GraphicContainer>(
        std::string("Panel 0"),
        view::utils::Area(margin,
                          margin,
                          static_cast<float>(getWidth()) - 2.0f * margin,
                          static_cast<float>(getHeight()) - 2.0f * margin),
        view::EventListener::Interaction::MouseButton
      );

      // Check that the creation was successful.
      if (m_panel == nullptr) {
        throw GuiException(std::string("Could not create main panel used for display"));
      }

      // Add main panel to drawables.
      addDrawable(m_panel.get());

      // Add main panel to listeners.
      addListener(m_panel.get());
    }

  }
}

#endif // OGAMEVIEW_HXX
