project (ogamelike_lib_gui)

set (CMAKE_CXX_STANDARD 14)

#set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package (SDL REQUIRED)
find_package (SDL_ttf REQUIRED)

set (SOURCES
  OgameView.cpp
  GuiException.cpp
  GalaxyView.cpp
  PlanetGalaxyEntry.cpp
  PictureContainer.cpp
  LabelContainer.cpp
  PlanetIconDisplay.cpp
  SwitchPictureContainer.cpp
  PlanetActionList.cpp
  GalaxyNavigationPanel.cpp
  ValueSelector.cpp
  GalaxyPlayerData.cpp
  SelectorPanel.cpp
  MenuView.cpp
  LabelledPicture.cpp
  ResourcesView.cpp
  OptionsView.cpp
  PlanetsView.cpp
  PlanetViewLink.cpp
  StateContainer.cpp
  StateLabelContainer.cpp
  ActionProviderStateContainer.cpp
  Overview.cpp
  PlanetDescription.cpp
  ConditionalPictureContainer.cpp
  BuildingsView.cpp
  FacilitiesView.cpp
  ResearchView.cpp
  ShipyardView.cpp
  DefenseView.cpp
  FleetView.cpp
  AbstractBuyingView.cpp
  ElementDescriptionPanel.cpp
  UpgradeInfo.cpp
  UpgradeResourceInfo.cpp
  UpgradeActionContainer.cpp
  PhotoGallery.cpp
  ActionProviderLabelStateContainer.cpp
  )

add_library (ogamelike_lib_gui SHARED
  ${SOURCES}
  ${SDL_INCLUDE_DIRS}
  )

add_library (SDL IMPORTED SHARED)

add_library (SDL_ttf IMPORTED SHARED)

target_link_libraries(ogamelike_lib_gui
  ${SDL_LIBRARY}
  ${SDLTTF_LIBRARY}
  ogamelike_lib_core
  ogamelike_lib_view
  ogamelike_lib_player
  )

target_include_directories (ogamelike_lib_gui PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CORE_INCLUDE_DIR}
  ${VIEW_INCLUDE_DIR}
  ${PLAYER_INCLUDE_DIR}
  )

