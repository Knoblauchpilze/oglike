
#include <iostream>
#include <string>

#include "ArgumentsParser.h"
#include "ArgumentsException.h"

#include "Universe.h"

#include "OgameView.h"
#include "ViewException.h"

int main(int argc, char* argv[])
{
  // Parse input arguments.
  ogame::app::ArgumentsParser parser(std::string("OGameServer"), argc, argv);
  parser.addOption(std::string("galaxy"), true, true);
  parser.addOption(std::string("system"), true, true);
  parser.addOption(std::string("planet"), false, true);

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
  ogame::view::OgameViewShPtr view;
  try {
    view  = std::make_shared<ogame::view::OgameView>(640u, 480u);
  }
  catch (const ogame::view::ViewException& e) {
    std::cerr << "[MAIN] Caught exception:" << std::endl << e.what() << std::endl;
  }
  catch (const ogame::core::OgameException& e) {
    std::cerr << "[MAIN] Caught internal exception:" << std::endl << e.what() << std::endl;
  }

  


  return 0;
}
