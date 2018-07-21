#ifndef RESEARCHVIEW_HXX
#define RESEARCHVIEW_HXX

#include "ResearchView.h"
#include "PlanetException.h"
#include "DataModelException.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    void ResearchView::onActionTriggered(const player::GeneralDataModel& model) {
      // Process this action.
      try {
        const core::Account& account = model.getActiveAccount();
        const core::Planet& planet = model.getActivePlanet();
        populateWithAccountData(account, planet);
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[RESEARCH] Caught exception while setting up buildings view:" << std::endl << e.what() << std::endl;
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[RESEARCH] Caught exception while setting up buildings view:" << std::endl << e.what() << std::endl;
      }
    }

    inline
    LabelledPictureShPtr ResearchView::createLabelledPictureContainer(const std::string& name,
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

    inline
    const std::string ResearchView::getDisplayForTech(const core::Research::Type& type, const core::Account& account) const noexcept {
      return std::to_string(account.getLevelForTechnology(type));
    }

  }
}

#endif // RESEARCHVIEW_HXX
