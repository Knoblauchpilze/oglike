#ifndef UPGRADERESOURCEINFO_H
#define UPGRADERESOURCEINFO_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "LabelContainer.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    class UpgradeResourceInfo: public view::GraphicContainer
    {
      public:

        UpgradeResourceInfo(const std::string& name);

        virtual ~UpgradeResourceInfo();

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