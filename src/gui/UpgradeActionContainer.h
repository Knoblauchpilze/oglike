#ifndef UPGRADEACTIONCONTAINER_H
#define UPGRADEACTIONCONTAINER_H

#include <memory>
#include <SDL/SDL.h>
#include "SelectorPanel.h"
#include "LabelContainer.h"
#include "Planet.h"

namespace ogame {
  namespace gui {

    class UpgradeActionContainer: public SelectorPanel
    {
      public:

        UpgradeActionContainer(const std::string& name);

        virtual ~UpgradeActionContainer();

        void populateWithBuildingData(const core::Planet& planet);

        void populateWithResearchData(const core::Account& account);

        void populateWithShipyardData(const core::Planet& planet);

      private:

        void createView();

        view::GraphicContainerShPtr createUpgradeContainer(const std::string& name);

        view::GraphicContainerShPtr createEmptyContainer(const std::string& name);

        LabelContainerShPtr createLabel(const std::string& name,
                                        const std::string& text,
                                        const SDL_Color& textColor,
                                        const LabelContainer::Alignment& alignment = LabelContainer::Alignment::Left,
                                        const SDL_Color& bgColor = SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE},
                                        const bool transparent = true,
                                        const int& policeSize = 15) const;

        const std::string computeDisplayTime(const float& seconds) const;

        const std::string getPictureNameFromBuilding(const core::Building::Type& type) const noexcept;

        const std::string getPictureNameFromResearch(const core::Research::Type& type) const noexcept;

        const std::string getPictureNameFromShip(const core::Ship::Type& type) const noexcept;

        const std::string getPictureNameFromDefense(const core::Defense::Type& type) const noexcept;

        void populatePanel(const std::string& upgradeType,
                           const std::string& upgradeName,
                           const std::string& upgradePicture,
                           const std::string& upgradeDesc,
                           const std::string& upgradeDuration);

        void clearPanel(const std::string& upgradeType,
                        const std::string& upgradeDesc);

      private:

    };

    using UpgradeActionContainerShPtr = std::shared_ptr<UpgradeActionContainer>;
  }
}

#include "UpgradeActionContainer.hxx"

#endif // UPGRADEACTIONCONTAINER_H