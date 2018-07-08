
#include "GalaxyPlayerData.h"
#include "GuiException.h"
#include "LinearLayout.h"

namespace ogame {
  namespace gui {

    GalaxyPlayerData::GalaxyPlayerData(const std::string& name):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::MouseButton,
                             std::make_shared<view::LinearLayout>(
                               view::LinearLayout::Direction::Horizontal,
                               0.0f,
                               0.0f,
                               this
                             )),
      m_font(std::make_shared<view::Font>(
        std::string("data/fonts/angsa.ttf"),
        0, 0, 128, SDL_ALPHA_OPAQUE
      ))
    {
      createView();
    }

    GalaxyPlayerData::~GalaxyPlayerData() {}

    void GalaxyPlayerData::populateWithPlayerData(/* TODO */) {
      lock();
      
      LabelContainer* spyProbes = getChild<LabelContainer*>(std::string("spy_probes"));
      if (checkChild(spyProbes, std::string("Spy probes"))) {
        // TODO: Update probes
        spyProbes->setText(std::to_string(0) + " spy probe" + (false ? "s" : ""));
      }
      
      LabelContainer* recyclers = getChild<LabelContainer*>(std::string("recyclers"));
      if (checkChild(recyclers, std::string("Recyclers"))) {
        // TODO: Update recyclers
        recyclers->setText(std::to_string(0) + " recycler" + (false ? "s" : ""));
      }
      
      LabelContainer* mips = getChild<LabelContainer*>(std::string("interplanetary_missiles"));
      if (checkChild(mips, std::string("Interplanetary missiles"))) {
        // TODO: Update mips
        mips->setText(std::to_string(0) + " interplanetary missile" + (false ? "s" : ""));
      }
      
      LabelContainer* slots = getChild<LabelContainer*>(std::string("used_slots"));
      if (checkChild(slots, std::string("Used slots"))) {
        // TODO: Update used slots
        slots->setText(std::to_string(0) + "/" + std::to_string(200) + " used slot" + (false ? "s" : ""));
      }

      makeDeepDirty();

      unlock();
    }

    void GalaxyPlayerData::createView() {
      // Create each information panel.
      LabelContainerShPtr probes = createLabelPanel(std::string("spy_probes"),
                                                    std::string("0 spy probe"),
                                                    m_font);

      LabelContainerShPtr recyclers = createLabelPanel(std::string("recyclers"),
                                                    std::string("0 recycler"),
                                                    m_font);

      LabelContainerShPtr mips = createLabelPanel(std::string("interplanetary_missiles"),
                                                    std::string("0 interplanetary missile"),
                                                    m_font);

      LabelContainerShPtr slots = createLabelPanel(std::string("used_slots"),
                                                    std::string("0/0 used slot"),
                                                    m_font);

      if (probes == nullptr ||
          recyclers == nullptr ||
          mips == nullptr ||
          slots == nullptr)
      {
        throw GuiException(std::string("Could not create one or more of the player's information panel"));
      }

      addChild(probes);
      addChild(recyclers);
      addChild(mips);
      addChild(slots);
    }
  }
}
