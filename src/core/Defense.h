#ifndef DEFENSE_H
#define DEFENSE_H

#include <string>
#include <memory>
#include "FixedCostUnit.h"

namespace ogame {
  namespace core {

    class Defense: public FixedCostUnit
    {
      public:

        // Convenience define for the type of a defense.
        enum class Type {
          MissileLauncher,
          LightLaser,
          HeavyLaser,
          GaussCannon,
          IonCannon,
          PlasmaTurret,
          SmallShieldDome,
          LargeShieldDome,
          AntiballisticMissile,
          InterplanetaryMissile
        };

        Defense(const Type& type,
                const std::unordered_map<Resource, float>& cost);

        virtual ~Defense();

        const Type& getType() const noexcept;

      private:

        const std::string getNameFromType(const Type& type) const noexcept;

      private:

        Type m_type;
    };

    using DefenseShPtr = std::shared_ptr<Defense>;

  }
}

#include "Defense.hxx"

#endif // DEFENSE_H
