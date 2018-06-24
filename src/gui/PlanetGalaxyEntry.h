#ifndef PLANETGALAXYENTRY_H
#define PLANETGALAXYENTRY_H

#include <memory>
#include <vector>
#include <SDL/SDL.h>
#include "GraphicContainer.h"

namespace ogame {
  namespace gui {

    class PlanetGalaxyEntry: public view::GraphicContainer
    {
      public:

        PlanetGalaxyEntry(const unsigned& index);
        
        virtual ~PlanetGalaxyEntry();

      private:

        void createView();

        view::GraphicContainerShPtr createInformativePanel(const std::string& name);

      private:

    };

    using PlanetGalaxyEntryShPtr = std::shared_ptr<PlanetGalaxyEntry>;
  }
}

#endif // PLANETGALAXYENTRY_H
