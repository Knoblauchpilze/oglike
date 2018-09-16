
#include "BackgroundedLabel.h"
#include "ComponentFactory.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    BackgroundedLabel::BackgroundedLabel(const std::string& name,
                                         view::ColoredFontShPtr font,
                                         const std::string& picture,
                                         const std::string& text,
                                         const SDL_Color& textBackgroundColor,
                                         const Alignment& alignment,
                                         const view::EventListener::Interaction::Mask& mask):
      PictureContainer(name,
                       picture,
                       mask),
      m_alignment(alignment),

      m_textChanged(true),
      m_text(text),

      m_textBackgroundColor(textBackgroundColor),

      m_font(font),

      m_textSurface(nullptr)
    {
      // Nothing to do here.
    }

    BackgroundedLabel::~BackgroundedLabel() {}

    SDL_Surface* BackgroundedLabel::createContentPrivate() {
      // Use the base PictureContainer class to create the background image.
      SDL_Surface* croppedArea = PictureContainer::createContentPrivate();

      // Create the text to render.
      createText();

      // Check whether some text should be displayed.
      if (m_textSurface != nullptr) {
        // Compute the blit position of the picture so that it respects the alignment.
        SDL_Rect textBlitArea = computeBlitPosition(croppedArea->w, croppedArea->h);

        // Perform the blit operation (i.e. stick the text onto the rendering area).
        SDL_BlitSurface(m_textSurface, nullptr, croppedArea, &textBlitArea);
      }

      // Reset flags.
      m_textChanged = false;

      // This is the final image for this container.
      return croppedArea;
    }

  }
}
