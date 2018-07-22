#ifndef DEFENSE_H
#define DEFENSE_H

#include <string>
#include <memory>

namespace ogame {
  namespace core {

    class Defense
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

        Defense(const Type& type);

        virtual ~Defense();

        const Type& getType() const noexcept;

        const std::string& getName() const noexcept;

        const unsigned getCount() const noexcept;

      private:

        const std::string getNameFromType(const Type& type) const noexcept;

      private:

        Type m_type;
        std::string m_name;
    };

    using DefenseShPtr = std::shared_ptr<Defense>;

  }
}

#include "Defense.hxx"

#endif // DEFENSE_H
