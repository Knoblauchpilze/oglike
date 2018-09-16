#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <memory>
#include "AbstractUpgradable.h"

namespace ogame {
  namespace core {

    class Building: public AbstractUpgradable
    {
      public:

        // Convenience define for the type of a building.
        enum class Type {
          MetalMine,
          CrystalMine,
          DeuteriumMine,
          SolarPlant,
          FusionPlant,
          MetalStorage,
          CrystalStorage,
          DeuteriumStorage,
          RoboticsFactory,
          NaniteFactory,
          Shipyard,
          SpaceDock,
          MissileSilo,
          AllianceDepot,
          ResearchLab,
          Terraformer
        };

        Building(const Type& type,
                 const std::string& name,
                 const std::unordered_map<Resource, float>& initResources,
                 const float& factor);

        virtual ~Building();

        const Type& getType() const noexcept;

        const std::string& getName() const noexcept;

        // Time in seconds.
        const float getUpgradeTime(const unsigned& universeSpeed,
                                   const unsigned& roboticsLevel,
                                   const unsigned& naniteLevel) const;

        template <typename ChildClass>
        const ChildClass* asType() const;

        static
        std::string getPictureNameFromBuilding(const core::Building::Type& type, const bool reduced = true) noexcept;

      protected:

        Building() = delete;

      private:

        Type m_type;
        std::string m_name;
    };

    using BuildingShPtr = std::shared_ptr<Building>;

  }
}

#include "Building.hxx"

#endif // BUILDING_H
