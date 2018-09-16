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
#include "ResourceMine.h"

namespace ogame {
  namespace gui {

    inline
    void UpgradeInfo::triggerUnitCount() {
      // Retrieve the value from the selector
      ValueSelector* unitCount = getChild<ValueSelector*>(std::string("unit_number"));
      if (checkChild(unitCount, std::string("Upgrade info unit count"))) {
        setUnitCount(std::stoi(unitCount->getActiveOption()));
      }
    }

    inline
    void UpgradeInfo::onActionTriggered(const player::GeneralDataModel& model, const player::Action& action) {}

    inline
    void UpgradeInfo::onInteractionPerformed(const std::string& origin, const view::EventListener::Interaction::Mask& mask) {
      // Determine the origin of the event (either galaxy or system selector) and update the corresponding value in the data model.
      if (origin == std::string("unit_number")) {
        triggerUnitCount();
      }
      else {
        std::cerr << "[NAVIGATION] Caught interaction in " << getName() << " from unknown origin " << origin << std::endl;
      }
    }

    template <typename Element>
    inline
    void UpgradeInfo::populateInformationFromElement(const Element& element,
                                                     const core::Planet& planet,
                                                     const core::Account& account)
    {
      throw GuiException(std::string("Cannot populate information panel from unknown element type"));
    }

    template <>
    inline
    void UpgradeInfo::populateInformationFromElement(const core::Building& element,
                                                     const core::Planet& planet,
                                                     const core::Account& account)
    {
      lock();

      // Update each property for this panel.
      unsigned universeSpeed = 1u;
      unsigned roboticsLevel = 0u;
      unsigned naniteLevel = 0u;
      try {
        universeSpeed = account.getUniverseSpeed();
        roboticsLevel = planet.getBuildingLevel(core::Building::Type::RoboticsFactory);
        naniteLevel = planet.getBuildingLevel(core::Building::Type::NaniteFactory);
      }
      catch (const core::AccountException& e) {
        std::cerr << "[UPGRADE] Could not retrieve speed of universe, duration may be wrong:" << std::endl << e.what() << std::endl;
      }

      LabelContainer* title = getChild<LabelContainer*>(std::string("title"));
      if (checkChild(title, std::string("Upgrade info title"))) {
        title->setText(element.getName());
      }

      LabelContainer* level = getChild<LabelContainer*>(std::string("level"));
      if (checkChild(level, std::string("Upgrade info title"))) {
        level->setText(std::string("Level ") + std::to_string(element.getLevel()));
      }

      LabelContainer* production = getChild<LabelContainer*>(std::string("production_time"));
      if (checkChild(production, std::string("Upgrade info production time"))) {
        production->setText(std::string("Production duration: ") + computeDisplayTime(element.getUpgradeTime(universeSpeed, roboticsLevel, naniteLevel)));
      }

      LabelContainer* energy = getChild<LabelContainer*>(std::string("energy_needed"));
      if (checkChild(energy, std::string("Upgrade info energy label"))) {
        energy->setText(computeEnergyDisplay(element));
      }

      LabelContainer* gain = getChild<LabelContainer*>(std::string("production_increase"));
      if (checkChild(gain, std::string("Upgrade info production label"))) {
        gain->setText(computeProductionDisplay(element, planet, universeSpeed));
      }

      ValueSelector* unitCount = getChild<ValueSelector*>(std::string("unit_number"));
      if (checkChild(unitCount, std::string("Upgrade info unit count"))) {
        unitCount->setEnabled(false);
        unitCount->setActiveOption(0u);
      }

      unlock();
    }

    template <>
    inline
    void UpgradeInfo::populateInformationFromElement(const core::Research& element,
                                                     const core::Planet& planet,
                                                     const core::Account& account)
    {
      lock();

      // Update each property for this panel.
      unsigned universeSpeed = 1u;
      unsigned laboratoryLevel = 0u;
      try {
        universeSpeed = account.getUniverseSpeed();
        laboratoryLevel = planet.getBuildingLevel(core::Building::Type::ResearchLab);
      }
      catch (const core::AccountException& e) {
        std::cerr << "[UPGRADE] Could not retrieve speed of universe, duration may be wrong:" << std::endl << e.what() << std::endl;
      }

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
        production->setText(std::string("Production duration: ") + computeDisplayTime(element.getUpgradeTime(universeSpeed, laboratoryLevel)));
      }

      LabelContainer* energy = getChild<LabelContainer*>(std::string("energy_needed"));
      if (checkChild(energy, std::string("Upgrade info energy label"))) {
        energy->setText(std::string(""));
      }

      LabelContainer* gain = getChild<LabelContainer*>(std::string("production_increase"));
      if (checkChild(gain, std::string("Upgrade info production label"))) {
        gain->setText(std::string(""));
      }

