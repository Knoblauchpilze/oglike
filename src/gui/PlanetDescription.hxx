#ifndef PLANETDESCRIPTION_HXX
#define PLANETDESCRIPTION_HXX

#include "PlanetDescription.h"
#include "DataModelException.h"
#include "PlanetException.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    inline
    void PlanetDescription::onActionTriggered(const player::GeneralDataModel& model) {
      try {
        const core::Planet& planet = model.getActivePlanet();
        populateWithPlanetData(planet);
      }
      catch (const core::PlanetException& e) {
        std::cerr << "[DESCRIPTION] Caught internal error while populating planet description view:" << std::endl << e.what() << std::endl;
      }
      catch (const player::DataModelException& e) {
        std::cerr << "[DESCRIPTION] Caught internal error while populating planet description view:" << std::endl << e.what() << std::endl;
      }
    }

    inline
    LabelContainerShPtr PlanetDescription::createInfoLabelPanel(const std::string& name, const std::string& text) const {
      return createLabelPanel(name, text, 96, 159, 197, SDL_ALPHA_OPAQUE, LabelContainer::Alignment::Right);
    }

    inline
    LabelContainerShPtr PlanetDescription::createValueLabelPanel(const std::string& name, const std::string& text) const {
      return createLabelPanel(name, text, 255, 255, 255, SDL_ALPHA_OPAQUE, LabelContainer::Alignment::Right);
    }

    inline
    LabelContainerShPtr PlanetDescription::createLabelPanel(const std::string& name,
                                                            const std::string& text,
                                                            const int& red,
                                                            const int& green,
                                                            const int& blue,
                                                            const int& alpha,
                                                            const LabelContainer::Alignment& alignment) const
    {
      return ComponentFactory::createLabelPanel(
        name,
        text,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/angsa.ttf"),
          red, green, blue, alpha
        ),
        alignment
      );
    }

    inline
    LabelledPictureShPtr PlanetDescription::createLabelledPicturePanel(const std::string& name,
                                                                       const std::string& picture,
                                                                       const std::string& text) const
    {
      return ComponentFactory::createLabelledPicturePanel(
        name,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/angsa.ttf"),
          255, 255, 255, SDL_ALPHA_OPAQUE
        ),
        picture,
        text,
        LabelledPicture::Alignment::Left
      );
    }

  }
}

#endif // PLANETDESCRIPTION_HXX
