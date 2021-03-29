#ifndef PLANETACTIONLIST_H
#define PLANETACTIONLIST_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "SwitchPictureContainer.h"
#include "Planet.h"

namespace ogame {
  namespace gui {

    class PlanetActionList: public view::GraphicContainer
    {
      public:

        PlanetActionList(const std::string& name);

        virtual ~PlanetActionList();

        void updateStatus(const core::Planet& planet);

      private:

        void createView();

        SwitchPictureContainerShPtr createAction(const std::string& action, const std::string& image) const;

    };

    using PlanetActionListShPtr = std::shared_ptr<PlanetActionList>;
  }
}

#include "PlanetActionList.hxx"

#endif // PLANETACTIONLIST_H
