#ifndef OGAMEVIEW_HXX
#define OGAMEVIEW_HXX

#include "OgameView.h"
#include "GuiException.h"
#include "Planet.h"
#include "PlanetException.h"

namespace ogame {
  namespace gui {

    inline
    void OgameView::onActionTriggered(const player::GeneralDataModel& model) {
      // Process this action.
      try {
        const core::Planet* planet = model.getProperty<const core::Planet>(std::string("active_planet"));

        // Update each view.
        m_galaxyView->populateWithSystemData(planet->getSystem());

        // Update the main panel with the corresponding view.
        const std::string& activeView = getViewNameFromView(*model.getProperty<const player::View>(std::string("active_view")));

        m_generalView->setActiveChild(activeView);
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

    inline
    view::GraphicContainerShPtr OgameView::createGraphicContainer(const std::string& name) const {
      return std::make_shared<view::GraphicContainer>(
        name,
        view::utils::Area(),
        view::EventListener::Interaction::NoInteraction
      );
    }

    inline
    const std::string OgameView::getViewNameFromView(const player::View& view) const noexcept {
      std::string name;
      switch (view) {
        case player::View::Overview:
          name = "over_view";
          break;
        case player::View::Resources:
          name = "resources_view";
          break;
        case player::View::Facilities:
          name = "facilities_view";
          break;
        case player::View::Research:
          name = "research_view";
          break;
        case player::View::Shipyard:
          name = "shipyard_view";
          break;
        case player::View::Defense:
          name = "defens_view";
          break;
        case player::View::Fleet:
          name = "fleet_view";
          break;
        case player::View::Alliance:
          name = "alliance_view";
          break;
        case player::View::Galaxy:
        default:
          name = "galaxy_view";
          break;
      }

      return name;
    }

  }
}

#endif // OGAMEVIEW_HXX
