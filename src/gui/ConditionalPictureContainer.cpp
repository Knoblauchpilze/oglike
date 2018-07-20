
#include "ConditionalPictureContainer.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    ConditionalPictureContainer::ConditionalPictureContainer(const std::string& name,
                                       const std::string& picture,
                                       const view::EventListener::Interaction::Mask& mask,
                                       const bool active):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             mask),
      m_file(picture),
      m_picture(nullptr),
      m_active(active)
    {
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});

      loadPicture();
    }
        
    ConditionalPictureContainer::~ConditionalPictureContainer() {
      if (m_picture != nullptr) {
        SDL_FreeSurface(m_picture);
      }
    }

    SDL_Surface* ConditionalPictureContainer::createContentPrivate() {
      // Create the surface based on the dimensions of this container.
      SDL_Surface* croppedArea = GraphicContainer::createContentPrivate();
      if (croppedArea == nullptr) {
        throw GuiException(std::string("Unable to create perform rendering for picture container using file ") + m_file);
      }
      GraphicContainer::clearContentPrivate(croppedArea);

      // Check whether we should display the picture.
      if (m_active) {
        // Compute the blit position of the picture so that it is centered.
        SDL_Rect pictureBlitArea = {
          static_cast<Sint16>(croppedArea->w / 2.0f - m_picture->w / 2.0f),
          static_cast<Sint16>(croppedArea->h / 2.0f - m_picture->h / 2.0f),
          static_cast<Uint16>(m_picture->w),
          static_cast<Uint16>(m_picture->h)
        };

        // Perform the blit operation (i.e. stick the picture onto the rendering area).
        SDL_BlitSurface(m_picture, nullptr, croppedArea, &pictureBlitArea);
      }

      // This is the final image for this container.
      return croppedArea;
    }

    void ConditionalPictureContainer::loadPicture() {
      // Load the image
      m_picture = SDL_LoadBMP(m_file.c_str());
      if (m_picture == nullptr) {
        throw GuiException(std::string("Unable to create picture container using file ") + m_file);
      }
    }

  }
}
