#ifndef LABELCONTAINER_H
#define LABELCONTAINER_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Font.h"

namespace ogame {
  namespace gui {

    class LabelContainer: public view::GraphicContainer
    {
      public:

        LabelContainer(const std::string& name,
                       const std::string& text,
                       view::FontShPtr font,
                       view::FontShPtr highlightFont);

        virtual ~LabelContainer();

        const std::string getText() const noexcept;

        void setText(const std::string& text);

        void setFont(view::FontShPtr font);

        void setHighlightFont(view::FontShPtr font);

        void highlight();

        void unhighlight();

      protected:

        SDL_Surface* createContentPrivate() override;

        void clearContentPrivate(SDL_Surface* render) override;

      private:

        void clearText();

        // We assume that the font is loaded before entering this method.
        void createText();

        SDL_Surface* createTextFromFont(const std::string& text, view::FontShPtr font);

      private:

        bool m_textChanged;
        std::string m_text;

        bool m_fontChanged;
        view::FontShPtr m_font;

        bool m_hFontChanged;
        view::FontShPtr m_hFont;

        bool m_highlightChanged;
        bool m_highlight;
        SDL_Surface* m_textSurface;

    };

    using LabelContainerShPtr = std::shared_ptr<LabelContainer>;
  }
}

#include "LabelContainer.hxx"

#endif // LABELCONTAINER_H
