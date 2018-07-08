#ifndef PLANETVIEWLINK_H
#define PLANETVIEWLINK_H

#include <memory>
#include <vector>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"
#include "PlanetIconDisplay.h"

namespace ogame {
  namespace gui {

    class PlanetViewLink: public view::GraphicContainer
    {
      public:

        PlanetViewLink(const std::string& name, const unsigned& planetCount);

        virtual ~PlanetViewLink();

        void populateWithPlanetData(const core::Planet& planet);

      private:

        void createView(const unsigned& planetCount);

      private:

    };

    using PlanetViewLinkShPtr = std::shared_ptr<PlanetViewLink>;
  }
}

#include "PlanetViewLink.hxx"

#endif // PLANETVIEWLINK_H
