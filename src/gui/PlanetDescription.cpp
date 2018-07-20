
#include "PlanetDescription.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "LabelledPicture.h"
#include "ComponentFactory.h"
#include "SystemException.h"

namespace ogame {
  namespace gui {

    PlanetDescription::PlanetDescription(const std::string& name, player::GeneralDataModelShPtr model):
      view::GraphicContainer(name,
                             view::utils::Area()),
      player::GeneralActionListener(model.get())
    {
      createView();

      connectDataModel(model);
    }

    PlanetDescription::~PlanetDescription() {}

    void PlanetDescription::createView() {
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(2u, 7u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create planet description"));
      }

      // Create the navigation panel.
      LabelContainerShPtr diamaterLabel = createInfoLabelPanel(std::string("diameter_label"), std::string("Diameter"));
      LabelContainerShPtr temperatureLabel = createInfoLabelPanel(std::string("temperature_label"), std::string("Temperature"));
      LabelContainerShPtr coordinatesLabel = createInfoLabelPanel(std::string("coordinates_label"), std::string("Coordinates"));
      LabelContainerShPtr pointsLabel = createInfoLabelPanel(std::string("points_label"), std::string("Points"));
      LabelContainerShPtr honourLabel = createInfoLabelPanel(std::string("honour_label"), std::string("Honour points"));

      LabelContainerShPtr diamaterValue = createValueLabelPanel(std::string("diameter_value"), std::string("0 km"));
      LabelContainerShPtr temperatureValue = createValueLabelPanel(std::string("temperature_value"), std::string("0 to 0 degrees"));
      LabelContainerShPtr coordinatesValue = createValueLabelPanel(std::string("coordinates_value"), std::string("[0:0:0]"));
      LabelContainerShPtr pointsValue = createValueLabelPanel(std::string("points_value"), std::string("0"));
      LabelContainerShPtr honourValue = createValueLabelPanel(std::string("honour_value"), std::string("0"));

      LabelledPictureShPtr relocate = createLabelledPicturePanel(
        std::string("move_option"),
        std::string("data/img/relocate_icon.bmp"),
        std::string("Relocate")
      );
      LabelledPictureShPtr settings = createLabelledPicturePanel(
        std::string("settings_option"),
        std::string("data/img/settings_icon.bmp"),
        std::string("Give up/Rename")
      );

      if (diamaterLabel == nullptr ||
          temperatureLabel == nullptr ||
          coordinatesLabel == nullptr ||
          pointsLabel == nullptr ||
          honourLabel == nullptr ||
          diamaterValue == nullptr ||
          temperatureValue == nullptr ||
          coordinatesValue == nullptr ||
          pointsValue == nullptr ||
          honourValue == nullptr ||
          relocate == nullptr ||
          settings == nullptr)
      {
        throw GuiException(std::string("Could not allocate memory to create planet description"));
      }

      layout->addItem(diamaterLabel,    0u, 0u, 1u, 1u);
      addChild(diamaterLabel);
      layout->addItem(temperatureLabel, 0u, 1u, 1u, 1u);
      addChild(temperatureLabel);
      layout->addItem(coordinatesLabel, 0u, 2u, 1u, 1u);
      addChild(coordinatesLabel);
      layout->addItem(pointsLabel,      0u, 3u, 1u, 1u);
      addChild(pointsLabel);
      layout->addItem(honourLabel,      0u, 4u, 1u, 1u);
      addChild(honourLabel);

      layout->addItem(diamaterValue,    1u, 0u, 1u, 1u);
      addChild(diamaterValue);
      layout->addItem(temperatureValue, 1u, 1u, 1u, 1u);
      addChild(temperatureValue);
      layout->addItem(coordinatesValue, 1u, 2u, 1u, 1u);
      addChild(coordinatesValue);
      layout->addItem(pointsValue,      1u, 3u, 1u, 1u);
      addChild(pointsValue);
      layout->addItem(honourValue,      1u, 4u, 1u, 1u);
      addChild(honourValue);

      layout->addItem(relocate,         0u, 6u, 1u, 1u);
      addChild(relocate);
      layout->addItem(settings,         1u, 6u, 1u, 1u);
      addChild(settings);

      setLayout(layout);
    }

    void PlanetDescription::connectDataModel(player::GeneralDataModelShPtr dataModel) {
      dataModel->registerForAction(player::Action::ChangePlanet, this);
    }

    void PlanetDescription::populateWithPlanetData(const core::Planet& planet) {
      lock();

      // Update each information.
      LabelContainer* diameter = getChild<LabelContainer*>(std::string("diameter_value"));
      if (checkChild(diameter, "Planet diameter")) {
        diameter->setText(std::to_string(static_cast<int>(planet.getDiameter())) + " kms");
      }

      LabelContainer* temperature = getChild<LabelContainer*>(std::string("temperature_value"));
      if (checkChild(temperature, "Planet temperature")) {
        temperature->setText(
          std::to_string(static_cast<int>(planet.getMinTemperature())) +
          " to " +
          std::to_string(static_cast<int>(planet.getMaxTemperature())) +
          " degrees"
        );
      }

      LabelContainer* coordinates = getChild<LabelContainer*>(std::string("coordinates_value"));
      if (checkChild(coordinates, "Planet coordinates")) {
        try {
          coordinates->setText(planet.getCoordinates());
        }
        catch (const core::PlanetException& e) {
          std::cerr << "[DESCRIPTION] Could not compute coordinates for planet " << planet.getName() << ": " << std::endl << e.what() << std::endl;
        }
        catch (const core::SystemException& e) {
          std::cerr << "[DESCRIPTION] Could not compute coordinates for planet " << planet.getName() << ": " << std::endl << e.what() << std::endl;
        }
      }

      makeDeepDirty();
      unlock();
    }

  }
}
