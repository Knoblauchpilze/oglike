#ifndef FONTFACTORY_HXX
#define FONTFACTORY_HXX

#include "FontFactory.h"

namespace ogame {
  namespace view {

    inline
    FontShPtr FontFactory::createFont(const std::string& name, const int& size) {
      // Try to find this couple.
      std::unordered_map<std::pair<std::string, int>, FontShPtr>::const_iterator font = m_fonts.find(std::make_pair(name, size));
      if (font != m_fonts.cend()) {
        return font->second;
      }

      m_fonts[std::make_pair(name, size)] = std::make_shared<Font>(
        name,
        size
      );

      return m_fonts[std::make_pair(name, size)];
    }

    inline
    ColoredFontShPtr FontFactory::createColoredFont(const std::string& name,
                                                    const int& r,
                                                    const int& g,
                                                    const int& b,
                                                    const int& a,
                                                    const int& size)
    {
      return std::make_shared<ColoredFont>(
        createFont(name, size),
        r, g, b, a
      );
    }

  }
}

#endif // FONTFACTORY_HXX
