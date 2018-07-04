
#include "PlanetActionList.h"
#include "GuiException.h"
#include "LinearLayout.h"

namespace ogame {
  namespace gui {

    PlanetActionList::PlanetActionList(const std::string& name):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             nullptr)
    {
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});

      createView();
    }

    PlanetActionList::~PlanetActionList() {}

    void PlanetActionList::updateStatus(const core::Planet& planet) {
      lock();

      // Update information.
      SwitchPictureContainer* spy = getChild<SwitchPictureContainer*>(std::string("Spy button"));
      if (checkChild(spy, std::string("Spy button"))) {
        spy->updateStatus(planet.isColonized());
      }
      SwitchPictureContainer* message = getChild<SwitchPictureContainer*>(std::string("Message button"));
      if (checkChild(message, std::string("Message button"))) {
        message->updateStatus(planet.isColonized());
      }
      SwitchPictureContainer* player = getChild<SwitchPictureContainer*>(std::string("Player button"));
      if (checkChild(player, std::string("Spy button"))) {
        player->updateStatus(planet.isColonized());
      }
      SwitchPictureContainer* mip = getChild<SwitchPictureContainer*>(std::string("Mip button"));
      if (checkChild(mip, std::string("Spy button"))) {
        mip->updateStatus(planet.isColonized());
      }

      unlock();
    }

    void PlanetActionList::createView() {
      // Create the main layout for this panel.
      view::LinearLayoutShPtr layout = std::make_shared<view::LinearLayout>(view::LinearLayout::Direction::Horizontal, 0.0f, 5.0f);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create planet's action list"));
      }

      // Create each container with the associated image.
      SwitchPictureContainerShPtr spy = createAction(std::string("Spy button"),
                                                     std::string("data/img/action_spy.bmp"));
      SwitchPictureContainerShPtr message = createAction(std::string("Message button"),
                                                         std::string("data/img/action_message.bmp"));
      SwitchPictureContainerShPtr player = createAction(std::string("Player button"),
                                                        std::string("data/img/action_player.bmp"));
      SwitchPictureContainerShPtr mip = createAction(std::string("Mip button"),
                                                     std::string("data/img/action_mip.bmp"));

      addChild(spy);
      layout->addItem(spy);
      addChild(message);
      layout->addItem(message);
      addChild(player);
      layout->addItem(player);
      addChild(mip);
      layout->addItem(mip);

      // Now assign the layout to this container.
      setLayout(layout);
    }

  }
}
