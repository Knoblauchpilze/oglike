
#include <iostream>
#include <string>

#include "ArgumentsParser.h"
#include "ArgumentsException.h"

#include "Universe.h"

#include "OgameAbstractView.h"
#include "ViewException.h"

#include "Area.h"
#include "GraphicContainer.h"
#include "LinearLayout.h"

int main(int argc, char* argv[])
{
  // Parse input arguments.
  ogame::app::ArgumentsParser parser(std::string("OGameServer"), argc, argv);
  parser.addOption(std::string("galaxy"), true, true);
  parser.addOption(std::string("system"), true, true);
  parser.addOption(std::string("planet"), true, true);
  parser.addOption(std::string("width"), true, true);
  parser.addOption(std::string("height"), true, true);

  try {
    parser.parseArguments();
  }
  catch (const ogame::app::ArgumentsException& e) {
    std::cerr << "[MAIN] Caught exception:" << std::endl << e.what() << std::endl;
    parser.displayUsage(std::cout);
  }
  catch (const ogame::core::OgameException& e) {
    std::cerr << "[MAIN] Caught internal exception:" << std::endl << e.what() << std::endl;
  }

  const unsigned galaxiesCount = std::stoi(parser.getOptionValue("--galaxy"));
  const unsigned systemsCount = std::stoi(parser.getOptionValue("--system"));
  const unsigned planetsCount = std::stoi(parser.getOptionValue("--planet"));
  std::cout << "[INFO] Instanciating universe with " << galaxiesCount << " galaxies, " << systemsCount << " systems per galaxy and " << planetsCount << " planets per system" << std::endl;

  ogame::core::UniverseShPtr universe = std::make_shared<ogame::core::Universe>(1u, galaxiesCount);

  // Instantiate the main view.
  const unsigned screenWidth = std::stoi(parser.getOptionValue("--width"));
  const unsigned screenHeight = std::stoi(parser.getOptionValue("--height"));
  ogame::view::OgameAbstractViewShPtr view;
  ogame::view::GraphicContainerShPtr panel;

  std::vector<ogame::view::GraphicContainerShPtr> containersForLayout;
  ogame::view::LayoutShPtr layout;

  const float margin = 1.0f;
  const ogame::view::utils::Area panelArea(margin,
                                           margin,
                                           static_cast<float>(screenWidth) - 2.0f * margin,
                                           static_cast<float>(screenHeight) - 2.0f * margin);
  try {
    view  = std::make_shared<ogame::view::OgameAbstractView>("OGame Viewer", "65px-Stop_hand.svg[1].BMP", screenWidth, screenHeight);

    layout = std::make_shared<ogame::view::LinearLayout>(ogame::view::LinearLayout::Direction::Horizontal,
                                                         1.0f,
                                                         2.0f,
                                                         nullptr);

    panel = std::make_shared<ogame::view::GraphicContainer>("Main panel",
                                                            panelArea,
                                                            layout.get());
    view->addDrawable(panel.get());

    containersForLayout.push_back(
      std::make_shared<ogame::view::GraphicContainer>(
        "Panel 0",
        ogame::view::utils::Area()
      )
    );
    containersForLayout.push_back(
      std::make_shared<ogame::view::GraphicContainer>(
        "Panel 1",
        ogame::view::utils::Area()
      )
    );
    containersForLayout.push_back(
      std::make_shared<ogame::view::GraphicContainer>(
        "Panel 2",
        ogame::view::utils::Area()
      )
    );
    containersForLayout.push_back(
      std::make_shared<ogame::view::GraphicContainer>(
        "Panel 3",
        ogame::view::utils::Area()
      )
    );

    for (int indexPanel = 0 ; indexPanel < containersForLayout.size() ; ++indexPanel) {
      panel->addChild(containersForLayout[indexPanel].get());
    }
  }
  catch (const ogame::view::ViewException& e) {
    std::cerr << "[MAIN] Caught exception:" << std::endl << e.what() << std::endl;
    return 1;
  }
  catch (const ogame::core::OgameException& e) {
    std::cerr << "[MAIN] Caught internal exception:" << std::endl << e.what() << std::endl;
    return 1;
  }

  // Run the application.
  try {
    view->run();
  }
  catch (const ogame::view::ViewException& e) {
    std::cerr << "[MAIN] Caught exception:" << std::endl << e.what() << std::endl;
  }
  catch (const ogame::core::OgameException& e) {
    std::cerr << "[MAIN] Caught internal exception:" << std::endl << e.what() << std::endl;
  }

  return 0;
}
