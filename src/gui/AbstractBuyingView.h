#ifndef ABSTRACTBUYINGVIEW_H
#define ABSTRACTBUYINGVIEW_H

#include <memory>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "DataModelImplementation.h"
#include "BackgroundedLabel.h"
#include "GraphicContainerListener.h"
#include "ElementDescriptionPanel.h"

namespace ogame {
  namespace gui {

    class AbstractBuyingView: public view::GraphicContainer, public player::GeneralActionListener, public view::GraphicContainerListener
    {
      public:

        AbstractBuyingView(const std::string& name,
                           player::GeneralDataModelShPtr model,
                           const unsigned& gridWidth,
                           const unsigned& gridHeight,
                           const std::string& mainImageFile,
                           const view::EventListener::Interaction::Mask& mask = view::EventListener::Interaction::Mouse);

        virtual ~AbstractBuyingView();

        void onActionTriggered(const player::GeneralDataModel& model, const player::Action& action) override;

        void onInteractionPerformed(const std::string& origin, const view::EventListener::Interaction::Mask& mask) override;

      protected:

        void connectDataModel(const player::Action& action) noexcept;

        BackgroundedLabelShPtr createBackgroundedLabelContainer(const std::string& name,
                                                                const std::string& picture,
                                                                const std::string& text,
                                                                const bool registerForInteraction = true);

        virtual void populateWithPlanetData(const core::Planet& planet);

        virtual void populateWithAccountData(const core::Account& account);

        virtual void onInteractionPerformedPrivate(const std::string& origin);

        virtual void populateActionData(const std::string& origin, ElementDescriptionPanel& action) const = 0;

      private:

        void createView(player::GeneralDataModelShPtr model,
                        const unsigned& gridWidth,
                        const unsigned& gridHeight,
                        const std::string& mainImageFile);

      private:

        view::EventListener::Interaction::Mask m_mask;
        ElementDescriptionPanelShPtr m_buyingAction;
        std::string m_activeBuyingActionName;

    };

    using AbstractBuyingViewShPtr = std::shared_ptr<AbstractBuyingView>;
  }
}

#include "AbstractBuyingView.hxx"

#endif // ABSTRACTBUYINGVIEW_H
