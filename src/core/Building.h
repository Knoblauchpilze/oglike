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
          ResourceMine,
          Plant,
          Storage,
          ConstructionAcceleration,
          SpaceConstruction,
          Research,
          Facilities
        };

        virtual ~Building();

        const Type& getType() const noexcept;

        const std::string& getName() const noexcept;

      protected:

        Building() = delete;

        Building(const Type& type,
                 const std::string& name,
                 const std::unordered_map<Resource, float>& initResources);

      private:

        Type m_type;
        std::string m_name;
    };

    using BuildingShPtr = std::shared_ptr<Building>;

  }
}

#include "Building.hxx"

#endif // BUILDING_H
