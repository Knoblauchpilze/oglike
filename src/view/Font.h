#ifndef FONT_H
#define FONT_H

#include <memory>
#include <SDL/SDL_ttf.h>

namespace ogame {
  namespace view {

    class Font
    {
      public:

        explicit Font(const std::string& name, const int& size = 25);

        explicit Font(const Font& other);

        virtual ~Font();

        const std::string& getName() const noexcept;

        const int& getSize() const noexcept;

        void setName(const std::string& name);

        void setSize(const int& size);

        SDL_Surface* render(const std::string text, const SDL_Color& color);

      private:

        const bool loaded() const noexcept;

        void load();

        void unload();

        void initializeTTFLib();

      private:

        std::string m_name;
        int m_size;
        TTF_Font* m_font;

    };

    using FontShPtr = std::shared_ptr<Font>;
  }
}

#include "Font.hxx"

#endif // FONT_H
