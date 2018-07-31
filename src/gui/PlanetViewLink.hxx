#ifndef PLANETVIEWLINK_HXX
#define PLANETVIEWLINK_HXX

#include "PlanetViewLink.h"
#include "StateLabelContainer.h"

namespace ogame {
  namespace gui {

    inline
    void PlanetViewLink::onStateModified() {
      StateLabelContainer* name = getChild<StateLabelContainer*>(std::string("planet_name"));
      if (checkChild(name, "Planet view link name")) {
        name->setState(getStatePrivate());
      }

      StateLabelContainer* coords = getChild<StateLabelContainer*>(std::string("planet_coords"));
      if (checkChild(coords, "Planet view link coordinates")) {
        coords->setState(getStatePrivate());
      }
    }

  }
}

#endif // PLANETVIEWLINK_HXX
