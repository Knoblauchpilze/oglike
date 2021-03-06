
#include "PictureContainer.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    PictureContainer::PictureContainer(const std::string& name,
                                       const std::string& picture,
                                       const view::EventListener::Interaction::Mask& mask):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             mask,
                             true),
      m_file(picture),
      m_picture(nullptr)
    {
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});

      loadPicture();
    }

    PictureContainer::~PictureContainer() {
      if (m_picture != nullptr) {
        SDL_FreeSurface(m_picture);
      }
    }

    SDL_Surface* PictureContainer::createContentPrivate() {
      // Create the surface based on the dimensions of this container.
      SDL_Surface* croppedArea = GraphicContainer::createContentPrivate();
      if (croppedArea == nullptr) {
        throw GuiException(std::string("Unable to create perform rendering for picture container using file ") + m_file);
      }
      GraphicContainer::clearContentPrivate(croppedArea);

      // Compute the blit position of the picture so that it is centered.
      if (m_picture != nullptr) {
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

    void PictureContainer::loadPicture() {
      // CLear existing image if any.
      if (m_picture != nullptr) {
        SDL_FreeSurface(m_picture);
        m_picture = nullptr;
      }

      // Load the image
      if (!m_file.empty()) {
        m_picture = SDL_LoadBMP(m_file.c_str());
        if (m_picture == nullptr) {
          throw GuiException(std::string("Unable to create picture container using file ") + m_file);
        }
      }
    }

  }
}
