#ifndef PLANETICONDISPLAY_H
#define PLANETICONDISPLAY_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"

namespace ogame {
  namespace gui {

    class PlanetIconDisplay: public view::GraphicContainer
    {
      public:

        PlanetIconDisplay(const unsigned& count, const std::string& name);
        
        virtual ~PlanetIconDisplay();

        void populateWithPlanetData(const core::Planet& planet);

      protected:

        SDL_Surface* createContentPrivate() override;

        void clearContentPrivate(SDL_Surface* render) override;

      private:

        void loadPictures();

        const int computeIndexFromPlanet(const core::Planet& planet) const noexcept;

      private:

        unsigned m_count;
        std::unordered_map<int, SDL_Surface*> m_pictures;
        int m_planetIndex;

    };

    using PlanetIconDisplayShPtr = std::shared_ptr<PlanetIconDisplay>;
  }
}

#include "PlanetIconDisplay.hxx"

#endif // PLANETICONDISPLAY_H
