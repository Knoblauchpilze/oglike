
#include "OgameView.h"
#include "ViewException.h"

namespace ogame {
  namespace view {

    OgameView::OgameView(const unsigned& width, const unsigned& height):
      OgameAbstractView(std::string("Ogame is life and ya know it !"),
                        std::string("65px-Stop_hand.svg[1].BMP"),
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
      m_panel = std::make_shared<GraphicContainer>(
        std::string("Panel 0"),
        utils::Area(margin,
                    margin,
                    static_cast<float>(getWidth()) - 2.0f * margin,
                    static_cast<float>(getHeight()) - 2.0f * margin),
        EventListener::Interaction::MouseButton,
        nullptr,
        nullptr
      );
      if (m_panel == nullptr) {
        throw ViewException(std::string("Could not create main panel used for display"));
      }
      // Add main panel to drawables.
      addDrawable(m_panel.get());

      // Add main panel to listeners.
      addListener(m_panel.get());
    }

  }
}

