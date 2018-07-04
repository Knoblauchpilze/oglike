#ifndef PLANETACTIONLIST_HXX
#define PLANETACTIONLIST_HXX

#include "PlanetActionList.h"

namespace ogame {
  namespace gui {

    inline
    SwitchPictureContainerShPtr PlanetActionList::createAction(const std::string& action, const std::string& image) const {
      return std::make_shared<SwitchPictureContainer>(action,
                                                      image,
                                                      std::string("data/img/action_empty.bmp"));
    }

  }
}

#endif // PLANETACTIONLIST_HXX
