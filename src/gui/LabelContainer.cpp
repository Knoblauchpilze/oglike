
#include "LabelContainer.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    LabelContainer::LabelContainer(const std::string& name,
                                   const std::string& text,
                                   view::ColoredFontShPtr font,
                                   const Alignment& alignment,
                                   const SDL_Color& bgColor,
                                   const bool transparent):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             transparent),
      m_alignment(alignment),

      m_textChanged(true),
      m_text(text),

      m_fontChanged(true),
      m_font(font),

      m_highlightChanged(true),
      m_textSurface(nullptr)
    {
      setBackgroundColor(bgColor);
    }

    LabelContainer::~LabelContainer() {
      clearText();
    }

    SDL_Surface* LabelContainer::createContentPrivate() {
      // Create the text to render.
      createText();

      // Create the surface based on the dimensions of this container.
      SDL_Surface* croppedArea = GraphicContainer::createContentPrivate();
      if (croppedArea == nullptr) {
        throw GuiException(std::string("Unable to create perform rendering for label container using text ") + m_text);
      }
      GraphicContainer::clearContentPrivate(croppedArea);

      // Check whether some text should be displayed.
      if (m_textSurface != nullptr) {
        // Compute the blit position of the picture so that it respects the alignment.
        SDL_Rect textBlitArea = computeBlitPosition(croppedArea->w, croppedArea->h);

        // Perform the blit operation (i.e. stick the text onto the rendering area).
        SDL_BlitSurface(m_textSurface, nullptr, croppedArea, &textBlitArea);
      }

      // Reset flags.
      m_fontChanged = false;
      m_textChanged = false;

      // This is the final image for this container.
      return croppedArea;
    }

  }
}
