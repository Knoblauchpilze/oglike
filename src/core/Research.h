#ifndef RESEARCH_H
#define RESEARCH_H

#include <string>
#include <memory>

namespace ogame {
  namespace core {

    class Research
    {
      public:

        // Convenience define for the type of a ship.
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

        Research(const Type& type);

        virtual ~Research();

        const Type& getType() const noexcept;

        const std::string& getName() const noexcept;

        const unsigned getLevel() const noexcept;

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
