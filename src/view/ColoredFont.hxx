#ifndef COLOREDFONT_HXX
#define COLOREDFONT_HXX

#include "ColoredFont.h"

namespace ogame {
  namespace view {

    inline
    SDL_Surface* ColoredFont::render(const std::string text) {
      return m_fontPtr->render(text, m_color);
    }

  }
}

#endif // COLOREDFONT_HXX
