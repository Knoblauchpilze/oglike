#ifndef UPGRADEACTIONCONTAINER_H
#define UPGRADEACTIONCONTAINER_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "LabelContainer.h"
#include "Planet.h"

namespace ogame {
  namespace gui {

    class UpgradeActionContainer: public view::GraphicContainer
    {
      public:

        UpgradeActionContainer(const std::string& name);

        virtual ~UpgradeActionContainer();

        void populateWithBuildingData(const core::Planet& planet);

        void populateWithResearchData(const core::Account& account);

        void populateWithShipyardData(const core::Planet& planet);

      private:

        void createView();

        LabelContainerShPtr createLabel(const std::string& name,
                                        const std::string& text,
                                        const SDL_Color& color,
                                        const LabelContainer::Alignment& alignment = LabelContainer::Alignment::Left) const;

        const std::string computeDisplayTime(const float& seconds) const;

        const std::string getPictureNameFromBuilding(const core::Building::Type& type) const noexcept;

        const std::string getPictureNameFromResearch(const core::Research::Type& type) const noexcept;

      private:

    };

    using UpgradeActionContainerShPtr = std::shared_ptr<UpgradeActionContainer>;
  }
}

#include "UpgradeActionContainer.hxx"

#endif // UPGRADEACTIONCONTAINER_H