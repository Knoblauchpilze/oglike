
#include "Font.h"

namespace ogame {
  namespace view {

    Font::Font(const std::string& name, const SDL_Color& color, const int& size):
      m_name(name),
      m_color(color),
      m_size(std::max(1, size)),
      m_font(nullptr)
    {
      // Initialize the lib.
      initializeTTFLib();
    }

    Font::Font(const std::string& name,
               const int& r,
               const int& g,
               const int& b,
               const int& a,
               const int& size):
      m_name(name),
      m_color({static_cast<std::uint8_t>(r), static_cast<std::uint8_t>(g), static_cast<std::uint8_t>(b), static_cast<std::uint8_t>(a)}),
      m_size(std::max(1, size)),
      m_font(nullptr)
    {
      // Initialize the lib.
      initializeTTFLib();
    }

    Font::~Font() {
      unload();
    }

  }
}
