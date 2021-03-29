
#include "GalaxyNavigationPanel.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "ComponentFactory.h"
#include "SystemException.h"
#include "GalaxyPlayerData.h"

namespace ogame {
  namespace gui {

    GalaxyNavigationPanel::GalaxyNavigationPanel(const std::string& name,
                                                 const unsigned& galaxyCount,
                                                 const unsigned& systemCount,
                                                 player::GeneralDataModelShPtr model):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::MouseButton),
      player::GeneralActionListener(model.get()),
      view::GraphicContainerListener()
    {
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});

      createView(galaxyCount, systemCount);

      connectDataModel(model);
    }

    GalaxyNavigationPanel::~GalaxyNavigationPanel() {
      // Nothing to do here.
    }

    void GalaxyNavigationPanel::populateWithSystemData(const core::System& system) {
      lock();

      ValueSelector* galaxySelector = getChild<ValueSelector*>(std::string("galaxy_selector"));
      if (checkChild(galaxySelector, std::string("Galaxy selector"))) {
        try {
          galaxySelector->setActiveOption(system.getGalaxyIndex());
        }
        catch (const core::SystemException& e) {
          std::cerr << "[NAVIGATION] Could not update galaxy selector:" << std::endl << e.what() << std::endl;
        }
        catch (const GuiException& e) {
          std::cerr << "[NAVIGATION] Could not update galaxy selector: " << std::endl << e.what() << std::endl;
        }
      }

      ValueSelector* systemSelector = getChild<ValueSelector*>(std::string("system_selector"));
      if (checkChild(systemSelector, std::string("System selector"))) {
        try {
          systemSelector->setActiveOption(system.getIndex());
        }
        catch (const core::SystemException& e) {
          std::cerr << "[NAVIGATION] Could not update system selector:" << std::endl << e.what() << std::endl;
        }
        catch (const GuiException& e) {
          std::cerr << "[NAVIGATION] Could not update system selector: " << std::endl << e.what() << std::endl;
        }
      }

      makeDeepDirty();
      unlock();
    }

    void GalaxyNavigationPanel::populateWithPlanetData(const core::Planet& planet) {
      lock();

      GalaxyPlayerData* playerData = getChild<GalaxyPlayerData*>(std::string("player_data"));
      if (checkChild(playerData, std::string("Player data"))) {
        playerData->populateWithPlanetData(planet);
      }

      makeDeepDirty();
      unlock();
    }

    void GalaxyNavigationPanel::createView(const unsigned& galaxyCount,
                                           const unsigned& systemCount)
    {
      // Create the main layout for this panel.
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(4u, 4u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create galaxy's navigation panel"));
      }

      // Add each informative panel to the layout and as child of this panel.
      LabelContainerShPtr galaxy = createLabelPanel(std::string("galaxy_label"),
                                                    std::string("Galaxy"),
                                                    view::FontFactory::getInstance().createColoredFont(
                                                      std::string("data/fonts/ARLRDBD.ttf"),
                                                      0, 0, 64, SDL_ALPHA_OPAQUE,
                                                      20
                                                    ));
      LabelContainerShPtr system = createLabelPanel(std::string("system_label"),
                                                    std::string("System"),
                                                    view::FontFactory::getInstance().createColoredFont(
                                                      std::string("data/fonts/ARLRDBD.ttf"),
                                                      0, 0, 64, SDL_ALPHA_OPAQUE,
                                                      20
                                                    ));

      std::vector<std::string> galaxies;
      for (unsigned galaxy = 0u ; galaxy < galaxyCount ; ++galaxy) {
        galaxies.push_back(std::to_string(galaxy + 1));
      }
      ValueSelectorShPtr galaxySelector = createValueSelector(std::string("galaxy_selector"),
                                                              view::FontFactory::getInstance().createColoredFont(
                                                                std::string("data/fonts/ARLRDBD.ttf"),
                                                                0, 0, 0
                                                              ),
                                                              galaxies);

      std::vector<std::string> systems;
      for (unsigned system = 0u ; system < systemCount ; ++system) {
        systems.push_back(std::to_string(system + 1));
      }
      ValueSelectorShPtr systemSelector = createValueSelector(std::string("system_selector"),
                                                              view::FontFactory::getInstance().createColoredFont(
                                                                std::string("data/fonts/ARLRDBD.ttf"),
                                                                0, 0, 0
                                                              ),
                                                              systems);

      view::GraphicContainerShPtr information = nullptr;
      try {
        information = createLabelForSystemView();
      }
      catch (const GuiException& e) {
        std::cerr << "[NAVIGATION] Could not create system navigation information panel:" << std::endl << e.what() << std::endl;
        information = nullptr;
      }

      GalaxyPlayerDataShPtr playerData = nullptr;
      try {
        playerData = std::make_shared<GalaxyPlayerData>(std::string("player_data"));
      }
      catch (const GuiException& e) {
        std::cerr << "[NAVIGATION] Could not create player data information panel:" << std::endl << e.what() << std::endl;
        playerData = nullptr;
      }

      if (galaxy == nullptr ||
          system == nullptr ||
          galaxySelector == nullptr ||
          systemSelector == nullptr ||
          information == nullptr ||
          playerData == nullptr)
      {
        throw GuiException(std::string("Could not allocate one of the informative panel for galaxy's navigation panel"));
      }

      galaxySelector->addEventListener(this);
      systemSelector->addEventListener(this);

      layout->addItem(galaxy,           0u, 0u, 1u, 1u);
      addChild(galaxy);
      layout->addItem(system,           1u, 0u, 1u, 1u);
      addChild(system);
      layout->addItem(galaxySelector,   0u, 1u, 1u, 1u);
      addChild(galaxySelector);
      layout->addItem(systemSelector,   1u, 1u, 1u, 1u);
      addChild(systemSelector);
      layout->addItem(playerData,       0u, 2u, 4u, 1u);
      addChild(playerData);
      layout->addItem(information,      0u, 3u, 4u, 1u);
      addChild(information);

      // Now assign the layout to this container.
      setLayout(layout);
    }

    void GalaxyNavigationPanel::connectDataModel(player::GeneralDataModelShPtr model) {
      model->registerForAction(player::Action::ChangePlanet, this);
    }

    view::GraphicContainerShPtr GalaxyNavigationPanel::createLabelForSystemView() const {
      // Create a default container.
      view::GraphicContainerShPtr information = std::make_shared<view::GraphicContainer>(
        std::string("system_view_label_panel"),
        view::utils::Area()
      );

      // Create the main layout for this panel.
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(12u, 1u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not create label for system view"));
      }

      // Add each informative panel to the layout and as child of this panel.
      LabelContainerShPtr index = createLabelPanel(std::string("planet_label"),
                                                   std::string("Planet"),
                                                   view::FontFactory::getInstance().createColoredFont(
                                                     std::string("data/fonts/ARLRDBD.ttf"),
                                                     128, 128, 128, SDL_ALPHA_OPAQUE,
                                                     20
                                                   ));

      LabelContainerShPtr name = createLabelPanel(std::string("planet_name_label"),
                                                  std::string("Name"),
                                                  view::FontFactory::getInstance().createColoredFont(
                                                    std::string("data/fonts/ARLRDBD.ttf"),
                                                    128, 128, 128, SDL_ALPHA_OPAQUE,
                                                    20
                                                  ));

      LabelContainerShPtr moon = createLabelPanel(std::string("planet_moon"),
                                                  std::string("Moon"),
                                                  view::FontFactory::getInstance().createColoredFont(
                                                    std::string("data/fonts/ARLRDBD.ttf"),
                                                    128, 128, 128, SDL_ALPHA_OPAQUE,
                                                    20
                                                  ));

      LabelContainerShPtr wreckField = createLabelPanel(std::string("Planet wreck field"),
                                                        std::string("Debris"),
                                                        view::FontFactory::getInstance().createColoredFont(
                                                          std::string("data/fonts/ARLRDBD.ttf"),
                                                          128, 128, 128, SDL_ALPHA_OPAQUE,
                                                          20
                                                        ));

      LabelContainerShPtr owner = createLabelPanel(std::string("planet_player"),
                                                   std::string("Player (status)"),
                                                   view::FontFactory::getInstance().createColoredFont(
                                                     std::string("data/fonts/ARLRDBD.ttf"),
                                                     128, 128, 128, SDL_ALPHA_OPAQUE,
                                                     20
                                                   ));

      LabelContainerShPtr actions = createLabelPanel(std::string("planet_actions"),
                                                     std::string("Actions"),
                                                     view::FontFactory::getInstance().createColoredFont(
                                                       std::string("data/fonts/ARLRDBD.ttf"),
                                                       128, 128, 128, SDL_ALPHA_OPAQUE,
                                                       20
                                                     ));

      information->addChild(index);
      layout->addItem(index,      0u, 0u, 2u, 1u);
      information->addChild(name);
      layout->addItem(name,       2u, 0u, 3u, 1u);
      information->addChild(moon);
      layout->addItem(moon,       5u, 0u, 1u, 1u);
      information->addChild(wreckField);
      layout->addItem(wreckField, 6u, 0u, 1u, 1u);
      information->addChild(owner);
      layout->addItem(owner,      7u, 0u, 3u, 1u);
      information->addChild(actions);
      layout->addItem(actions,    10u, 0u, 2u, 1u);

      information->setLayout(layout);

      return information;
    }

  }
}
