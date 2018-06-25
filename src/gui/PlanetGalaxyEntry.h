#ifndef PLANETGALAXYENTRY_H
#define PLANETGALAXYENTRY_H

#include <memory>
#include <vector>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"
#include "PictureContainer.h"

namespace ogame {
  namespace gui {

    class PlanetGalaxyEntry: public view::GraphicContainer
    {
      public:

        PlanetGalaxyEntry(const unsigned& index);
        
        virtual ~PlanetGalaxyEntry();

        void populateWithPlanetData(const core::PlanetShPtr planet);

      private:

        void createView();

        view::GraphicContainerShPtr createInformativePanel(const std::string& name) const;

        PictureContainerShPtr createPicturePanel(const std::string& name, const std::string& file) const;

      private:

        bool m_wreckfield;
        bool m_moon;

    };

    using PlanetGalaxyEntryShPtr = std::shared_ptr<PlanetGalaxyEntry>;
  }
}

#endif // PLANETGALAXYENTRY_H
