
#include "OptionsView.h"
#include "GuiException.h"
#include "GridLayout.h"

namespace ogame {
  namespace gui {

    OptionsView::OptionsView(const std::string& name):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction)
    {
      setBackgroundColor(SDL_Color{0, 0, 0, SDL_ALPHA_OPAQUE});

      createView();
    }

    OptionsView::~OptionsView() {}

    void OptionsView::populateWithPlayerData(const core::Account& account) {
      lock();

      // Update information.
      LabelContainer* player = getChild<LabelContainer*>(std::string("player_panel"));
      if (checkChild(player, std::string("Player name"))) {
        player->setText(account.getCommunityName() + " " + account.getUniverseName() + " " + account.getPlayerName());
      }

      // Make this component dirty.
      makeDeepDirty();

      unlock();
    }

    void OptionsView::createView() {
      // Create the main layout.
      view::GridLayoutShPtr layout = std::make_shared<view::GridLayout>(11u, 1u, 0.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not create layout for container ") + getName());
      }

      // Create each element.
      LabelContainerShPtr player = createOptionPanel(std::string("player_panel"), "FR Oberon player's name");

      LabelContainerShPtr highscore = createOptionPanel(std::string("highscore_panel"), "Highscore (1)");

      LabelContainerShPtr notes = createOptionPanel(std::string("notes_panel"), "Notes");

      LabelContainerShPtr friends = createOptionPanel(std::string("friends_panel"), "Friends (0)");

      LabelContainerShPtr search = createOptionPanel(std::string("search_panel"), "Search");

      LabelContainerShPtr options = createOptionPanel(std::string("options_panel"), "Options");

      LabelContainerShPtr support = createOptionPanel(std::string("support_panel"), "Support");

      LabelContainerShPtr logout = createOptionPanel(std::string("logout_panel"), "Logout");

      if (player == nullptr ||
          highscore == nullptr ||
          notes == nullptr ||
          friends == nullptr ||
          search == nullptr ||
          options == nullptr ||
          support == nullptr ||
          logout == nullptr)
      {
        throw GuiException(std::string("Could not create one or more component for view ") + getName());
      }

      layout->addItem(player,     0u, 0u, 4u, 1u);
      addChild(player);
      layout->addItem(highscore,  4u, 0u, 1u, 1u);
      addChild(highscore);
      layout->addItem(notes,      5u, 0u, 1u, 1u);
      addChild(notes);
      layout->addItem(friends,    6u, 0u, 1u, 1u);
      addChild(friends);
      layout->addItem(search,     7u, 0u, 1u, 1u);
      addChild(search);
      layout->addItem(options,    8u, 0u, 1u, 1u);
      addChild(options);
      layout->addItem(support,    9u, 0u, 1u, 1u);
      addChild(support);
      layout->addItem(logout,     10u, 0u, 1u, 1u);
      addChild(logout);

      setLayout(layout);
    }

  }
}
