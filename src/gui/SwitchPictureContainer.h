#ifndef SWITCHPICTURECONTAINER_H
#define SWITCHPICTURECONTAINER_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"

namespace ogame {
  namespace gui {

    class SwitchPictureContainer: public view::GraphicContainer
    {
      public:

        SwitchPictureContainer(const std::string& name,
                               const std::string& onPicture,
                               const std::string& offPicture,
                               const view::EventListener::Interaction::Mask& mask = view::EventListener::Interaction::NoInteraction);

        virtual ~SwitchPictureContainer();

        void updateStatus(bool status);

      protected:

        SDL_Surface* createContentPrivate() override;

        void clearContentPrivate(SDL_Surface* render) override;

        void onMouseButtonReleasedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent) override;

      private:

        void loadPictures();

      private:

        std::string m_onFile;
        SDL_Surface* m_onPicture;
        std::string m_offFile;
        SDL_Surface* m_offPicture;
        bool m_status;

    };

    using SwitchPictureContainerShPtr = std::shared_ptr<SwitchPictureContainer>;
  }
}

#include "SwitchPictureContainer.hxx"

#endif // SWITCHPICTURECONTAINER_H
