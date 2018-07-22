#ifndef UPGRADEINFO_HXX
#define UPGRADEINFO_HXX

#include "UpgradeInfo.h"
#include "ComponentFactory.h"
#include "FontFactory.h"
#include "GuiException.h"
#include "Research.h"
#include "Ship.h"
#include "Building.h"
#include "Defense.h"

namespace ogame {
  namespace gui {

    template <typename Element>
    inline
    void UpgradeInfo::populateInformationFromElement(const Element& element) {
      throw GuiException(std::string("Cannot populate information panel from unknown element type"));
    }

    template <>
    inline
    void UpgradeInfo::populateInformationFromElement(const core::Research& element) {
      lock();

      // Update each property for this panel.
      LabelContainer* title = getChild<LabelContainer*>(std::string("title"));
      if (checkChild(title, std::string("Upgrade info title"))) {
        title->setText(std::string("Technology: ") + element.getName());
      }

      LabelContainer* level = getChild<LabelContainer*>(std::string("level"));
      if (checkChild(level, std::string("Upgrade info title"))) {
        level->setText(std::string("Level ") + std::to_string(element.getLevel()));
      }

      LabelContainer* production = getChild<LabelContainer*>(std::string("production_time"));
      if (checkChild(production, std::string("Upgrade info production time"))) {
        production->setText(std::string("Production duration: ") + computeDisplayTime(element.getUpgradeTime()));
      }

      LabelContainer* energy = getChild<LabelContainer*>(std::string("energy_needed"));
      if (checkChild(energy, std::string("Upgrade info energy label"))) {
        energy->setText(std::string(""));
      }

      LabelContainer* number = getChild<LabelContainer*>(std::string("number"));
      if (checkChild(number, std::string("Upgrade info number"))) {
        number->setText(std::string(""));
      }

      LabelContainer* unitcount = getChild<LabelContainer*>(std::string("unit_number"));
      if (checkChild(unitcount, std::string("Upgrade info unit count"))) {
        // TODO
      }

      unlock();
    }

    template <>
    inline
    void UpgradeInfo::populateInformationFromElement(const core::Ship& element) {
      lock();

      // Update each property for this panel.
      LabelContainer* title = getChild<LabelContainer*>(std::string("title"));
      if (checkChild(title, std::string("Upgrade info title"))) {
        title->setText(std::string("Technology: ") + element.getName());
      }

      LabelContainer* level = getChild<LabelContainer*>(std::string("level"));
      if (checkChild(level, std::string("Upgrade info title"))) {
        level->setText(std::string("Number: ") + std::to_string(element.getCount()));
      }

      LabelContainer* production = getChild<LabelContainer*>(std::string("production_time"));
      if (checkChild(production, std::string("Upgrade info production time"))) {
        production->setText(std::string("Production duration: ") + computeDisplayTime(45.0f));
      }

      LabelContainer* energy = getChild<LabelContainer*>(std::string("energy_needed"));
      if (checkChild(energy, std::string("Upgrade info energy label"))) {
        energy->setText(std::string(""));
      }

      LabelContainer* number = getChild<LabelContainer*>(std::string("number"));
      if (checkChild(number, std::string("Upgrade info number"))) {
        number->setText(std::string("Number:"));
      }

      LabelContainer* unitcount = getChild<LabelContainer*>(std::string("unit_number"));
      if (checkChild(unitcount, std::string("Upgrade info unit count"))) {
        // TODO
      }

      unlock();
    }

    template <>
    inline
    void UpgradeInfo::populateInformationFromElement(const core::Building& element) {
      std::cout << "[UPGRADE] Populating panel from building " << element.getName() << std::endl;
    }

    template <>
    inline
    void UpgradeInfo::populateInformationFromElement(const core::Defense& element) {
      lock();

      // Update each property for this panel.
      LabelContainer* title = getChild<LabelContainer*>(std::string("title"));
      if (checkChild(title, std::string("Upgrade info title"))) {
        title->setText(element.getName());
      }

      LabelContainer* level = getChild<LabelContainer*>(std::string("level"));
      if (checkChild(level, std::string("Upgrade info title"))) {
        level->setText(std::string("Number: ") + std::to_string(element.getCount()));
      }

      LabelContainer* production = getChild<LabelContainer*>(std::string("production_time"));
      if (checkChild(production, std::string("Upgrade info production time"))) {
        production->setText(std::string("Production duration: ") + computeDisplayTime(50.0f));
      }

      LabelContainer* energy = getChild<LabelContainer*>(std::string("energy_needed"));
      if (checkChild(energy, std::string("Upgrade info energy label"))) {
        energy->setText(std::string(""));
      }

      LabelContainer* number = getChild<LabelContainer*>(std::string("number"));
      if (checkChild(number, std::string("Upgrade info number"))) {
        number->setText(std::string("Number:"));
      }

      LabelContainer* unitcount = getChild<LabelContainer*>(std::string("unit_number"));
      if (checkChild(unitcount, std::string("Upgrade info unit count"))) {
        // TODO
      }

      unlock();
    }

    inline
    LabelContainerShPtr UpgradeInfo::createLabelPanel(const std::string& name,
                                                      const std::string& text,
                                                      const SDL_Color& textColor,
                                                      const SDL_Color& bgColor,
                                                      const bool transparent,
                                                      const LabelContainer::Alignment& alignment) const
    {
      return ComponentFactory::createLabelPanel(
        name,
        text,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/upcfb.ttf"),
          textColor.r, textColor.g, textColor.b, textColor.unused
        ),
        alignment,
        bgColor,
        transparent
      );
    }

    inline
    const std::string UpgradeInfo::computeDisplayTime(const float& seconds) const {
      // Compute values up to a year.
      const int uSeconds = static_cast<int>(seconds);
      const int years =   uSeconds / (60 * 60 * 24 * 7 * 52);
      const int weeks =   uSeconds / (60 * 60 * 24 * 7)         -     years * 52;
      const int days =    uSeconds / (60 * 60 * 24)             -    (years * 52 + weeks) * 7;
      const int hours =   uSeconds / (60 * 60)                  -   ((years * 52 + weeks) * 7 + days) * 24;
      const int minutes = uSeconds / (60)                       -  (((years * 52 + weeks) * 7 + days) * 24 + hours) * 60;
      const int realSec = uSeconds                              - ((((years * 52 + weeks) * 7 + days) * 24 + hours) * 60 + minutes) * 60;

      // Build the final string.
      std::string duration;
      if (std::abs(years) > 0) {
        duration += (std::to_string(years) + "y ");
      }
      if (std::abs(weeks) > 0) {
        duration += (std::to_string(weeks) + "w ");
      }
      if (std::abs(days) > 0) {
        duration += (std::to_string(days) + "d ");
      }
      if (std::abs(hours) > 0) {
        duration += (std::to_string(hours) + "h ");
      }
      if (std::abs(minutes) > 0) {
        duration += (std::to_string(minutes) + "m ");
      }
      if (std::abs(realSec) > 0) {
        duration += (std::to_string(realSec) + "s");
      }

      return duration;
    }

  }
}

#endif // UPGRADEINFO_HXX