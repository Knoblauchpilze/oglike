#ifndef FONT_HXX
#define FONT_HXX

#include "Font.h"
#include "FontException.h"

namespace ogame {
  namespace view {

    inline
    const std::string& Font::getName() const noexcept {
      return m_name;
    }

    inline
    const int& Font::getSize() const noexcept {
      return m_size;
    }

    inline
    void Font::setName(const std::string& name) {
      unload();
      m_name = name;
    }

    inline
    void Font::setSize(const int& size) {
      unload();
      m_size = size;
    }

    inline
    SDL_Surface* Font::render(const std::string text, const SDL_Color& color) {
      // Load the font if needed.
      if (!loaded()) {
        load();
      }

      // Proceed to rendering.
      SDL_Surface* textSurface = TTF_RenderUTF8_Blended(m_font, text.c_str(), color);
      if (textSurface == nullptr) {
        throw FontException(std::string("Could not render text ") + text + " with font " + m_name);
      }

      return textSurface;
    }

    inline
    const bool Font::loaded() const noexcept {
      return (m_font != nullptr);
    }

    inline
    void Font::load() {
      if (!loaded()) {
        m_font = TTF_OpenFont(m_name.c_str(), m_size);
        // Check that we could effectively load the font.
        if (m_font == nullptr) {
          throw FontException(std::string("Unable to create font from file ") + m_name + ": " + TTF_GetError());
        }
      }
    }

    inline
    void Font::unload() {
      if (loaded()) {
        TTF_CloseFont(m_font);
        m_font = nullptr;
      }
    }

    inline
    void Font::initializeTTFLib() {
      // Initialize the ttf lib.
      if (!TTF_WasInit() && TTF_Init() == -1) {
        throw FontException(std::string("Unable to initialize TTF lib, cannot create view: ") + TTF_GetError());
      }
    }

  }
}

#endif // FONT_HXX
