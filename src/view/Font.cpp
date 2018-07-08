
#include "Font.h"

namespace ogame {
  namespace view {

    Font::Font(const std::string& name, const int& size):
      m_name(name),
      m_size(std::max(1, size)),
      m_font(nullptr)
    {
      // Initialize the lib.
      initializeTTFLib();
    }

    Font::Font(const Font& other):
      m_name(other.m_name),
      m_size(other.m_size),
      m_font(other.m_font)
    {
      // Nothing to do.
    }

    Font::~Font() {
      unload();
    }

  }
}
