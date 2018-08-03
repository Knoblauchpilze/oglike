
#include <iostream>
#include <string>

#include "ArgumentsParser.h"
#include "ArgumentsException.h"

#include "OgameView.h"
#include "GuiException.h"

#include "Community.h"
#include "Player.h"
#include "Universe.h"
#include "Account.h"

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "AbstractDataModel.h"
#include "AbstractActionListener.h"

#include "ServerLauncher.h"
#include "UniverseRunnable.h"

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

  // Create a universe and a player in it.
  const unsigned galaxiesCount = std::stoi(parser.getOptionValue("--galaxy"));
  const unsigned systemsCount = std::stoi(parser.getOptionValue("--system"));
  const unsigned planetsCount = std::stoi(parser.getOptionValue("--planet"));
  std::cout << "[INFO] Instanciating universe with " << galaxiesCount << " galaxies, " << systemsCount << " systems per galaxy and " << planetsCount << " planets per system" << std::endl;


  ogame::core::CommunityShPtr community = std::make_shared<ogame::core::Community>("FR");
  ogame::core::UniverseShPtr universe = nullptr;
  ogame::core::AccountShPtr account = nullptr;
  ogame::player::PlayerShPtr player = nullptr;

  const unsigned accountsToCreate = 0;
  std::vector<ogame::core::AccountShPtr> accounts;
  std::vector<ogame::player::PlayerShPtr> players;
  try {
    universe = std::make_shared<ogame::core::Universe>(
      community->createUniverse(std::string("Oberon")),
      galaxiesCount,
      systemsCount,
      planetsCount
    );
    player = std::make_shared<ogame::player::Player>(std::string("tttttttttttttttttttt"), community);
    account = std::make_shared<ogame::core::Account>(player->getUuid(), universe, community);
    universe->createAccount(account);

    for (unsigned indexAccount = 0u ; indexAccount < accountsToCreate ; ++indexAccount) {
      ogame::player::PlayerShPtr newPlayer = std::make_shared<ogame::player::Player>(std::string("Player ") + std::to_string(indexAccount), community);
      players.push_back(newPlayer);
      ogame::core::AccountShPtr newAccount = std::make_shared<ogame::core::Account>(newPlayer->getUuid(), universe, community);
      accounts.push_back(newAccount);
      universe->createAccount(newAccount);
    }
  }
  catch (const ogame::core::OgameException& e) {
    std::cerr << "[MAIN] Caught internal exception:" << std::endl << e.what() << std::endl;
  }

  // Instantiate the data model.
  ogame::player::GeneralDataModelShPtr dataModel = nullptr;
  dataModel = std::make_shared<ogame::player::GeneralDataModel>(std::string("general_model"));

  // Instantiate the main view.
  const unsigned screenWidth = std::stoi(parser.getOptionValue("--width"));
  const unsigned screenHeight = std::stoi(parser.getOptionValue("--height"));
  ogame::gui::OgameViewShPtr view;

  try {
    view  = std::make_shared<ogame::gui::OgameView>(
      screenWidth,
      screenHeight,
      galaxiesCount,
      systemsCount,
      planetsCount,
      dataModel
    );
  }
  catch (const ogame::gui::GuiException& e) {
    std::cerr << "[MAIN] Caught exception:" << std::endl << e.what() << std::endl;
    return 1;
  }
  catch (const ogame::core::OgameException& e) {
    std::cerr << "[MAIN] Caught internal exception:" << std::endl << e.what() << std::endl;
    return 1;
  }

  // Populate the data model.
  try {
    dataModel->setActiveAccount(account.get());
    dataModel->setActivePlanet(&account->getHomeWorld());
    dataModel->setActiveView(ogame::player::View::Overview);
    dataModel->setActiveSystemCoordinate(account->getHomeWorld().getSystem().getIndex());
    dataModel->setActiveGalaxyCoordinate(account->getHomeWorld().getSystem().getGalaxyIndex());
    dataModel->setActiveResearch(ogame::core::Research::Type::Energy);
    dataModel->setActiveBuilding(ogame::core::Building::Type::MetalMine);
    dataModel->setActiveShip(ogame::core::Ship::Type::LightFighter);
    dataModel->setActiveDefense(ogame::core::Defense::Type::MissileLauncher);
  }
  catch (const ogame::gui::GuiException& e) {
    std::cerr << "[MAIN] Caught exception:" << std::endl << e.what() << std::endl;
    return 1;
  }
  catch (const ogame::core::OgameException& e) {
    std::cerr << "[MAIN] Caught internal exception:" << std::endl << e.what() << std::endl;
    return 1;
  }

  // Create the server.
  ogame::server::ServerLauncherShPtr launcher = nullptr;
  ogame::server::UniverseRunnableShPtr universeLauncher = nullptr;
  try {
    launcher = std::make_shared<ogame::server::ServerLauncher>(
      5.0f,
      500.0f,
      ogame::server::time::Unit::Millisecond
    );
    universeLauncher = std::make_shared<ogame::server::UniverseRunnable>(universe);

    launcher->addRunnable(universeLauncher.get());
  }
  catch (const ogame::server::ServerException& e) {
    std::cerr << "[MAIN] Caught exception:" << std::endl << e.what() << std::endl;
    return 1;
  }
  catch (const ogame::core::OgameException& e) {
    std::cerr << "[MAIN] Caught internal exception:" << std::endl << e.what() << std::endl;
    return 1;
  }

  // Run the application.
  try {
    launcher->start();
    view->run();
    launcher->stop();
  }
  catch (const ogame::server::ServerException& e) {
    std::cerr << "[MAIN] Caught exception:" << std::endl << e.what() << std::endl;
  }
  catch (const ogame::gui::GuiException& e) {
    std::cerr << "[MAIN] Caught exception:" << std::endl << e.what() << std::endl;
  }
  catch (const ogame::view::ViewException& e) {
    std::cerr << "[MAIN] Caught exception:" << std::endl << e.what() << std::endl;
  }
  catch (const ogame::core::OgameException& e) {
    std::cerr << "[MAIN] Caught internal exception:" << std::endl << e.what() << std::endl;
  }

  // We need to manually destroy objects before exiting the program to be sure that we can clean-up libraries afterwards.
  view.reset();

  ogame::view::FontFactory::getInstance().releaseFonts();

  // Unload the sdl and the ttf libs if needed.
  if (TTF_WasInit()) {
    TTF_Quit();
  }
  if (SDL_WasInit(0u)) {
    SDL_Quit();
  }

  // All is good.
  return 0;
}
