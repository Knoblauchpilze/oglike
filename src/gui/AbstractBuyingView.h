#ifndef ABSTRACTBUYINGVIEW_H
#define ABSTRACTBUYINGVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "DataModelImplementation.h"
#include "LabelledPicture.h"

namespace ogame {
  namespace gui {

    class AbstractBuyingView: public view::GraphicContainer, public player::GeneralActionListener
    {
      public:

        AbstractBuyingView(const std::string& name, player::GeneralDataModelShPtr model);

        virtual ~AbstractBuyingView();

        void onActionTriggered(const player::GeneralDataModel& model) override;

      protected:

        LabelledPictureShPtr createLabelledPictureContainer(const std::string& name,
                                                            const std::string& picture,
                                                            const std::string& text) const;

        virtual void populateWithData(const core::Planet& planet, const core::Account& account) = 0;

      private:

    };

    using AbstractBuyingViewShPtr = std::shared_ptr<AbstractBuyingView>;
  }
}

#include "AbstractBuyingView.hxx"

#endif // ABSTRACTBUYINGVIEW_H
