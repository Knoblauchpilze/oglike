#ifndef FONT_H
#define FONT_H

#include <memory>
#include <SDL/SDL_ttf.h>
#include "Layout.h"

namespace ogame {
  namespace view {

    class Font
    {
      public:

        explicit Font(const std::string& name, const SDL_Color& color, const int& size = 25);

        explicit Font(const std::string& name,
                      const int& r,
                      const int& g,
                      const int& b,
                      const int& a,
                      const int& size = 25);

        virtual ~Font();

        const std::string& getName() const noexcept;

        const SDL_Color& getColor() const noexcept;

        const int& getSize() const noexcept;

        void setName(const std::string& name);

        void setColor(const SDL_Color& color);

        void setSize(const int& size);

        SDL_Surface* render(const std::string text);

      private:

        const bool loaded() const noexcept;

        void load();

        void unload();

        void initializeTTFLib();

      private:

        std::string m_name;
        SDL_Color m_color;
        int m_size;
        TTF_Font* m_font;

    };

    using FontShPtr = std::shared_ptr<Font>;
  }
}

#include "Font.hxx"

#endif // FONT_H
