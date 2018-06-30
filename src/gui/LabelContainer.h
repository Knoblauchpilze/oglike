#ifndef LABELCONTAINER_H
#define LABELCONTAINER_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "GraphicContainer.h"

namespace ogame {
  namespace gui {

    class LabelContainer: public view::GraphicContainer
    {
      public:

        LabelContainer(const std::string& text,
                       const SDL_Color& color,
                       const std::string& font,
                       const std::string& name,
                       const int& fontSize = 25);
        
        virtual ~LabelContainer();

        const std::string& getText() const noexcept;

        const SDL_Color& getTextColor() const noexcept;

        const std::string& getFont() const noexcept;

        const int& getFontSize() const noexcept;

        void setText(const std::string& text);

        void setTextColor(const SDL_Color& color);

        void setFont(const std::string& font);

        void setFontSize(const int& size);

      protected:

        SDL_Surface* createContentPrivate() override;

        void clearContentPrivate(SDL_Surface* render) override;

      private:

        void loadFont();

        void clearFont();

        void clearText();

        // We assume that the font is loaded before entering this method.
        void createText();

      private:

        bool m_textChanged;
        std::string m_text;
        SDL_Color m_textColor;
        bool m_fontChanged;
        std::string m_fontName;
        TTF_Font* m_font;
        int m_size;
        SDL_Surface* m_textSurface;

    };

    using LabelContainerShPtr = std::shared_ptr<LabelContainer>;
  }
}

#include "LabelContainer.hxx"

#endif // LABELCONTAINER_H
