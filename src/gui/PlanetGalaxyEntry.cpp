
#include "PlanetGalaxyEntry.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    PlanetGalaxyEntry::PlanetGalaxyEntry(const unsigned& index, const unsigned& count, const std::string& name):
      view::GraphicContainer(name,
                             view::utils::Area())
    {
      // Assign the background color.
      setBackgroundColor(SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE});

      createView(index, count);
    }

    PlanetGalaxyEntry::~PlanetGalaxyEntry() {}

    void PlanetGalaxyEntry::populateWithPlanetData(const core::Planet& planet) {
      lock();

      // Update information.
      PlanetIconDisplay* icon = getChild<PlanetIconDisplay*>(std::string("Planet icon"));
      if (checkChild(icon, std::string("Planet icon"))) {
        icon->populateWithPlanetData(planet);
      }
      LabelContainer* label = getChild<LabelContainer*>(std::string("Planet name"));
      if (checkChild(label, std::string("Planet name"))) {
        label->setText(planet.isColonized() ? planet.getName() : "");
      }
      SwitchPictureContainer* moon = getChild<SwitchPictureContainer*>(std::string("Planet moon"));
      if (checkChild(moon, std::string("Planet moon"))) {
        moon->updateStatus(planet.hasMoon());
      }
      SwitchPictureContainer* wreckfield = getChild<SwitchPictureContainer*>(std::string("Planet wreck field"));
      if (checkChild(wreckfield, std::string("Planet wreck field"))) {
        wreckfield->updateStatus(planet.hasWreckfield());
      }
      LabelContainer* owner = getChild<LabelContainer*>(std::string("Planet owner's name"));
      if (checkChild(label, std::string("Planet owner's name"))) {
        try {
          owner->setText(planet.isColonized() ? planet.getOwnerName() : "");
        }
        catch (const core::PlanetException& e) {
          std::cerr << "[ENTRY] Caught error while updating owner's name:" << std::endl << e.what() << std::endl;
        }
      }
      PlanetActionList* actions = getChild<PlanetActionList*>(std::string("Planet actions"));
      if (checkChild(label, std::string("Planet actions"))) {
        actions->updateStatus(planet);
      }

      // Make this component dirty.
      makeDeepDirty();

      unlock();
    }

    void PlanetGalaxyEntry::createView(const unsigned& index, const unsigned& count) {
      // Create the main layout for this panel.
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(12u, 1u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create planet's panel"));
      }

      // Add each informative panel to the layout and as child of this panel.
      LabelContainerShPtr position = createLabelPanel(std::string("Planet index"),
                                                      std::to_string(index),
                                                      view::FontFactory::getInstance().createColoredFont(
                                                        std::string("data/fonts/upcfb.ttf"),
                                                        192, 0, 0
                                                      ));

      PlanetIconDisplayShPtr icon = createPlanetIconPanel(count, std::string("Planet icon"));

      LabelContainerShPtr name = createLabelPanel(std::string("Planet name"),
                                                  std::string(""),
                                                  view::FontFactory::getInstance().createColoredFont(
                                                    std::string("data/fonts/upcfb.ttf"),
                                                    128, 0, 0
                                                  ));

      SwitchPictureContainerShPtr wreckField = createSwitchPicture(std::string("Planet wreck field"),
                                                                   std::string("data/img/wreckfield.bmp"),
                                                                   std::string("data/img/wreckfield_none.bmp"));

      SwitchPictureContainerShPtr moon = createSwitchPicture(std::string("Planet moon"),
                                                             std::string("data/img/moon.bmp"),
                                                             std::string("data/img/moon_none.bmp"));

      LabelContainerShPtr owner = createLabelPanel(std::string("Planet owner's name"),
                                                   std::string(""),
                                                   view::FontFactory::getInstance().createColoredFont(
                                                     std::string("data/fonts/upcfb.ttf"),
                                                     255, 0, 0
                                                   ));

      PlanetActionListShPtr actions = createActionList(std::string("Planet actions"));

      if (position == nullptr ||
          icon == nullptr ||
          name == nullptr ||
          wreckField == nullptr ||
          moon == nullptr ||
          owner == nullptr ||
          actions == nullptr)
      {
        throw GuiException(std::string("Could not allocate one of the informative panel for planet's panel"));
      }

      addChild(position);
      layout->addItem(position,      0u, 0u, 1u, 1u);
      addChild(icon);
      layout->addItem(icon,       1u, 0u, 1u, 1u);
      addChild(name);
      layout->addItem(name,       2u, 0u, 3u, 1u);
      addChild(moon);
      layout->addItem(moon,       5u, 0u, 1u, 1u);
      addChild(wreckField);
      layout->addItem(wreckField, 6u, 0u, 1u, 1u);
      addChild(owner);
      layout->addItem(owner,      7u, 0u, 3u, 1u);
      addChild(actions);
      layout->addItem(actions,    10u, 0u, 2u, 1u);

      // Now assign the layout to this container.
      setLayout(layout);
    }

  }
}
