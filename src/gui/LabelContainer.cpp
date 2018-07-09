
#include "LabelContainer.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    LabelContainer::LabelContainer(const std::string& name,
                                   const std::string& text,
                                   view::ColoredFontShPtr font,
                                   view::ColoredFontShPtr highlightFont,
                                   const StateContainer::StateAssociation& colors):
      StateContainer(name, StateContainer::State::Normal, colors),
      m_textChanged(true),
      m_text(text),
      
      m_fontChanged(true),
      m_font(font),

      m_hFontChanged(true),
      m_hFont(highlightFont),

      m_highlightChanged(true),
      m_highlight(false),
      m_textSurface(nullptr)
    {
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});
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
        // Compute the blit position of the picture so that it is centered.
        SDL_Rect textBlitArea = {
          static_cast<Sint16>(croppedArea->w / 2.0f - m_textSurface->w / 2.0f),
          static_cast<Sint16>(croppedArea->h / 2.0f - m_textSurface->h / 2.0f),
          static_cast<Uint16>(m_textSurface->w),
          static_cast<Uint16>(m_textSurface->h)
        };

        // Perform the blit operation (i.e. stick the text onto the rendering area).
        SDL_BlitSurface(m_textSurface, nullptr, croppedArea, &textBlitArea);
      }

      // Reset flags.
      m_highlightChanged = false;
      m_fontChanged = false;
      m_textChanged = false;

      // This is the final image for this container.
      return croppedArea;
    }

  }
}
