#ifndef LABELCONTAINER_HXX
#define LABELCONTAINER_HXX

#include "LabelContainer.h"
#include <SDL/SDL_ttf.h>
#include "GuiException.h"

namespace ogame {
  namespace gui {

    inline
    const std::string LabelContainer::getText() const noexcept {
      return m_text;
    }

    inline
    void LabelContainer::setText(const std::string& text) {
      lock();
      m_text = text;
      m_textChanged = true;
      makeDirty();
      unlock();
    }

    inline
    void LabelContainer::clearContentPrivate(SDL_Surface* render) {
      // Nothing to do here.
    }

    inline
    void LabelContainer::clearText() {
      if (m_textSurface != nullptr) {
        SDL_FreeSurface(m_textSurface);
        m_textSurface = nullptr;
      }
    }

    inline
    void LabelContainer::createText() {
      // Create new text if needed.
      if (m_textChanged || m_fontChanged || m_highlightChanged) {
        clearText();
        if (!m_text.empty()) {
          m_textSurface = createTextFromFont(m_text, m_font);
          if (m_textSurface == nullptr) {
            throw GuiException(std::string("Could not render label container ") + getName() + ", error with text " + m_text);
          }
        }
      }
    }

    inline
    SDL_Surface* LabelContainer::createTextFromFont(const std::string& text, view::ColoredFontShPtr font) {
      if (font == nullptr) {
        throw GuiException(std::string("Could not render label container ") + getName() + ", invalid font");
      }
      return font->render(text);
    }

    inline
    SDL_Rect LabelContainer::computeBlitPosition(const unsigned& displayWidth, const unsigned& displayHeight) const noexcept {
      SDL_Rect textBlitArea;
      const float margin = 2.0f;

      if (m_alignment == Alignment::Left) {
       textBlitArea = SDL_Rect{
          static_cast<Sint16>(margin),
          static_cast<Sint16>(displayHeight / 2.0f - m_textSurface->h / 2.0f),
          static_cast<Uint16>(m_textSurface->w),
          static_cast<Uint16>(m_textSurface->h)
        };
      }
      else if (m_alignment == Alignment::Right) {
       textBlitArea = SDL_Rect{
          static_cast<Sint16>(displayWidth - margin - m_textSurface->w),
          static_cast<Sint16>(displayHeight / 2.0f - m_textSurface->h / 2.0f),
          static_cast<Uint16>(m_textSurface->w),
          static_cast<Uint16>(m_textSurface->h)
        };
      }
      else {
       textBlitArea = SDL_Rect{
          static_cast<Sint16>(displayWidth / 2.0f - m_textSurface->w / 2.0f),
          static_cast<Sint16>(displayHeight / 2.0f - m_textSurface->h / 2.0f),
          static_cast<Uint16>(m_textSurface->w),
          static_cast<Uint16>(m_textSurface->h)
        };
      }

      return textBlitArea;
    }

  }
}

#endif // LABELCONTAINER_HXX
