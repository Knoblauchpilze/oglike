#ifndef UPGRADEINFO_H
#define UPGRADEINFO_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "LabelContainer.h"

namespace ogame {
  namespace gui {

    class UpgradeInfo: public view::GraphicContainer
    {
      public:

        UpgradeInfo(const std::string& name);

        virtual ~UpgradeInfo();

      private:

        void createView();

        LabelContainerShPtr createLabelPanel(const std::string& name,
                                             const std::string& text,
                                             const SDL_Color& textColor,
                                             const SDL_Color& bgColor = SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE},
                                             const bool transparent = true) const;

      private:

    };

    using UpgradeInfoShPtr = std::shared_ptr<UpgradeInfo>;
  }
}

#include "UpgradeInfo.hxx"

#endif // UPGRADEINFO_H