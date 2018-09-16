#ifndef BACKGROUNDEDLABEL_HXX
#define BACKGROUNDEDLABEL_HXX

#include "BackgroundedLabel.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    inline
    void BackgroundedLabel::setText(const std::string& text) {
      lock();
      m_text = text;
      m_textChanged = true;
      makeDirty();
      unlock();
    }

    inline
    void BackgroundedLabel::clearContentPrivate(SDL_Surface* render) {
      // Nothing to do here.
    }

    inline
    void BackgroundedLabel::clearText() {
      if (m_textSurface != nullptr) {
        SDL_FreeSurface(m_textSurface);
        m_textSurface = nullptr;
      }
    }

    inline
    void BackgroundedLabel::createText() {
      // Create new text if needed.
      if (m_textChanged) {
        clearText();
        if (!m_text.empty()) {
          // Create the text.
          m_textSurface = createTextFromFont(m_text, m_font);
          if (m_textSurface == nullptr) {
            throw GuiException(std::string("Could not render backgrounded label container ") + getName() + ", error with text " + m_text);
          }

          // Create the text background.
          const unsigned hMargin = 5u;
          const unsigned vMargin = 2u;
          SDL_Surface* textBackground = SDL_CreateRGBSurface(0, m_textSurface->w + hMargin, m_textSurface->h + vMargin, 32, 0, 0, 0, 0);
          if (textBackground == nullptr) {
            throw GuiException(std::string("Could not render backgrounded label container ") + getName() + ", error with text " + m_text);
          }
          SDL_FillRect(
            textBackground,
            nullptr,
            SDL_MapRGB(
              textBackground->format,
              m_textBackgroundColor.r,
              m_textBackgroundColor.g,
              m_textBackgroundColor.b
            )
          );

          // Copy the text onto the background
          SDL_Rect blitPosition = {hMargin, vMargin, 0, 0};
          SDL_BlitSurface(m_textSurface, nullptr, textBackground, &blitPosition);

          // Finally swap the text image.
          SDL_FreeSurface(m_textSurface);
          m_textSurface = textBackground;
        }
      }
    }

    inline
    SDL_Surface* BackgroundedLabel::createTextFromFont(const std::string& text, view::ColoredFontShPtr font) {
      if (font == nullptr) {
        throw GuiException(std::string("Could not render label container ") + getName() + ", invalid font");
      }
      return font->render(text);
    }
    inline
    SDL_Rect BackgroundedLabel::computeBlitPosition(const unsigned& displayWidth, const unsigned& displayHeight) const noexcept {
      SDL_Rect textBlitArea;
      const float hMargin = 2.0f;
      const float vMargin = 10.0f;

      if (m_alignment == Alignment::TopLeft) {
       textBlitArea = SDL_Rect{
          static_cast<Sint16>(hMargin),
          static_cast<Sint16>(vMargin),
          static_cast<Uint16>(m_textSurface->w),
          static_cast<Uint16>(m_textSurface->h)
        };
      }
      else if (m_alignment == Alignment::TopRight) {
       textBlitArea = SDL_Rect{
          static_cast<Sint16>(displayWidth - hMargin - m_textSurface->w),
          static_cast<Sint16>(vMargin),
          static_cast<Uint16>(m_textSurface->w),
          static_cast<Uint16>(m_textSurface->h)
        };
      }
      else if (m_alignment == Alignment::BottomLeft) {
       textBlitArea = SDL_Rect{
          static_cast<Sint16>(hMargin),
          static_cast<Sint16>(displayHeight - vMargin - m_textSurface->h),
          static_cast<Uint16>(m_textSurface->w),
          static_cast<Uint16>(m_textSurface->h)
        };
      }
      else {
       textBlitArea = SDL_Rect{
          static_cast<Sint16>(displayWidth - hMargin - m_textSurface->w),
          static_cast<Sint16>(displayHeight - vMargin - m_textSurface->h),
          static_cast<Uint16>(m_textSurface->w),
          static_cast<Uint16>(m_textSurface->h)
        };
      }

      return textBlitArea;
    }

  }
}

#endif // BACKGROUNDEDLABEL_HXX
