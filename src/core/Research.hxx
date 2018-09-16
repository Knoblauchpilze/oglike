#ifndef RESEARCH_HXX
#define RESEARCH_HXX

#include "Research.h"

namespace ogame {
  namespace core {

    inline
    const Research::Type& Research::getType() const noexcept {
      return m_type;
    }

    inline
    const std::string& Research::getName() const noexcept {
      return m_name;
    }

    inline
    const float Research::getUpgradeTime(const unsigned& universeSpeed,
                                         const unsigned& laboratoryLevel) const
    {
      const std::unordered_map<Resource, float>::const_iterator metal = m_upgradeCost.find(Resource(std::string("metal")));
      const std::unordered_map<Resource, float>::const_iterator crystal = m_upgradeCost.find(Resource(std::string("crystal")));

      const float metalValue = (metal != m_upgradeCost.cend() ? metal->second : 0.0f);
      const float crystalValue = (crystal != m_upgradeCost.cend() ? crystal->second : 0.0f);

      return std::max(1.0f, 3600.0f * (metalValue + crystalValue) / (universeSpeed * 1000.0f * (1.0f + laboratoryLevel)));
    }

    inline
    std::string Research::getPictureNameFromResearch(const core::Research::Type& type, const bool reduced) noexcept {
      const std::string path("data/img/");
      std::string image;
      const std::string extension(reduced ? "_tech_small.bmp" : "_tech.bmp");

      switch (type) {
        case core::Research::Type::Laser:
          image = std::string("laser");
          break;
        case core::Research::Type::Ion:
          image = std::string("ions");
          break;
        case core::Research::Type::Hyperspace:
          image = std::string("hyperspace");
          break;
        case core::Research::Type::Plasma:
          image = std::string("plasma");
          break;
        case core::Research::Type::CombustionDrive:
          image = std::string("combustion_drive");
          break;
        case core::Research::Type::ImpulseDrive:
          image = std::string("impulse_drive");
          break;
        case core::Research::Type::HyperspaceDrive:
          image = std::string("hyperspace_drive");
          break;
        case core::Research::Type::Espionage:
          image = std::string("espionage");
          break;
        case core::Research::Type::Computer:
          image = std::string("computer");
          break;
        case core::Research::Type::Astrophysics:
          image = std::string("astrophysics");
          break;
        case core::Research::Type::IRN:
          image = std::string("intergalactic_research_network");
          break;
        case core::Research::Type::Graviton:
          image = std::string("graviton");
          break;
        case core::Research::Type::Weapon:
          image = std::string("weapon");
          break;
        case core::Research::Type::Shielding:
          image = std::string("shielding");
          break;
        case core::Research::Type::Armour:
          image = std::string("armour");
          break;
        case core::Research::Type::Energy:
        default:
          image = std::string("energy");
          break;
      }

      return path + image + extension;
    }

    inline
    const std::string Research::getNameFromType(const Type& type) const noexcept {
      std::string name = "Default technology name";

      switch (type) {
        case Type::Laser:
          name = "Laser";
          break;
        case Type::Ion:
          name = "Ion";
          break;
        case Type::Hyperspace:
          name = "Hyperspace";
          break;
        case Type::Plasma:
          name = "Plasma";
          break;
        case Type::CombustionDrive:
          name = "Combustion drive";
          break;
        case Type::ImpulseDrive:
          name = "Impulse drive";
          break;
        case Type::HyperspaceDrive:
          name = "Hyperspace drive";
          break;
        case Type::Espionage:
          name = "Espionage";
          break;
        case Type::Computer:
          name = "Computer";
          break;
        case Type::Astrophysics:
          name = "Astrophysics";
          break;
        case Type::IRN:
          name = "IRN";
          break;
        case Type::Graviton:
          name = "Graviton";
          break;
        case Type::Weapon:
          name = "Weapon";
          break;
        case Type::Shielding:
          name = "Shielding";
          break;
        case Type::Armour:
          name = "Armour";
          break;
        case Type::Energy:
        default:
          name = "Energy";
          break;
      }

      return name;
    }

  }
}

#endif // RESEARCH_HXX
