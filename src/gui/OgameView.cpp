
#include "OgameView.h"
#include "GuiException.h"
#include "GalaxyView.h"

namespace ogame {
  namespace gui {

    OgameView::OgameView(const unsigned& width,
                         const unsigned& height,
                         const unsigned& galaxyCount,
                         const unsigned& systemCount,
                         const unsigned& planetCount):
      OgameAbstractView(std::string("Ogame is life and ya know it !"),
                        std::string("data/icon.bmp"),
                        width,
                        height),
      m_panel(nullptr)
    {
      // Initialize the TTF lib.
      initializeTTFLib();

      // Create views.
      createViews(1.0f, galaxyCount, systemCount, planetCount);
    }

    OgameView::~OgameView() {
      // Nothing to do.
    }

    void OgameView::createViews(const float& margin,
                                const unsigned& galaxyCount,
                                const unsigned& systemCount,
                                const unsigned& planetCount)
    {
      // Create the main panel in which views will be displayed.
      m_panel = std::make_shared<view::GraphicContainer>(
        std::string("Panel 0"),
        view::utils::Area(margin,
                          margin,
                          static_cast<float>(getWidth()) - 2.0f * margin,
                          static_cast<float>(getHeight()) - 2.0f * margin),
        view::EventListener::Interaction::MouseButton,
        std::make_shared<view::LinearLayout>(view::LinearLayout::Direction::Vertical,
                                             0.0f,
                                             0.0f,
                                             nullptr),
        nullptr
      );
      if (m_panel == nullptr) {
        throw GuiException(std::string("Could not create main panel used for display"));
      }
      // Add main panel to drawables.
      addDrawable(m_panel.get());

      // Add main panel to listeners.
      addListener(m_panel.get());

      // Create each view.
      createGalaxyView(galaxyCount, systemCount, planetCount);
    }

    void OgameView::createGalaxyView(const unsigned& galaxyCount,
                                     const unsigned& systemCount,
                                     const unsigned& planetCount)
    {
      // Create the view.
      m_galaxyView = std::make_shared<GalaxyView>(galaxyCount, systemCount, planetCount);

      // Add it as a child of the main panel for event propagation purposes.
      m_panel->addChild(m_galaxyView);
    }

  }
}

