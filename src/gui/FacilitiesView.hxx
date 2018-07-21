#ifndef FACILITIESVIEW_HXX
#define FACILITIESVIEW_HXX

#include "FacilitiesView.h"
#include "PlanetException.h"
#include "DataModelException.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    void FacilitiesView::onActionTriggered(const player::GeneralDataModel& model) {
      // Process this action.
      try {
        const core::Planet& planet = model.getActivePlanet();
        populateWithPlanetData(planet);
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[FACILITIES] Caught exception while setting up buildings view:" << std::endl << e.what() << std::endl;
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[FACILITIES] Caught exception while setting up buildings view:" << std::endl << e.what() << std::endl;
      }
    }

    inline
    LabelledPictureShPtr FacilitiesView::createLabelledPictureContainer(const std::string& name,
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

#endif // FACILITIESVIEW_HXX
