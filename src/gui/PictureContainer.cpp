
#include "PictureContainer.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    PictureContainer::PictureContainer(const std::string& name, const std::string& picture):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             nullptr),
      m_file(picture),
      m_picture(nullptr)
    {
      loadPicture();
    }
        
    PictureContainer::~PictureContainer() {
      if (m_picture != nullptr) {
        SDL_FreeSurface(m_picture);
      }
    }

    SDL_Surface* PictureContainer::createContentPrivate() {
      // Create the surface based on the dimensions of this container.
      SDL_Surface* croppedArea = SDL_CreateRGBSurface(0, static_cast<int>(getRenderingAreaPrivate().w()), static_cast<int>(getRenderingAreaPrivate().h()), 32, 0, 0, 0, 0);
      if (croppedArea == nullptr) {
        throw GuiException(std::string("Unable to create perform rendering for picture container using file ") + m_file);
      }

      // Compute the blit position of the picture so that it is centered.
      SDL_Rect pictureBlitArea = {
        static_cast<Sint16>(croppedArea->w / 2.0f - m_picture->w / 2.0f),
        static_cast<Sint16>(croppedArea->h / 2.0f - m_picture->h / 2.0f),
        static_cast<Uint16>(m_picture->w),
        static_cast<Uint16>(m_picture->h)
      };

      // Perform the blit operation (i.e. stick the picture onto the rendering area).
      SDL_BlitSurface(m_picture, nullptr, croppedArea, &pictureBlitArea);

      // This is the final image for this container.
      return croppedArea;
    }

    void PictureContainer::loadPicture() {
      // Load the image
      m_picture = SDL_LoadBMP(m_file.c_str());
      if (m_picture == nullptr) {
        throw GuiException(std::string("Unable to create picture container using file ") + m_file);
      }
    }

  }
}
