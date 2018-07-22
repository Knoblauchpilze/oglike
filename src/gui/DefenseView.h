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

      private:

        void createView(player::GeneralDataModelShPtr model);

        void connectDataModel(player::GeneralDataModelShPtr dataModel);

        void populateWithData(const core::Planet& planet, const core::Account& account) override;

        const std::string getDefenseCountFromType(const core::Defense::Type& type, const core::Planet& planet) const noexcept;

      private:

    };

    using DefenseViewShPtr = std::shared_ptr<DefenseView>;
  }
}

#include "DefenseView.hxx"

#endif // DEFENSEVIEW_H
