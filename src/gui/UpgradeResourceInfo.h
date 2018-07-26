#ifndef UPGRADERESOURCEINFO_H
#define UPGRADERESOURCEINFO_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "GraphicContainerListener.h"
#include "LabelContainer.h"
#include "LabelledPicture.h"
#include "Planet.h"

namespace ogame {
  namespace gui {

    class UpgradeResourceInfo: public view::GraphicContainer, public view::GraphicContainerListener
    {
      public:

        UpgradeResourceInfo(const std::string& name);

        virtual ~UpgradeResourceInfo();

        void onInteractionPerformed(const std::string& origin, const view::EventListener::Interaction::Mask& mask) override;

        template <typename Element>
        inline
        void populateInformationFromElement(const Element& element, const core::Planet& planet);

      private:

        void createView();

        LabelContainerShPtr createLabelPanel(const std::string& name,
                                             const std::string& text,
                                             const SDL_Color& color) const;

        LabelledPictureShPtr createLabelledPicturePanel(const std::string& name,
                                                        const std::string& picture,
                                                        const std::string& text) const;

      private:

    };

    using UpgradeResourceInfoShPtr = std::shared_ptr<UpgradeResourceInfo>;
  }
}

#include "UpgradeResourceInfo.hxx"

#endif // UPGRADERESOURCEINFO_H