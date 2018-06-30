
#include "SwitchPictureContainer.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    SwitchPictureContainer::SwitchPictureContainer(const std::string& name,
                                                   const std::string& onPicture,
                                                   const std::string& offPicture):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             nullptr),
      m_onFile(onPicture),
      m_onPicture(nullptr),
      m_offFile(offPicture),
      m_offPicture(nullptr),
      m_status(false)
    {
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});

      loadPictures();
    }
        
    SwitchPictureContainer::~SwitchPictureContainer() {
      if (m_onPicture != nullptr) {
        SDL_FreeSurface(m_onPicture);
      }
      if (m_offPicture != nullptr) {
        SDL_FreeSurface(m_offPicture);
      }
    }

    SDL_Surface* SwitchPictureContainer::createContentPrivate() {
      // Create the surface based on the dimensions of this container.
      SDL_Surface* croppedArea = GraphicContainer::createContentPrivate();
      if (croppedArea == nullptr) {
        throw GuiException(std::string("Unable to create perform rendering for picture container using file ") + (m_status ? m_onFile : m_offFile));
      }
      GraphicContainer::clearContentPrivate(croppedArea);

      // Retrieve the picture based on the status.
      SDL_Surface* displayPicture = (m_status ? m_onPicture : m_offPicture);

      // Compute the blit position of the picture so that it is centered.
      SDL_Rect pictureBlitArea = {
        static_cast<Sint16>(croppedArea->w / 2.0f - displayPicture->w / 2.0f),
        static_cast<Sint16>(croppedArea->h / 2.0f - displayPicture->h / 2.0f),
        static_cast<Uint16>(displayPicture->w),
        static_cast<Uint16>(displayPicture->h)
      };

      // Perform the blit operation (i.e. stick the picture onto the rendering area).
      SDL_BlitSurface(displayPicture, nullptr, croppedArea, &pictureBlitArea);

      // This is the final image for this container.
      return croppedArea;
    }

    void SwitchPictureContainer::loadPictures() {
      // Load both images.
      m_onPicture = SDL_LoadBMP(m_onFile.c_str());
      if (m_onPicture == nullptr) {
        throw GuiException(std::string("Unable to create switch picture container using file ") + m_onFile);
      }

      m_offPicture = SDL_LoadBMP(m_offFile.c_str());
      if (m_offPicture == nullptr) {
        throw GuiException(std::string("Unable to create switch picture container using file ") + m_offFile);
      }
    }

  }
}
