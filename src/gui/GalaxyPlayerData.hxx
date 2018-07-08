#ifndef GALAXYPLAYERDATA_HXX
#define GALAXYPLAYERDATA_HXX

#include "GalaxyPlayerData.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    LabelContainerShPtr GalaxyPlayerData::createLabelPanel(const std::string& name, const std::string& text) const {
      return ComponentFactory::createLabelPanel(
        name,
        text,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/angsa.ttf"),
          0, 0, 128
        )
      );
    }

  }
}

#endif // GALAXYPLAYERDATA_HXX
