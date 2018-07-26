#ifndef RESEARCH_H
#define RESEARCH_H

#include <string>
#include <memory>
#include "AbstractUpgradable.h"

namespace ogame {
  namespace core {

    class Research: public AbstractUpgradable
    {
      public:

        // Convenience define for the type of a research.
        enum class Type {
          Energy,
          Laser,
          Ion,
          Hyperspace,
          Plasma,
          CombustionDrive,
          ImpulseDrive,
          HyperspaceDrive,
          Espionage,
          Computer,
          Astrophysics,
          IRN,
          Graviton,
          Weapon,
          Shielding,
          Armour
        };

        Research(const Type& type,
                 const std::unordered_map<Resource, float>& initResources);

        virtual ~Research();

        const Type& getType() const noexcept;

        const std::string& getName() const noexcept;

        // Time in seconds.
        const float getUpgradeTime(const unsigned& universeSpeed,
                                   const unsigned& laboratoryLevel) const;

      private:

        const std::string getNameFromType(const Type& type) const noexcept;

      private:

        Type m_type;
        std::string m_name;
    };

    using ResearchShPtr = std::shared_ptr<Research>;

  }
}

#include "Research.hxx"

#endif // RESEARCH_H
