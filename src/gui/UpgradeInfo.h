#ifndef UPGRADEINFO_H
#define UPGRADEINFO_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "GraphicContainerListener.h"
#include "LabelContainer.h"
#include "Planet.h"
#include "ResourceMine.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class UpgradeInfo: public view::GraphicContainer, public player::GeneralActionListener, view::GraphicContainerListener
    {
      public:

        UpgradeInfo(const std::string& name,
                    player::GeneralDataModelShPtr model);

        virtual ~UpgradeInfo();

        void onActionTriggered(const player::GeneralDataModel& model, const player::Action& action) override;

        void onInteractionPerformed(const std::string& origin, const view::EventListener::Interaction::Mask& mask) override;

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

        const std::string computeEnergyDisplay(const core::Building& building) const;

        const std::string computeProductionDisplay(const core::Building& building, const core::Planet& planet) const;

      private:

    };

    using UpgradeInfoShPtr = std::shared_ptr<UpgradeInfo>;
  }
}

#include "UpgradeInfo.hxx"

#endif // UPGRADEINFO_H