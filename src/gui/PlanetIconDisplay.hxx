#ifndef PLANETICONDISPLAY_HXX
#define PLANETICONDISPLAY_HXX

#include "PlanetIconDisplay.h"
#include "SystemException.h"

namespace ogame {
  namespace gui {

    inline
    void PlanetIconDisplay::populateWithPlanetData(const core::Planet& planet) {
      lock();
      try {
        m_planetIndex = (planet.isColonized() ? computeIndexFromPlanet(planet) : -1);
        makeDirty();
      }
      catch (const core::SystemException& e) {
        std::cerr << "[PLANET] Unable to find planet icon, invalid system index:" << std::endl << e.what() << std::endl;
      }
      unlock();
    }

    inline
    void PlanetIconDisplay::clearContentPrivate(SDL_Surface* render) {
      // Nothing to do here.
    }

    inline
    void PlanetIconDisplay::loadPictures() {
      // Load all related images.
      for (unsigned indexPlanet = 0u ; indexPlanet < m_count ; ++indexPlanet) {
        const std::string planetFileName = std::string("data/img/planet") + std::to_string(indexPlanet + 1) + ".bmp";
        SDL_Surface* planet = SDL_LoadBMP(planetFileName.c_str());
        if (planet == nullptr) {
          std::cerr << "[PLANET] Unable to create picture from planet icon file " << planetFileName << std::endl;
        }
        else {
          m_pictures[indexPlanet] = planet;
        }
      }
    }

    inline
    const int PlanetIconDisplay::computeIndexFromPlanet(const core::Planet& planet) const noexcept {
      return planet.getPositionInSystem() % m_count;
    }

  }
}

#endif // PLANETICONDISPLAY_HXX
