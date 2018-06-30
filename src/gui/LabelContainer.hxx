#ifndef LABELCONTAINER_HXX
#define LABELCONTAINER_HXX

#include "LabelContainer.h"
#include <SDL/SDL_ttf.h>
#include "GuiException.h"

namespace ogame {
  namespace gui {

    inline
    const std::string& LabelContainer::getText() const noexcept {
      return m_text;
    }

    inline
    const SDL_Color& LabelContainer::getTextColor() const noexcept {
      return m_textColor;
    }

    inline
    const std::string& LabelContainer::getFont() const noexcept {
      return m_fontName;
    }

    inline
    const int& LabelContainer::getFontSize() const noexcept {
      return m_size;
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
    void LabelContainer::setTextColor(const SDL_Color& color) {
      lock();
      m_textColor = color;
      m_textChanged = true;
      makeDirty();
      unlock();
    }

    inline
    void LabelContainer::setFont(const std::string& font) {
      lock();
      m_fontName = font;
      m_fontChanged = true;
      makeDirty();
      unlock();
    }

    inline
    void LabelContainer::setFontSize(const int& size) {
      lock();
      m_size = size;
      m_fontChanged = true;
      makeDirty();
      unlock();
    }

    inline
    void LabelContainer::clearContentPrivate(SDL_Surface* render) {
      // Nothing to do here.
    }

    inline
    void LabelContainer::clearFont() {
      if (m_font != nullptr) {
        TTF_CloseFont(m_font);
      }
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
      if (m_textChanged || m_fontChanged) {
        clearText();
        if (!m_text.empty()) {
          m_textSurface = TTF_RenderText_Blended(m_font, m_text.c_str(), m_textColor);
          if (m_textSurface == nullptr) {
            throw GuiException(std::string("Could not render label container, error with text ") + m_text);
          }
        }
      }
    }

  }
}

#endif // LABELCONTAINER_HXX
