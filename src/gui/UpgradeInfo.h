#ifndef UPGRADEINFO_H
#define UPGRADEINFO_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "LabelContainer.h"
#include "Planet.h"

namespace ogame {
  namespace gui {

    class UpgradeInfo: public view::GraphicContainer
    {
      public:

        UpgradeInfo(const std::string& name);

        virtual ~UpgradeInfo();

        template <typename Element>
        inline
        void populateInformationFromElement(const Element& element,
                                            const core::Planet& planet,
                                            const core::Account& account);

      private:

        void createView();

        LabelContainerShPtr createLabelPanel(const std::string& name,
                                             const std::string& text,
                                             const SDL_Color& textColor,
                                             const SDL_Color& bgColor = SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE},
                                             const bool transparent = true,
                                             const LabelContainer::Alignment& alignment = LabelContainer::Alignment::Left) const;

        const std::string computeDisplayTime(const float& seconds) const;

      private:

    };

    using UpgradeInfoShPtr = std::shared_ptr<UpgradeInfo>;
  }
}

#include "UpgradeInfo.hxx"

#endif // UPGRADEINFO_H