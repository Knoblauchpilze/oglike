
#include "OgameView.h"
#include "ViewException.h"

namespace ogame {
  namespace view {

    OgameView::OgameView(const unsigned& width, const unsigned& height)
      //m_screen(nullptr)
    {
      createScreen(width, height);
    }

    OgameView::~OgameView() {
      // Nothing to do.
    }

    void OgameView::createScreen(const unsigned& width, const unsigned& height) {
      m_screen = SDL_CreateRGBSurface(0, width, height, 32, 0, 0, 0, 0);
      
      if (m_screen == nullptr) {
        const std::string errorMessage = std::string("Could not create screen with dimensions ") +
          std::to_string(width) + "x" + std::to_string(height);
        throw ViewException(errorMessage);
      }
    }

  }
}