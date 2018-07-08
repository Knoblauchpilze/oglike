
#include "FontFactory.h"

namespace ogame {
  namespace view {

    FontFactory::FontFactory():
      m_fonts()
    {
      // Nothing to do.
    }

    FontFactory::~FontFactory() {}

    
    FontFactory& FontFactory::getInstance() {
      static FontFactory instance;
      return instance;
    }

    void FontFactory::releaseFonts() {
      m_fonts.clear();
    }

  }
}
