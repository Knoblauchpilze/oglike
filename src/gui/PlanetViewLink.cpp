
#include "PlanetViewLink.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "ComponentFactory.h"
#include "FontFactory.h"
#include "PlanetException.h"
#include "SystemException.h"

namespace ogame {
  namespace gui {

    PlanetViewLink::PlanetViewLink(const std::string& name,
                                   const unsigned& planetCount,
                                   const StateContainer::StateAssociation& colors):
      StateContainer(name,
                     StateContainer::State::Normal,
                     colors)
    {
      setBackgroundColor(SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE});

      createView(planetCount);
    }

    PlanetViewLink::~PlanetViewLink() {}

    void PlanetViewLink::populateWithPlanetData(const core::Planet& planet) {
      lock();

      // Update each information.
      PlanetIconDisplay* picture = getChild<PlanetIconDisplay*>(std::string("planet_picture"));
      if (checkChild(picture, "Planet picture")) {
        picture->populateWithPlanetData(planet);
      }

      StateLabelContainer* name = getChild<StateLabelContainer*>(std::string("planet_name"));
      if (checkChild(name, "Planet name")) {
        name->setText(planet.getName());
      }

      StateLabelContainer* coords = getChild<StateLabelContainer*>(std::string("planet_coords"));
      if (checkChild(coords, "Planet name")) {
        try {
          coords->setText(planet.getCoordinates());
        }
        catch (const core::PlanetException& e) {
          std::cerr << "[LINK] Could not compute coordinates for planet " << planet.getName() << ": " << std::endl << e.what() << std::endl;
        }
        catch (const core::SystemException& e) {
          std::cerr << "[LINK] Could not compute coordinates for planet " << planet.getName() << ": " << std::endl << e.what() << std::endl;
        }
      }

      SwitchPictureContainer* moon = getChild<SwitchPictureContainer*>(std::string("planet_moon"));
      if (checkChild(moon, "Planet moon")) {
        moon->updateStatus(planet.hasMoon());
      }

      makeDeepDirty();
      unlock();
    }

    void PlanetViewLink::createView(const unsigned& planetCount)
    {
      // Create the main layout.
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(4u, 2u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not create layout for container" ) + getName());
      }

      StateLabelContainer::FontAssociation textColors;
      textColors[StateContainer::State::Normal]      = view::FontFactory::getInstance().createColoredFont(
        std::string("data/fonts/times.ttf"),
        85, 126, 148, SDL_ALPHA_OPAQUE,
        13
      );
      textColors[StateContainer::State::Highlighted] = view::FontFactory::getInstance().createColoredFont(
        std::string("data/fonts/times.ttf"),
        0, 64, 0, SDL_ALPHA_OPAQUE,
        13
      );
      textColors[StateContainer::State::Selected]    = view::FontFactory::getInstance().createColoredFont(
        std::string("data/fonts/times.ttf"),
        0, 32, 0, SDL_ALPHA_OPAQUE,
        13
      );

      // Create the planet info.
      PlanetIconDisplayShPtr planet = std::make_shared<PlanetIconDisplay>(planetCount, std::string("planet_picture"));

      StateLabelContainerShPtr name = ComponentFactory::createStateLabelPanel(
        std::string("planet_name"),
        std::string("Default planet name"),
        textColors
      );

      StateLabelContainerShPtr coord = ComponentFactory::createStateLabelPanel(
        std::string("planet_coords"),
        std::string("[X:YYY:ZZ]"),
        textColors
      );

      SwitchPictureContainerShPtr moon = ComponentFactory::createSwitchPicturePanel(
        std::string("planet_moon"),
        std::string("data/img/moon.bmp"),
        std::string("data/img/moon_none.bmp")
      );

      if (planet == nullptr ||
          name == nullptr ||
          coord == nullptr ||
          moon == nullptr)
      {
        throw GuiException(std::string("Could not create one or more component for planet link ") + getName());
      }

      layout->addItem(planet, 0u, 0u, 1u, 2u);
      addChild(planet);
      layout->addItem(name, 1u, 0u, 2u, 1u);
      addChild(name);
      layout->addItem(coord, 1u, 1u, 2u, 1u);
      addChild(coord);
      layout->addItem(moon, 3u, 0u, 1u, 2u);
      addChild(moon);

      setLayout(layout);
    }

  }
}
