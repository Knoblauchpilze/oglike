
#include "PlanetIconDisplay.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    PlanetIconDisplay::PlanetIconDisplay(const unsigned& count, const std::string& name):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             nullptr),
      m_count(count),
      m_pictures(),
      m_planetIndex(-1)
    {
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});

      loadPictures();
    }

    PlanetIconDisplay::~PlanetIconDisplay() {
      for (std::unordered_map<int, SDL_Surface*>::const_iterator picture = m_pictures.cbegin() ;
           picture != m_pictures.cend() ;
           ++picture)
      {
        if (picture->second != nullptr) {
          SDL_FreeSurface(picture->second);
        }
      }
      m_pictures.clear();
    }

    SDL_Surface* PlanetIconDisplay::createContentPrivate() {
      // Create the surface based on the dimensions of this container.
      SDL_Surface* croppedArea = GraphicContainer::createContentPrivate();
      if (croppedArea == nullptr) {
        throw GuiException(std::string("Unable to create perform rendering for planet icon display ") + getName());
      }
      GraphicContainer::clearContentPrivate(croppedArea);

      // Retrieve the picture to use if any.
      if (m_planetIndex >= 0) {
        std::unordered_map<int, SDL_Surface*>::const_iterator picture = m_pictures.find(m_planetIndex);
        if (picture == m_pictures.cend()) {
          throw GuiException(std::string("Unable to find a suited planet icon for planet at index " ) + std::to_string(m_planetIndex));
        }

        // Compute the blit position of the picture so that it is centered.
        SDL_Rect pictureBlitArea = {
          static_cast<Sint16>(croppedArea->w / 2.0f - picture->second->w / 2.0f),
          static_cast<Sint16>(croppedArea->h / 2.0f - picture->second->h / 2.0f),
          static_cast<Uint16>(picture->second->w),
          static_cast<Uint16>(picture->second->h)
        };

        // Perform the blit operation (i.e. stick the picture onto the rendering area).
        SDL_BlitSurface(picture->second, nullptr, croppedArea, &pictureBlitArea);
      }

      // This is the final image for this container.
      return croppedArea;
    }

  }
}