      ValueSelector* unitCount = getChild<ValueSelector*>(std::string("unit_number"));
      if (checkChild(unitCount, std::string("Upgrade info unit count"))) {
        unitCount->setEnabled(false);
        unitCount->setActiveOption(0u);
      }

      unlock();
    }

    template <>
    inline
    void UpgradeInfo::populateInformationFromElement(const core::Ship& element,
                                                     const core::Planet& planet,
                                                     const core::Account& account)
    {
      lock();

      // Update each property for this panel.
      unsigned universeSpeed = 1u;
      unsigned shipyardLevel = 0u;
      unsigned naniteLevel = 0u;
      try {
        universeSpeed = account.getUniverseSpeed();
        shipyardLevel = planet.getBuildingLevel(core::Building::Type::Shipyard);
        naniteLevel = planet.getBuildingLevel(core::Building::Type::NaniteFactory);
      }
      catch (const core::AccountException& e) {
        std::cerr << "[UPGRADE] Could not retrieve speed of universe, duration may be wrong:" << std::endl << e.what() << std::endl;
      }

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
        production->setText(std::string("Production duration: ") + computeDisplayTime(element.getProductionTime(universeSpeed, shipyardLevel, naniteLevel)));
      }

      LabelContainer* energy = getChild<LabelContainer*>(std::string("energy_needed"));
      if (checkChild(energy, std::string("Upgrade info energy label"))) {
        energy->setText(std::string(""));
      }

      LabelContainer* gain = getChild<LabelContainer*>(std::string("production_increase"));
      if (checkChild(gain, std::string("Upgrade info production label"))) {
        gain->setText(std::string(""));
      }

      LabelContainer* number = getChild<LabelContainer*>(std::string("number"));
      if (checkChild(number, std::string("Upgrade info number"))) {
        number->setText(std::string("Number:"));
      }

      ValueSelector* unitCount = getChild<ValueSelector*>(std::string("unit_number"));
      if (checkChild(unitCount, std::string("Upgrade info unit count"))) {
        // TODO.
        unitCount->setEnabled(true);
        unitCount->setActiveOption(0u);
      }

      unlock();
    }

    template <>
    inline
    void UpgradeInfo::populateInformationFromElement(const core::Defense& element,
                                                     const core::Planet& planet,
                                                     const core::Account& account)
    {
      lock();

      // Update each property for this panel.
      unsigned universeSpeed = 1u;
      try {
        universeSpeed = account.getUniverseSpeed();
      }
      catch (const core::AccountException& e) {
        std::cerr << "[UPGRADE] Could not retrieve speed of universe, duration may be wrong:" << std::endl << e.what() << std::endl;
      }

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
        production->setText(std::string("Production duration: ") + computeDisplayTime(element.getProductionTime(universeSpeed, 0u, 0u)));
      }

      LabelContainer* energy = getChild<LabelContainer*>(std::string("energy_needed"));
      if (checkChild(energy, std::string("Upgrade info energy label"))) {
        energy->setText(std::string(""));
      }

      LabelContainer* gain = getChild<LabelContainer*>(std::string("production_increase"));
      if (checkChild(gain, std::string("Upgrade info production label"))) {
        gain->setText(std::string(""));
      }

      LabelContainer* number = getChild<LabelContainer*>(std::string("number"));
      if (checkChild(number, std::string("Upgrade info number"))) {
        number->setText(std::string("Number:"));
      }

      ValueSelector* unitCount = getChild<ValueSelector*>(std::string("unit_number"));
      if (checkChild(unitCount, std::string("Upgrade info unit count"))) {
        // TODO.
        unitCount->setEnabled(true);
        unitCount->setActiveOption(0u);
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

    inline
    const std::string UpgradeInfo::computeEnergyDisplay(const core::Building& mine) const {
      if (mine.getType() == core::Building::Type::MetalMine ||
          mine.getType() == core::Building::Type::CrystalMine ||
          mine.getType() == core::Building::Type::DeuteriumMine)
      {
        return std::string("Energy needed: ") + std::to_string(static_cast<int>(mine.asType<core::ResourceMine>()->getEnergyNeeded()));
      }
      return std::string("");
    }

    inline
    const std::string UpgradeInfo::computeProductionDisplay(const core::Building& mine,
                                                            const core::Planet& planet,
                                                            const unsigned& universeSpeed) const
    {
      if (mine.getType() == core::Building::Type::MetalMine ||
          mine.getType() == core::Building::Type::CrystalMine ||
          mine.getType() == core::Building::Type::DeuteriumMine)
      {
        return std::string("Production increase: ") +
               std::to_string(static_cast<int>(mine.asType<core::ResourceMine>()->getProductionIncrease(planet.getMaxTemperature(), universeSpeed)));
      }
      return std::string("");
    }

  }
}

#endif // UPGRADEINFO_HXX