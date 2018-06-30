#ifndef OGAMEVIEW_HXX
#define OGAMEVIEW_HXX

#include "OgameView.h"
#include <SDL/SDL_ttf.h>

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

  }
}

#endif // OGAMEVIEW_HXX
