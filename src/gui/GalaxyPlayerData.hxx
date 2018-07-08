#ifndef GALAXYPLAYERDATA_HXX
#define GALAXYPLAYERDATA_HXX

#include "GalaxyPlayerData.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    inline
    LabelContainerShPtr GalaxyPlayerData::createLabelPanel(const std::string& name, const std::string& text, view::FontShPtr font) const {
      return ComponentFactory::createLabelPanel(
        name,
        text,
        font
      );
    }

  }
}

#endif // GALAXYPLAYERDATA_HXX
