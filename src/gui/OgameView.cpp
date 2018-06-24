
#include "OgameView.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    OgameView::OgameView(const unsigned& width, const unsigned& height):
      OgameAbstractView(std::string("Ogame is life and ya know it !"),
                        std::string("data/icon.bmp"),
                        width,
                        height),
      m_panel(nullptr),
      m_views()
    {
      createViews(1.0f);
    }

    OgameView::~OgameView() {
      // Nothing to do.
    }

    void OgameView::createViews(const float& margin) {
      // Create the main panel in which views will be displayed.
      m_panel = std::make_shared<view::GraphicContainer>(
        std::string("Panel 0"),
        view::utils::Area(margin,
                          margin,
                          static_cast<float>(getWidth()) - 2.0f * margin,
                          static_cast<float>(getHeight()) - 2.0f * margin),
        view::EventListener::Interaction::MouseButton,
        nullptr,
        nullptr
      );
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

