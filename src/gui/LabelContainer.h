#ifndef LABELCONTAINER_H
#define LABELCONTAINER_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "ColoredFont.h"

namespace ogame {
  namespace gui {

    class LabelContainer: public view::GraphicContainer
    {
      public:

        LabelContainer(const std::string& name,
                       const std::string& text,
                       view::ColoredFontShPtr font,
                       const SDL_Color& bgColor = SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE},
                       const bool transparent = true);

        virtual ~LabelContainer();

        const std::string getText() const noexcept;

        void setText(const std::string& text);

      protected:

        SDL_Surface* createContentPrivate() override;

        void clearContentPrivate(SDL_Surface* render) override;

      private:

        void clearText();

        // We assume that the font is loaded before entering this method.
        void createText();

        SDL_Surface* createTextFromFont(const std::string& text, view::ColoredFontShPtr font);

      private:

        bool m_textChanged;
        std::string m_text;

        bool m_fontChanged;
        view::ColoredFontShPtr m_font;

        bool m_highlightChanged;
        SDL_Surface* m_textSurface;

    };

    using LabelContainerShPtr = std::shared_ptr<LabelContainer>;
  }
}

#include "LabelContainer.hxx"

#endif // LABELCONTAINER_H
