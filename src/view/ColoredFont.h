#ifndef COLOREDFONT_H
#define COLOREDFONT_H

#include <memory>
#include <SDL/SDL_ttf.h>
#include "Font.h"

namespace ogame {
  namespace view {

    class ColoredFont
    {
      public:

        explicit ColoredFont(FontShPtr font, const int& r, const int& g, const int& b, const int& a = SDL_ALPHA_OPAQUE);

        explicit ColoredFont(const ColoredFont& other);

        virtual ~ColoredFont();

        SDL_Surface* render(const std::string text);

      private:

        FontShPtr m_fontPtr;
        SDL_Color m_color;

    };

    using ColoredFontShPtr = std::shared_ptr<ColoredFont>;
  }
}

#include "ColoredFont.hxx"

#endif // COLOREDFONT_H
