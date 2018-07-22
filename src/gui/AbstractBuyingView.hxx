#ifndef ABSTRACTBUYINGVIEW_HXX
#define ABSTRACTBUYINGVIEW_HXX

#include "DefenseView.h"
#include "PlanetException.h"
#include "DataModelException.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

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
    LabelledPictureShPtr AbstractBuyingView::createLabelledPictureContainer(const std::string& name,
                                                                            const std::string& picture,
                                                                            const std::string& text) const
    {
      return ComponentFactory::createLabelledPicturePanel(
        name,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/upcfb.ttf"),
          219, 140, 40, SDL_ALPHA_OPAQUE
        ),
        picture,
        text,
        LabelledPicture::Alignment::Above
      );
    }

  }
}

#endif // ABSTRACTBUYINGVIEW_HXX
