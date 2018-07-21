#ifndef FLEETVIEW_HXX
#define FLEETVIEW_HXX

#include "FleetView.h"
#include "PlanetException.h"
#include "DataModelException.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    void FleetView::onActionTriggered(const player::GeneralDataModel& model) {
      // Process this action.
      try {
        const core::Planet& planet = model.getActivePlanet();
        populateWithPlanetData(planet);
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[FLEET] Caught exception while setting up fleet view:" << std::endl << e.what() << std::endl;
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[FLEET] Caught exception while setting up fleet view:" << std::endl << e.what() << std::endl;
      }
    }

    inline
    LabelledPictureShPtr FleetView::createLabelledPictureContainer(const std::string& name,
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
    const std::string FleetView::getShipCountFromType(const core::Ship::Type& type, const core::Planet& planet) const noexcept {
      return std::to_string(planet.getShipCount(type));
    }

  }
}

#endif // FLEETVIEW_HXX
