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

      private:

        void createView();

        void populateWithData(const core::Planet& planet, const core::Account& account) override;

        const std::string getDisplayForTech(const core::Research::Type& type, const core::Account& account) const noexcept;

      private:

    };

    using ResearchViewShPtr = std::shared_ptr<ResearchView>;
  }
}

#include "ResearchView.hxx"

#endif // RESEARCHVIEW_H
