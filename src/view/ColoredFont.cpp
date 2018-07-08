
#include "ColoredFont.h"

namespace ogame {
  namespace view {

    ColoredFont::ColoredFont(FontShPtr font, const int& r, const int& g, const int& b, const int& a):
      m_fontPtr(font),
      m_color({
        static_cast<std::uint8_t>(r),
        static_cast<std::uint8_t>(g),
        static_cast<std::uint8_t>(b),
        static_cast<std::uint8_t>(a)})
    {
      // Nothing to do.
    }

    ColoredFont::ColoredFont(const ColoredFont& other):
      m_fontPtr(other.m_fontPtr),
      m_color(other.m_color)
    {
      // Nothing to do.
    }

    ColoredFont::~ColoredFont() {}

  }
}
