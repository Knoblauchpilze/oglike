#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <memory>
#include <SDL/SDL.h>

namespace ogame {
  namespace view {

    class OgameView
    {
      public:

        OgameView(const unsigned& width, const unsigned& height);

        ~OgameView();

        void launch();

      private:

        void createScreen(const unsigned& width, const unsigned& height);

      private:

        SDL_Surface* m_screen;

    };

    using OgameViewShPtr = std::shared_ptr<OgameView>;

  }
}

#endif // MAINVIEW_H
