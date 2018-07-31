#ifndef ABSTRACTDATAMODEL_HXX
#define ABSTRACTDATAMODEL_HXX

#include "AbstractDataModel.h"
#include "DataModelException.h"

namespace ogame {
  namespace player {

    inline
    void AbstractDataModel::setActiveView(const View& view) {
      m_activeView = view;
      triggerAction(Action::ChangeView);
    }

    inline
    void AbstractDataModel::setActivePlanet(core::Planet* planet) {
      if (planet == nullptr) {
        throw DataModelException(std::string("Cannot set active planet for model ") + getName() + ", invalid null pointer");
      }
      m_activePlanet = planet;
      triggerAction(Action::ChangePlanet);
    }

    inline
    void AbstractDataModel::setActiveAccount(core::Account* account) {
      if (account == nullptr) {
        throw DataModelException(std::string("Cannot set active account for model ") + getName() + ", invalid null pointer");
      }
      m_activeAccount = account;
      triggerAction(Action::ChangeAccount);
    }

    inline
    void AbstractDataModel::setActiveSystemCoordinate(const unsigned& coordinate) {
      m_activeSystemCoordinate = coordinate;
      triggerAction(Action::ChangeSystem);
    }

    inline
    void AbstractDataModel::setActiveGalaxyCoordinate(const unsigned& coordinate) {
      m_activeGalaxyCoordinate = coordinate;
      triggerAction(Action::ChangeGalaxy);
    }

    inline
    void AbstractDataModel::setActiveResearch(const core::Research::Type& research) {
      m_research = research;
    }

    inline
    void AbstractDataModel::setActiveBuilding(const core::Building::Type& building) {
      m_building = building;
    }

    inline
    void AbstractDataModel::setActiveShip(const core::Ship::Type& ship) {
      m_ship = ship;
    }

    inline
    void AbstractDataModel::setActiveDefense(const core::Defense::Type& defense) {
      m_defense = defense;
    }

    inline
    void AbstractDataModel::setUnitCount(const unsigned& value) {
      m_unitCount = value;
    }

    inline
    const View& AbstractDataModel::getActiveView() const {
      return m_activeView;
    }

    inline
    const core::Planet& AbstractDataModel::getActivePlanet() const {
      if (m_activePlanet == nullptr) {
        throw DataModelException(std::string("Cannot retrieve active planet for model ") + getName() + ", invalid null pointer");
      }
      return *m_activePlanet;
    }

    inline
    core::Planet& AbstractDataModel::getActivePlanet() {
      if (m_activePlanet == nullptr) {
        throw DataModelException(std::string("Cannot retrieve active planet for model ") + getName() + ", invalid null pointer");
      }
      return *m_activePlanet;
    }

    inline
    const core::Account& AbstractDataModel::getActiveAccount() const {
      if (m_activeAccount == nullptr) {
        throw DataModelException(std::string("Cannot retrieve active account for model ") + getName() + ", invalid null pointer");
      }
      return *m_activeAccount;
    }

    inline
    core::Account& AbstractDataModel::getActiveAccount() {
      if (m_activeAccount == nullptr) {
        throw DataModelException(std::string("Cannot retrieve active account for model ") + getName() + ", invalid null pointer");
      }
      return *m_activeAccount;
    }

    inline
    const unsigned& AbstractDataModel::getActiveSystemCoordinate() const {
      return m_activeSystemCoordinate;
    }

    inline
    const unsigned& AbstractDataModel::getActiveGalaxyCoordinate() const {
      return m_activeGalaxyCoordinate;
    }

    inline
    const core::Research::Type& AbstractDataModel::getActiveResearch() const noexcept {
      return m_research;
    }

    inline
    const core::Building::Type& AbstractDataModel::getActiveBuilding() const noexcept {
      return m_building;
    }

    inline
    const core::Ship::Type& AbstractDataModel::getActiveShip() const noexcept {
      return m_ship;
    }

    inline
    const core::Defense::Type& AbstractDataModel::getActiveDefense() const noexcept {
      return m_defense;
    }

    inline
    const unsigned& AbstractDataModel::getUnitCount() const noexcept {
      return m_unitCount;
    }

  }
}

#endif // ABSTRACTDATAMODEL_HXX
