#ifndef ABSTRACTBUYINGVIEW_HXX
#define ABSTRACTBUYINGVIEW_HXX

#include "DefenseView.h"
#include "PlanetException.h"
#include "DataModelException.h"
#include "ComponentFactory.h"
#include "FontFactory.h"
#include "SelectorPanel.h"

namespace ogame {
  namespace gui {

    inline
    void AbstractBuyingView::onActionTriggered(const player::GeneralDataModel& model, const player::Action& action) {
      // Process this action.
      try {
        if (action == player::Action::ChangePlanet) {
          const core::Planet& planet = model.getActivePlanet();
          populateWithPlanetData(planet);
        }
        if (action == player::Action::ChangeAccount) {
          const core::Account& account = model.getActiveAccount();
          populateWithAccountData(account);
        }
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[BUYING] Caught exception while setting up view " << getName() << ":" << std::endl << e.what() << std::endl;
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[BUYING] Caught exception while setting up view " << getName() << ":" << std::endl << e.what() << std::endl;
      }
    }

    inline
    void AbstractBuyingView::onInteractionPerformed(const std::string& origin, const view::EventListener::Interaction::Mask& mask) {
      // Notify only relevant interaction.
      if (mask & m_mask) {
        onInteractionPerformedPrivate(origin);
      }
    }

    inline
    void AbstractBuyingView::connectDataModel(const player::Action& action) noexcept {
      try {
        getDataModel().registerForAction(action, this);
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[BUYING] Could not connect container " << getName() << " for action " << static_cast<int>(action) << ":" << std::endl << e.what() << std::endl;
      }
    }

    inline
    BackgroundedLabelShPtr AbstractBuyingView::createBackgroundedLabelContainer(const std::string& name,
                                                                                const std::string& picture,
                                                                                const std::string& text,
                                                                                const bool registerForInteraction)
    {
      // Create the component.
      BackgroundedLabelShPtr label = ComponentFactory::createBackgroundedLabelPanel(
        name,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/upcfb.ttf"),
          219, 140, 40, SDL_ALPHA_OPAQUE
        ),
        picture,
        text,
        SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE},
        BackgroundedLabel::Alignment::BottomRight,
        (registerForInteraction ? view::EventListener::Interaction::MouseButtonReleased : view::EventListener::Interaction::NoInteraction)
      );

      // Register if needed
      if (registerForInteraction) {
        label->addEventListener(this);
      }

      // Return this value.
      return label;
    }

    inline
    void AbstractBuyingView::populateWithPlanetData(const core::Planet& planet) {}

    inline
    void AbstractBuyingView::populateWithAccountData(const core::Account& account) {}

    inline
    void AbstractBuyingView::onInteractionPerformedPrivate(const std::string& origin) {
      bool deactivate = false;

      // Activate the buying panel action.
      SelectorPanel* selector = getChild<SelectorPanel*>(std::string("selector_panel"));
      if (checkChild(selector, std::string("Buying selector panel"))) {
        try {
          // Check whether we should deactivate this child.
          if (m_activeBuyingActionName == origin) {
            deactivate = true;
            m_activeBuyingActionName = "";
            selector->setActiveChild(std::string("image_panel"));
          }
          else {
            m_activeBuyingActionName = origin;
            selector->setActiveChild(std::string("buying_action"));

            // We need to assign the unit count for this panel.
            m_buyingAction->triggerUnitCount();
          }
        }
        catch (const GuiException& e) {
          std::cerr << "[BUYING] Could not activate description item after interaction with " << origin << " in " << getName() << ":" << std::endl << e.what() << std::endl;
        }
      }

      // Update the buying action based on the origin of the action.
      if (m_buyingAction != nullptr && !deactivate) {
        populateActionData(origin, *m_buyingAction);
      }
    }

  }
}

#endif // ABSTRACTBUYINGVIEW_HXX
