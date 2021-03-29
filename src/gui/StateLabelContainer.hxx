#ifndef STATE_LABEL_CONTAINER_HXX
#define STATE_LABEL_CONTAINER_HXX

#include "StateLabelContainer.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    inline
    void StateLabelContainer::setText(const std::string& text) {
      lock();
      if (text != m_text) {
        m_text = text;
        m_textChanged = true;
        makeDirty();
      }
      unlock();
    }

    inline
    void StateLabelContainer::setState(const StateContainer::State& state) {
      lock();
      if (state != m_state) {
        m_state = state;
        m_highlightChanged = true;
        makeDirty();
      }
      unlock();
    }

    inline
    void StateLabelContainer::clearContentPrivate(SDL_Surface* render) {
      // Nothing to do here.
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
      if (m_textChanged || m_highlightChanged) {
        clearText();
        if (!m_text.empty()) {
          m_textSurface = createTextFromFont(m_text, getFontFromState());
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

    inline
    SDL_Rect StateLabelContainer::computeBlitPosition(const unsigned& displayWidth, const unsigned& displayHeight) const noexcept {
      SDL_Rect textBlitArea;
      const float margin = 2.0f;

      if (m_alignment == LabelContainer::Alignment::Left) {
       textBlitArea = SDL_Rect{
          static_cast<Sint16>(margin),
          static_cast<Sint16>(displayHeight / 2.0f - m_textSurface->h / 2.0f),
          static_cast<Uint16>(m_textSurface->w),
          static_cast<Uint16>(m_textSurface->h)
        };
      }
      else if (m_alignment == LabelContainer::Alignment::Right) {
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

    inline
    view::ColoredFontShPtr StateLabelContainer::getFontFromState() const {
      const FontAssociation::const_iterator color = m_colors.find(m_state);
      const FontAssociation::const_iterator normalColor = m_colors.find(StateContainer::State::Normal);

      if (color != m_colors.cend()) {
          return color->second;
      }
      else if (m_policy == StateContainer::FailPolicy::Aggressive && normalColor != m_colors.cend()) {
        return normalColor->second;
      }
      else {
        // Could not find a color for this state.
        throw GuiException(std::string("Could not find color for label state in container ") + getName());
      }
    }

  }
}

#endif // STATE_LABEL_CONTAINER_HXX
