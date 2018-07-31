
#include "StateLabelContainer.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    StateLabelContainer::StateLabelContainer(const std::string& name,
                                             const std::string& text,
                                             const FontAssociation& colors,
                                             const LabelContainer::Alignment& alignment,
                                             const StateContainer::FailPolicy& policy):
      view::GraphicContainer(name,
                             view::utils::Area()),
      m_state(StateContainer::State::Normal),
      m_policy(policy),
      m_colors(colors),
      m_alignment(alignment),

      m_text(text),
      m_textChanged(true),
      m_highlightChanged(true),
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
      SDL_Surface* croppedArea = view::GraphicContainer::createContentPrivate();
      if (croppedArea == nullptr) {
        throw GuiException(std::string("Unable to create perform rendering for state label container ") + getName() + " using text " + m_text);
      }
      view::GraphicContainer::clearContentPrivate(croppedArea);

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
      m_textChanged = false;
      m_highlightChanged = false;

      // This is the final image for this container.
      return croppedArea;
    }

  }
}
