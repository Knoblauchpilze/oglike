#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <SDL/SDL.h>

namespace ogame {
  namespace view {

    class OgameView
    {
      public:

        OgameView(const unsigned& width, const unsigned& height);

        ~OgameView();

      private:

        void createScreen(const unsigned& width, const unsigned& height);

      private:

        SDL_Surface* m_screen;

    };

  }
}

#endif // MAINVIEW_H
