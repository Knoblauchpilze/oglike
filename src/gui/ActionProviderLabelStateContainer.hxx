#ifndef ACTIONPROVIDERLABELSTATECONTAINER_HXX
#define ACTIONPROVIDERLABELSTATECONTAINER_HXX

#include "ActionProviderLabelStateContainer.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    inline
    void ActionProviderLabelStateContainer::clearContentPrivate(SDL_Surface* render) {
      // Nothing to do here.
    }

    inline
    void ActionProviderLabelStateContainer::onStateModified() {
      // Call the parent method
      ActionProviderStateContainer::onStateModified();

      // Update internal attributes.
      m_highlightChanged = true;

      // Flag for redraw.
      makeDeepDirty();
    }

    inline
    void ActionProviderLabelStateContainer::clearText() {
      if (m_textSurface != nullptr) {
        SDL_FreeSurface(m_textSurface);
        m_textSurface = nullptr;
      }
    }

    inline
    void ActionProviderLabelStateContainer::createText() {
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
    SDL_Surface* ActionProviderLabelStateContainer::createTextFromFont(const std::string& text, view::ColoredFontShPtr font) {
      if (font == nullptr) {
        throw GuiException(std::string("Could not render label container ") + getName() + ", invalid font");
      }
      return font->render(text);
    }

  }
}

#endif // ACTIONPROVIDERLABELSTATECONTAINER_HXX
