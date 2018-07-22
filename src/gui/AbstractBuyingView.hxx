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
    void AbstractBuyingView::onActionTriggered(const player::GeneralDataModel& model) {
      // Process this action.
      try {
        const core::Planet& planet = model.getActivePlanet();
        const core::Account& account = model.getActiveAccount();
        populateWithData(planet, account);
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[DEFENSE] Caught exception while setting up defense view:" << std::endl << e.what() << std::endl;
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[DEFENSE] Caught exception while setting up defense view:" << std::endl << e.what() << std::endl;
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
        getDataModel().registerForAction(player::Action::ChangePlanet, this);
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[BUYING] Could not connect container " << getName() << " for action " << static_cast<int>(action) << ":" << std::endl << e.what() << std::endl;
      }
    }

    inline
    LabelledPictureShPtr AbstractBuyingView::createLabelledPictureContainer(const std::string& name,
                                                                            const std::string& picture,
                                                                            const std::string& text,
                                                                            const bool registerForInteraction)
    {
      // Create the component.
      LabelledPictureShPtr label = ComponentFactory::createLabelledPicturePanel(
        name,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/upcfb.ttf"),
          219, 140, 40, SDL_ALPHA_OPAQUE
        ),
        picture,
        text,
        LabelledPicture::Alignment::Above,
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
