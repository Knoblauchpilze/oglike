#ifndef BACKGROUNDEDLABEL_H
#define BACKGROUNDEDLABEL_H

#include <memory>
#include <string>
#include <SDL/SDL.h>

#include "ColoredFont.h"
#include "PictureContainer.h"

namespace ogame {
  namespace gui {

    class BackgroundedLabel: public PictureContainer
    {
      public:

        // Describe the position of the label above the picture.
        enum class Alignment {
          BottomLeft,
          BottomRight,
          TopLeft,
          TopRight
        };

        BackgroundedLabel(const std::string& name,
                          view::ColoredFontShPtr font,
                          const std::string& picture,
                          const std::string& text = std::string(),
                          const SDL_Color& textBackgroundColor = SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE},
                          const Alignment& alignment = Alignment::BottomRight,
                          const view::EventListener::Interaction::Mask& mask = view::EventListener::Interaction::NoInteraction);

        virtual ~BackgroundedLabel();

        void setText(const std::string& text);

      protected:

        SDL_Surface* createContentPrivate() override;

        void clearContentPrivate(SDL_Surface* render) override;

      private:

        void clearText();

        // We assume that the font is loaded before entering this method.
        void createText();

        SDL_Surface* createTextFromFont(const std::string& text, view::ColoredFontShPtr font);

        SDL_Rect computeBlitPosition(const unsigned& displayWidth, const unsigned& displayHeight) const noexcept;

      private:

        Alignment m_alignment;

        bool m_textChanged;
        std::string m_text;

        SDL_Color m_textBackgroundColor;

        view::ColoredFontShPtr m_font;

        SDL_Surface* m_textSurface;

    };

    using BackgroundedLabelShPtr = std::shared_ptr<BackgroundedLabel>;
  }
}

#include "BackgroundedLabel.hxx"

#endif // BACKGROUNDEDLABEL_H
