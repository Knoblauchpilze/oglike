#ifndef BUILDING_HXX
#define BUILDING_HXX

#include "Building.h"
#include <cmath>

namespace ogame {
  namespace core {

    inline
    const Building::Type& Building::getType() const noexcept {
      return m_type;
    }

    inline
    const std::string& Building::getName() const noexcept {
      return m_name;
    }

    inline
    const float Building::getUpgradeTime(const unsigned& universeSpeed,
                                         const unsigned& roboticsLevel,
                                         const unsigned& naniteLevel) const
    {
      const std::unordered_map<Resource, float>::const_iterator metal = m_upgradeCost.find(Resource(std::string("metal")));
      const std::unordered_map<Resource, float>::const_iterator crystal = m_upgradeCost.find(Resource(std::string("crystal")));

      const float metalValue = (metal != m_upgradeCost.cend() ? metal->second : 0.0f);
      const float crystalValue = (crystal != m_upgradeCost.cend() ? crystal->second : 0.0f);

      return std::max(1.0f, 3600.0f * (metalValue + crystalValue) / (universeSpeed * 2500.0f * (1.0f + roboticsLevel) * std::pow(2.0f, 1.0f * naniteLevel)));
    }

    template <typename ChildClass>
    inline
    const ChildClass* Building::asType() const {
      return dynamic_cast<const ChildClass*>(this);
    }

    inline
    std::string Building::getPictureNameFromBuilding(const core::Building::Type& type, const bool reduced) noexcept {
      const std::string path("data/img/");
      std::string image;
      const std::string extension(reduced ? "_small.bmp" : ".bmp");

      switch (type) {
        case core::Building::Type::MetalMine:
          image = std::string("metal_mine");
          break;
        case core::Building::Type::CrystalMine:
          image = std::string("crystal_mine");
          break;
        case core::Building::Type::DeuteriumMine:
          image = std::string("deuterium_synthesizer");
          break;
        case core::Building::Type::SolarPlant:
          image = std::string("solar_plant");
          break;
        case core::Building::Type::FusionPlant:
          image = std::string("fusion_plant");
          break;
        case core::Building::Type::MetalStorage:
          image = std::string("metal_storage");
          break;
        case core::Building::Type::CrystalStorage:
          image = std::string("crystal_storage");
          break;
        case core::Building::Type::DeuteriumStorage:
          image = std::string("deuterium_tank");
          break;
        case core::Building::Type::RoboticsFactory:
          image = std::string("robotics_factory");
          break;
        case core::Building::Type::Shipyard:
          image = std::string("shipyard");
          break;
        case core::Building::Type::ResearchLab:
          image = std::string("research_laboratory");
          break;
        case core::Building::Type::AllianceDepot:
          image = std::string("alliance_depot");
          break;
        case core::Building::Type::MissileSilo:
          image = std::string("missile_silo");
          break;
        case core::Building::Type::NaniteFactory:
          image = std::string("nanite_factory");
          break;
        case core::Building::Type::Terraformer:
          image = std::string("terraformer");
          break;
        case core::Building::Type::SpaceDock:
          image = std::string("space_dock");
          break;
        // TODO: Handle solar satellites.
        // case core::Building::Type:::
        default:
          image = std::string("solar_satellite");
          break;
      }

      return path + image + extension;
    }

  }
}

#endif // BUILDING_HXX
