#ifndef OGAMEVIEW_HXX
#define OGAMEVIEW_HXX

#include "OgameView.h"
#include <SDL/SDL_ttf.h>
#include "GuiException.h"

namespace ogame {
  namespace gui {

    inline
    void OgameView::populateGalaxyView(const core::System& system) {
      m_galaxyView->populateWithSystemData(system);
    }

    inline
    void OgameView::initializeTTFLib() {
      // Initialize the ttf lib.
      if (!TTF_WasInit() && TTF_Init() == -1) {
        throw GuiException(std::string("Unable to initialize TTF lib, cannot create view: ") + TTF_GetError());
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

  }
}

#endif // OGAMEVIEW_HXX
