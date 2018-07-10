#ifndef STATE_LABEL_CONTAINER_HXX
#define STATE_LABEL_CONTAINER_HXX

#include "StateLabelContainer.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    inline
    void StateLabelContainer::clearContentPrivate(SDL_Surface* render) {
      // Nothing to do here.
    }

    inline
    void StateLabelContainer::onStateModified() {
      lock();

      m_highlightChanged = true;

      makeDeepDirty();
      unlock();
    }

    inline
    void StateLabelContainer::clearText() {
      if (m_textSurface != nullptr) {
        SDL_FreeSurface(m_textSurface);
        m_textSurface = nullptr;
      }
    }

    inline
    void StateLabelContainer::createText() {
      // Create new text if needed.
      if (m_textChanged || m_fontChanged || m_highlightChanged) {
        clearText();
        if (!m_text.empty()) {
          m_textSurface = createTextFromFont(m_text, getStatePrivate() != State::Normal ? m_hFont : m_font);
          if (m_textSurface == nullptr) {
            throw GuiException(std::string("Could not render label container ") + getName() + ", error with text " + m_text);
          }
        }
      }
    }

    inline
    SDL_Surface* StateLabelContainer::createTextFromFont(const std::string& text, view::ColoredFontShPtr font) {
      if (font == nullptr) {
        throw GuiException(std::string("Could not render label container ") + getName() + ", invalid font");
      }
      return font->render(text);
    }

  }
}

#endif // STATE_LABEL_CONTAINER_HXX
