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
    const unsigned Research::getLevel() const noexcept {
      return 0u;
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
