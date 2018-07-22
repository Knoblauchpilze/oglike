#ifndef PLANET_HXX
#define PLANET_HXX

#include "Planet.h"
#include "PlanetException.h"

namespace ogame {
  namespace core {

    inline
    bool Planet::operator==(const Planet& other) const noexcept {
      return other.m_index == m_index;
    }

    inline
    const std::string& Planet::getName() const noexcept {
      return m_name;
    }

    inline
    const bool Planet::isColonized() const noexcept {
      return m_account != nullptr;
    }

    inline
    const bool Planet::hasMoon() const noexcept {
      return false;
    }

    inline
    const bool Planet::hasWreckfield() const noexcept {
      return false;
    }

    inline
    const std::string Planet::generateRandomName(const unsigned& length) const noexcept {
      std::string name;
      name.resize(length);
      unsigned index = 0u;
      while (index < length) {
        name[index] = 'a' + std::rand() % ('z' - 'a');
        ++index;
      }
      return name;
    }

    inline
    const float Planet::getResourceQuantity(const std::string& name) const {
      // Search across the resource deposit for this planet.
      unsigned indexDeposit = 0u;
      while (indexDeposit < m_resources.size()) {
        if (m_resources[indexDeposit] != nullptr && m_resources[indexDeposit]->getResourceName() == name) {
          return m_resources[indexDeposit]->getValue();
        }
        ++indexDeposit;
      }

      // If no deposit for this resource exists on this planet, assume the quantity is 0.
      return 0.0f;
    }

    inline
    const System& Planet::getSystem() const {
      if (m_parent == nullptr) {
        throw PlanetException(std::string("Could not retrieve system of planet ") + std::to_string(m_index) + " no associated system");
      }
      return *m_parent;
    }

    inline
    const float& Planet::getDiameter() const noexcept {
      return m_diameter;
    }

    inline
    const float& Planet::getMinTemperature() const noexcept {
      return m_minTemperature;
    }

    inline
    const float& Planet::getMaxTemperature() const noexcept {
      return m_maxTemperature;
    }

    inline
    const std::string Planet::getCoordinates() const  {
      return "[" + std::to_string(getGalaxyIndex() + 1u) + ":" + std::to_string(getSystemIndex() + 1u) + ":" + std::to_string(getPositionInSystem() + 1u) + "]";
    }

    inline
    const unsigned Planet::getShipCount(const Ship::Type& type) const {
      // Traverse the set of ships.
      unsigned indexShip = 0u;
      while (indexShip < m_ships.size()) {
        if (m_ships[indexShip] != nullptr && m_ships[indexShip]->getType() == type) {
          return m_ships[indexShip]->getCount();
        }
        ++indexShip;
      }

      // Ship not found, assume 0 count.
      return 0u;
    }

    inline
    const core::Ship& Planet::getShipData(const Ship::Type& type) const {
      // Traverse the set of ships.
      unsigned indexShip = 0u;
      while (indexShip < m_ships.size()) {
        if (m_ships[indexShip] != nullptr && m_ships[indexShip]->getType() == type) {
          return *m_ships[indexShip];
        }
        ++indexShip;
      }

      // Ship not found, this is a problem.
      const std::string errorMessage = std::string("Cannot retrieve data for ship ") +
        std::to_string(static_cast<int>(type)) +
        ", data not available in planet " +
        getName();
      throw PlanetException(errorMessage);
    }

    inline
    const unsigned Planet::getDefenseCount(const Defense::Type& type) const {
      // Traverse the set of defenses.
      unsigned indexDefense = 0u;
      while (indexDefense < m_defenses.size()) {
        if (m_defenses[indexDefense] != nullptr && m_defenses[indexDefense]->getType() == type) {
          return m_defenses[indexDefense]->getCount();
        }
        ++indexDefense;
      }

      // Defense not found, assume 0 count.
      return 0u;
    }

    inline
    const core::Defense& Planet::getDefenseData(const Defense::Type& type) const {
      // Traverse the set of defenses.
      unsigned indexDefenses = 0u;
      while (indexDefenses < m_defenses.size()) {
        if (m_defenses[indexDefenses] != nullptr && m_defenses[indexDefenses]->getType() == type) {
          return *m_defenses[indexDefenses];
        }
        ++indexDefenses;
      }

      // Defense not found, this is a problem.
      const std::string errorMessage = std::string("Cannot retrieve data for defense ") +
        std::to_string(static_cast<int>(type)) +
        ", data not available in planet " +
        getName();
      throw PlanetException(errorMessage);
    }

    inline
    void Planet::initializeShips() {
      // Create all ships on this planet.
      m_ships.push_back(std::make_shared<Ship>(Ship::Type::LightFighter));
      m_ships.push_back(std::make_shared<Ship>(Ship::Type::HeavyFighter));
      m_ships.push_back(std::make_shared<Ship>(Ship::Type::Cruiser));
      m_ships.push_back(std::make_shared<Ship>(Ship::Type::Battleship));

      m_ships.push_back(std::make_shared<Ship>(Ship::Type::SmallCargo));
      m_ships.push_back(std::make_shared<Ship>(Ship::Type::LargeCargo));
      m_ships.push_back(std::make_shared<Ship>(Ship::Type::ColonyShip));

      m_ships.push_back(std::make_shared<Ship>(Ship::Type::Battlecruiser));
      m_ships.push_back(std::make_shared<Ship>(Ship::Type::Bomber));
      m_ships.push_back(std::make_shared<Ship>(Ship::Type::Destroyer));
      m_ships.push_back(std::make_shared<Ship>(Ship::Type::Deathstar));

      m_ships.push_back(std::make_shared<Ship>(Ship::Type::Recycler));
      m_ships.push_back(std::make_shared<Ship>(Ship::Type::EspionageProbe));
      m_ships.push_back(std::make_shared<Ship>(Ship::Type::SolarSatellite));
    }

    inline
    void Planet::initializeDefenses() {
      m_defenses.push_back(std::make_shared<Defense>(Defense::Type::MissileLauncher));
      m_defenses.push_back(std::make_shared<Defense>(Defense::Type::LightLaser));
      m_defenses.push_back(std::make_shared<Defense>(Defense::Type::HeavyLaser));
      m_defenses.push_back(std::make_shared<Defense>(Defense::Type::GaussCannon));
      m_defenses.push_back(std::make_shared<Defense>(Defense::Type::IonCannon));
      m_defenses.push_back(std::make_shared<Defense>(Defense::Type::PlasmaTurret));
      m_defenses.push_back(std::make_shared<Defense>(Defense::Type::SmallShieldDome));
      m_defenses.push_back(std::make_shared<Defense>(Defense::Type::LargeShieldDome));
      m_defenses.push_back(std::make_shared<Defense>(Defense::Type::AntiballisticMissile));
      m_defenses.push_back(std::make_shared<Defense>(Defense::Type::InterplanetaryMissile));
    }

  }
}

#endif // PLANET_HXX
