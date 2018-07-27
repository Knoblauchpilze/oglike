#ifndef UPGRADERESOURCEINFO_HXX
#define UPGRADERESOURCEINFO_HXX

#include "UpgradeResourceInfo.h"
#include "ComponentFactory.h"
#include "FontFactory.h"
#include "GuiException.h"
#include "AbstractUpgradable.h"
#include "FixedCostUnit.h"

namespace ogame {
  namespace gui {

    inline
    void UpgradeResourceInfo::onActionTriggered(const player::AbstractDataModel& model) {}

    template <typename Element>
    inline
    void UpgradeResourceInfo::populateInformationFromElement(const Element& element, const core::Planet& planet) {
      // throw GuiException(std::string("Cannot populate information panel from unknown element type"));
      std::cerr << std::string("Cannot populate information panel from unknown element type") << std::endl;
    }

    template <>
    inline
    void UpgradeResourceInfo::populateInformationFromElement(const core::AbstractUpgradable& element, const core::Planet& planet) {
      lock();

      // Retrieve the cost to upgrade this element.
      const std::unordered_map<core::Resource, float>& costs = element.getUpgradeCost();
      std::unordered_map<core::Resource, float>::const_iterator metalCost = costs.find(core::Resource(std::string("metal")));
      std::unordered_map<core::Resource, float>::const_iterator crystalCost = costs.find(core::Resource(std::string("crystal")));
      std::unordered_map<core::Resource, float>::const_iterator deutCost = costs.find(core::Resource(std::string("deuterium")));
      std::unordered_map<core::Resource, float>::const_iterator energyCost = costs.find(core::Resource(std::string("energy")));

      // Update each property for this panel.
      LabelledPicture* metal = getChild<LabelledPicture*>(std::string("metal_needed"));
      if (checkChild(metal, std::string("Upgrade resource info metal"))) {
        metal->setLabel(metalCost != costs.cend() ?
          std::to_string(static_cast<int>(metalCost->second)) :
          std::to_string(0)
        );
      }

      LabelledPicture* crystal = getChild<LabelledPicture*>(std::string("crystal_needed"));
      if (checkChild(crystal, std::string("Upgrade resource info crystal"))) {
        crystal->setLabel(crystalCost != costs.cend() ?
          std::to_string(static_cast<int>(crystalCost->second)) :
          std::to_string(0)
        );
      }

      LabelledPicture* deut = getChild<LabelledPicture*>(std::string("deut_needed"));
      if (checkChild(deut, std::string("Upgrade resource info  deuterium"))) {
        deut->setLabel(deutCost != costs.cend() ?
          std::to_string(static_cast<int>(deutCost->second)) :
          std::to_string(0)
        );
      }

      LabelledPicture* energy = getChild<LabelledPicture*>(std::string("energy_needed"));
      if (checkChild(energy, std::string("Upgrade resource info energy"))) {
        energy->setLabel(energyCost != costs.cend() ?
          std::to_string(static_cast<int>(energyCost->second)) :
          std::to_string(0)
        );
      }

      SwitchPictureContainer* upgrade = getChild<SwitchPictureContainer*>(std::string("upgrade_label"));
      if (checkChild(upgrade, std::string("Upgrade resource info upgrade button"))) {
        upgrade->updateStatus(element.canUpgrade(planet.getResourceDeposits()));
      }

      unlock();
    }


