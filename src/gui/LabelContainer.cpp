
#include "LabelContainer.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    LabelContainer::LabelContainer(const std::string& text,
                                   const SDL_Color& color,
                                   const std::string& font,
                                   const std::string& name,
                                   const int& fontSize):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             nullptr),
      m_textChanged(true),
      m_text(text),
      m_textColor(color),
      m_fontChanged(true),
      m_fontName(font),
      m_font(nullptr),
      m_size(fontSize),
      m_textSurface(nullptr)
    {
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});
    }

    LabelContainer::~LabelContainer() {
      if (m_textSurface != nullptr) {
        SDL_FreeSurface(m_textSurface);
      }
      clearFont();
    }

    SDL_Surface* LabelContainer::createContentPrivate() {
      // Load the font to render the text.
      loadFont();

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
      m_fontChanged = false;
      m_textChanged = false;

      // This is the final image for this container.
      return croppedArea;
    }

    void LabelContainer::loadFont() {
      // Load the font if needed.
      if (m_fontChanged) {
        // Unload existing font.
        clearFont();

        // Open the new one.
        m_font = TTF_OpenFont(m_fontName.c_str(), m_size);

        // Check that we could effectively load the font.
        if (m_font == nullptr) {
          throw GuiException(std::string("Unable to create font from file ") + m_fontName + ": " + TTF_GetError());
        }
      }
    }

  }
}
