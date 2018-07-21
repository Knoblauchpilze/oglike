#ifndef SHIPYARDVIEW_HXX
#define SHIPYARDVIEW_HXX

#include "ShipyardView.h"
#include "PlanetException.h"
#include "DataModelException.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    void ShipyardView::onActionTriggered(const player::GeneralDataModel& model) {
      // Process this action.
      try {
        const core::Planet& planet = model.getActivePlanet();
        populateWithPlanetData(planet);
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[SHIPYARD] Caught exception while setting up shipyard view:" << std::endl << e.what() << std::endl;
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[SHIPYARD] Caught exception while setting up shipyard view:" << std::endl << e.what() << std::endl;
      }
    }

    inline
    LabelledPictureShPtr ShipyardView::createLabelledPictureContainer(const std::string& name,
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
    const std::string ShipyardView::getShipCountFromType(const core::Ship::Type& type, const core::Planet& planet) const noexcept {
      return std::to_string(planet.getShipCount(type));
    }

  }
}

#endif // SHIPYARDVIEW_HXX
