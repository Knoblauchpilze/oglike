
#include "StateLabelContainer.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    StateLabelContainer::StateLabelContainer(const std::string& name,
                                             const std::string& text,
                                             const player::View& view,
                                             player::DataModel* model,
                                             view::ColoredFontShPtr font,
                                             view::ColoredFontShPtr highlightFont,
                                             const StateContainer::StateAssociation& colors,
                                             const StateContainer::FailPolicy& policy):
      ActionProviderStateContainer(name,
                                   StateContainer::State::Normal,
                                   colors,
                                   view,
                                   model,
                                   policy),
      m_textChanged(true),
      m_text(text),
      
      m_fontChanged(true),
      m_font(font),
      
      m_hFontChanged(true),
      m_hFont(highlightFont),

      m_textSurface(nullptr)
    {
      // Nothing to do here.
    }

    StateLabelContainer::~StateLabelContainer() {
      clearText();
    }

    SDL_Surface* StateLabelContainer::createContentPrivate() {
      // Create the text to render.
      createText();

      // Create the surface based on the dimensions of this container.
      SDL_Surface* croppedArea = StateContainer::createContentPrivate();
      if (croppedArea == nullptr) {
        throw GuiException(std::string("Unable to create perform rendering for state label container ") + getName() + " using text " + m_text);
      }
      StateContainer::clearContentPrivate(croppedArea);

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
      m_fontChanged = false;
      m_hFontChanged = false;
      m_textChanged = false;

      // This is the final image for this container.
      return croppedArea;
    }

  }
}
