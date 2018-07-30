#ifndef RESEARCHVIEW_H
#define RESEARCHVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "AbstractBuyingView.h"
#include "Research.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class ResearchView: public AbstractBuyingView
    {
      public:

        ResearchView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~ResearchView();

      protected:

        void populateActionData(const std::string& origin, ElementDescriptionPanel& action) const override;

      private:

        void createView();

        void populateWithData(const core::Planet& planet, const core::Account& account) override;

        const std::string getDisplayForTech(const core::Research::Type& type, const core::Account& account) const noexcept;

        const core::Research::Type computeResearchFromOriginNode(const std::string& origin) const noexcept;

        const std::string getPictureNameFromResearch(const core::Research::Type& type, const bool reduced = true) const noexcept;

      private:

    };

    using ResearchViewShPtr = std::shared_ptr<ResearchView>;
  }
}

#include "ResearchView.hxx"

#endif // RESEARCHVIEW_H
