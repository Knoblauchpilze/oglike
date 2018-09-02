#ifndef DEFENSEVIEW_H
#define DEFENSEVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "AbstractBuyingView.h"
#include "Defense.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class DefenseView: public AbstractBuyingView
    {
      public:

        DefenseView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~DefenseView();

      protected:

        void populateActionData(const std::string& origin, ElementDescriptionPanel& action) const override;

      private:

        void createView();

        void populateWithPlanetData(const core::Planet& planet) override;

        const std::string getDefenseCountFromType(const core::Defense::Type& type, const core::Planet& planet) const noexcept;

        const core::Defense::Type computeDefenseFromOriginNode(const std::string& origin) const noexcept;

        const std::string getPictureNameFromDefense(const core::Defense::Type& type, const bool reduced = true) const noexcept;

      private:

    };

    using DefenseViewShPtr = std::shared_ptr<DefenseView>;
  }
}

#include "DefenseView.hxx"

#endif // DEFENSEVIEW_H
