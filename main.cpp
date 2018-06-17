
#include <iostream>
#include <string>

#include "ArgumentsParser.h"
#include "ArgumentsException.h"

#include "UniverseException.h"
#include "GalaxyException.h"
#include "SystemException.h"
#include "PlanetException.h"
#include "Universe.h"

int main(int argc, char* argv[])
{
  app::arguments::ArgumentsParser parser(std::string("OGameServer"), argc, argv);

  parser.addOption(std::string("galaxy"), true, true);
  parser.addOption(std::string("system"), true, true);
  parser.addOption(std::string("planet"), false, true);
  parser.addOption(std::string("demo"), false, false);

  try {
    parser.parseArguments();

    const unsigned galaxiesCount = std::stoi(parser.getOptionValue("--galaxy"));
    const unsigned systemsCount = std::stoi(parser.getOptionValue("--system"));
    const unsigned planetsCount = std::stoi(parser.getOptionValue("--planet"));

    std::cout << "[G] " << galaxiesCount << ", s=" << systemsCount << ", p=" << planetsCount << std::endl;

    ogame::core::UniverseShPtr universe = std::make_shared<ogame::core::Universe>(1u, galaxiesCount);
    (*universe)[2];

  }
  catch (const ogame::core::PlanetException& e) {
    std::cout << "[MAIN] Caught planet exception:" << std::endl << e.what() << std::endl;
  }
  catch (const ogame::core::SystemException& e) {
    std::cout << "[MAIN] Caught system exception:" << std::endl << e.what() << std::endl;
  }
  catch (const ogame::core::GalaxyException& e) {
    std::cout << "[MAIN] Caught galaxy exception:" << std::endl << e.what() << std::endl;
  }
  catch (const ogame::core::UniverseException& e) {
    std::cout << "[MAIN] Caught universe exception:" << std::endl << e.what() << std::endl;
  }
  catch (const app::arguments::ArgumentsException& e) {
    std::cout << "[MAIN] Caught exception:" << std::endl << e.what() << std::endl;
    parser.displayUsage(std::cout);
  }

  return 0;
}
