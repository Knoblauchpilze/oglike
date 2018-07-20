#ifndef CONDITIONALPICTURECONTAINER_H
#define CONDITIONALPICTURECONTAINER_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"

namespace ogame {
  namespace gui {

    class ConditionalPictureContainer: public view::GraphicContainer
    {
      public:

        ConditionalPictureContainer(const std::string& name,
                         const std::string& picture,
                         const view::EventListener::Interaction::Mask& mask = view::EventListener::Interaction::NoInteraction,
                         const bool active = true);
        
        virtual ~ConditionalPictureContainer();

        const bool getStatus();

        void setActive(const bool active);

      protected:

        SDL_Surface* createContentPrivate() override;

        void clearContentPrivate(SDL_Surface* render) override;

      private:

        void loadPicture();

      private:

        std::string m_file;
        SDL_Surface* m_picture;
        bool m_active;

    };

    using ConditionalPictureContainerShPtr = std::shared_ptr<ConditionalPictureContainer>;
  }
}

#include "ConditionalPictureContainer.hxx"

#endif // CONDITIONALPICTURECONTAINER_H
