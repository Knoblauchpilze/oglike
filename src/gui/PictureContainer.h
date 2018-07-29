#ifndef PICTURECONTAINER_H
#define PICTURECONTAINER_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"

namespace ogame {
  namespace gui {

    class PictureContainer: public view::GraphicContainer
    {
      public:

        PictureContainer(const std::string& name,
                         const std::string& picture,
                         const view::EventListener::Interaction::Mask& mask = view::EventListener::Interaction::NoInteraction);
        
        virtual ~PictureContainer();

        void setImagePath(const std::string& path);

        void clear();

      protected:

        SDL_Surface* createContentPrivate() override;

        void clearContentPrivate(SDL_Surface* render) override;

      private:

        void loadPicture();

      private:

        std::string m_file;
        SDL_Surface* m_picture;

    };

    using PictureContainerShPtr = std::shared_ptr<PictureContainer>;
  }
}

#include "PictureContainer.hxx"

#endif // PICTURECONTAINER_H
