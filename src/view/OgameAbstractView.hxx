#ifndef OGAMEABSTRACTVIEW_HXX
#define OGAMEABSTRACTVIEW_HXX

#include "OgameAbstractView.h"

namespace ogame {
  namespace view {

    inline
    void OgameAbstractView::addListener(EventListener* listener) {
      m_listeners.push_back(listener);
    }

    inline
    void OgameAbstractView::addDrawable(Drawable* drawable) {
      m_drawables.push_back(drawable);
    }

    inline
    void OgameAbstractView::run() {
      performRendering();
    }

    inline
    const int& OgameAbstractView::getWidth() const noexcept {
      return m_screen->w;
    }

    inline
    const int& OgameAbstractView::getHeight() const noexcept {
      return m_screen->h;
    }

    inline
    void OgameAbstractView::drawSurface(SDL_Surface* surface, SDL_Rect* sourceArea, SDL_Rect* destinationArea) {
      if (surface != nullptr) {
        SDL_BlitSurface(surface, sourceArea, m_screen, destinationArea);
      }
    }

  }
}

#endif // OGAMEABSTRACTVIEW_HXX
