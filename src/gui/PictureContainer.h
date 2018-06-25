#ifndef PICTURECONTAINER_H
#define PICTURECONTAINER_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Planet.h"

namespace ogame {
  namespace gui {

    class PictureContainer: public view::GraphicContainer
    {
      public:

        PictureContainer(const std::string& name, const std::string& picture);
        
        virtual ~PictureContainer();

      protected:

        SDL_Surface* createContentPrivate() override;

        void clearContentPrivate() override;

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
