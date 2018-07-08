#ifndef FONTFACTORY_H
#define FONTFACTORY_H

#include <memory>
#include <unordered_map>
#include "Font.h"
#include "ColoredFont.h"
#include "FontFactoryHashSpecialization.hxx"

namespace ogame {
  namespace view {

    class FontFactory
    {
      public:

        FontFactory(const FontFactory& other) = delete;

        void operator=(const FontFactory& other) = delete;

        static
        FontFactory& getInstance();

        void releaseFonts();

        FontShPtr createFont(const std::string& name, const int& size = 25);

        ColoredFontShPtr createColoredFont(const std::string& name,
                                           const int& r,
                                           const int& g,
                                           const int& b,
                                           const int& a = SDL_ALPHA_OPAQUE,
                                           const int& size = 25);

      private:

        FontFactory();

        virtual ~FontFactory();

      private:

        std::unordered_map<std::pair<std::string, int>, FontShPtr> m_fonts;

    };

  }
}

#include "FontFactory.hxx"

#endif // FONTFACTORY_H