    template <>
    inline
    void UpgradeResourceInfo::populateInformationFromElement(const core::FixedCostUnit& element, const core::Planet& planet) {
      lock();

      // Retrieve the cost to upgrade this element.
      const std::unordered_map<core::Resource, float>& costs = element.getCost();
      std::unordered_map<core::Resource, float>::const_iterator metalCost = costs.find(core::Resource(std::string("metal")));
      std::unordered_map<core::Resource, float>::const_iterator crystalCost = costs.find(core::Resource(std::string("crystal")));
      std::unordered_map<core::Resource, float>::const_iterator deutCost = costs.find(core::Resource(std::string("deuterium")));
      std::unordered_map<core::Resource, float>::const_iterator energyCost = costs.find(core::Resource(std::string("energy")));

      // Update each property for this panel.
      LabelledPicture* metal = getChild<LabelledPicture*>(std::string("metal_needed"));
      if (checkChild(metal, std::string("Upgrade resource info metal"))) {
        metal->setLabel(metalCost != costs.cend() ?
          std::to_string(static_cast<int>(metalCost->second)) :
          std::to_string(0)
        );
      }

      LabelledPicture* crystal = getChild<LabelledPicture*>(std::string("crystal_needed"));
      if (checkChild(crystal, std::string("Upgrade resource info crystal"))) {
        crystal->setLabel(crystalCost != costs.cend() ?
          std::to_string(static_cast<int>(crystalCost->second)) :
          std::to_string(0)
        );
      }

      LabelledPicture* deut = getChild<LabelledPicture*>(std::string("deut_needed"));
      if (checkChild(deut, std::string("Upgrade resource info  deuterium"))) {
        deut->setLabel(deutCost != costs.cend() ?
          std::to_string(static_cast<int>(deutCost->second)) :
          std::to_string(0)
        );
      }

      LabelledPicture* energy = getChild<LabelledPicture*>(std::string("energy_needed"));
      if (checkChild(energy, std::string("Upgrade resource info energy"))) {
        energy->setLabel(energyCost != costs.cend() ?
          std::to_string(static_cast<int>(energyCost->second)) :
          std::to_string(0)
        );
      }

      SwitchPictureContainer* upgrade = getChild<SwitchPictureContainer*>(std::string("upgrade_label"));
      if (checkChild(upgrade, std::string("Upgrade resource info upgrade button"))) {
        upgrade->updateStatus(element.canBuy(planet.getResourceDeposits()));
      }

      unlock();
    }

    template <>
    inline
    void UpgradeResourceInfo::populateInformationFromElement(const core::Building& element, const core::Planet& planet) {
      populateInformationFromElement<core::AbstractUpgradable>(element, planet);
    }

    template <>
    inline
    void UpgradeResourceInfo::populateInformationFromElement(const core::Research& element, const core::Planet& planet) {
      populateInformationFromElement<core::AbstractUpgradable>(element, planet);
    }
    
    template <>
    inline
    void UpgradeResourceInfo::populateInformationFromElement(const core::Ship& element, const core::Planet& planet) {
      populateInformationFromElement<core::FixedCostUnit>(element, planet);
    }
    
    template <>
    inline
    void UpgradeResourceInfo::populateInformationFromElement(const core::Defense& element, const core::Planet& planet) {
      populateInformationFromElement<core::FixedCostUnit>(element, planet);
    }

    inline
    LabelContainerShPtr UpgradeResourceInfo::createLabelPanel(const std::string& name,
                                                              const std::string& text,
                                                              const SDL_Color& color) const
    {
      return ComponentFactory::createLabelPanel(
        name,
        text,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/upcfb.ttf"),
          color.r, color.g, color.b, color.unused
        ),
        LabelContainer::Alignment::Left
      );
    }

    inline
    LabelledPictureShPtr UpgradeResourceInfo::createLabelledPicturePanel(const std::string& name,
                                                                         const std::string& picture,
                                                                         const std::string& text) const
    {
      return ComponentFactory::createLabelledPicturePanel(
        name,
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/times.ttf"),
          255, 255, 255, SDL_ALPHA_OPAQUE,
          20
        ),
        picture,
        text,
        LabelledPicture::Alignment::Above
      );
    }

    inline
    void UpgradeResourceInfo::createUpgradeResearchAction(core::Account& account, const player::GeneralDataModel& model) const {
      account.createUpgradeAction(model.getActiveResearch());
      triggerAction(player::Action::ChangePlanet);
    }

    inline
    void UpgradeResourceInfo::createUpgradeBuildingAction(core::Planet& planet, const player::GeneralDataModel& model) const {
      planet.createUpgradeAction(model.getActiveBuilding());
      triggerAction(player::Action::ChangePlanet);
    }

    inline
    void UpgradeResourceInfo::createUpgradeShipAction(core::Planet& planet, const player::GeneralDataModel& model) const {
      planet.createUpgradeAction(model.getActiveShip());
      triggerAction(player::Action::ChangePlanet);
    }

    inline
    void UpgradeResourceInfo::createUpgradeDefenseAction(core::Planet& planet, const player::GeneralDataModel& model) const {
      planet.createUpgradeAction(model.getActiveDefense());
      triggerAction(player::Action::ChangePlanet);
    }

  }
}

#endif // UPGRADERESOURCEINFO_HXX