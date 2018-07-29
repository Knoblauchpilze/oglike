
#include "AbstractActionListener.h"
#include "DataModelException.h"

namespace ogame {
  namespace player {

    AbstractActionListener::AbstractActionListener(AbstractDataModel* model):
      m_model(model)
    {
      // Nothing to do here.
    }

    AbstractActionListener::~AbstractActionListener() {}

    void AbstractActionListener::setActiveView(const View& view) const {
      m_model->setActiveView(view);
    }

    void AbstractActionListener::setActivePlanet(core::Planet* planet) const {
      if (planet == nullptr) {
        throw DataModelException(std::string("Cannot set active planet in model ") + m_model->getName() + ", invalid null pointer");
      }
      m_model->setActivePlanet(planet);
    }

    void AbstractActionListener::setActiveAccount(core::Account* account) const {
      if (account == nullptr) {
        throw DataModelException(std::string("Cannot set active account in model ") + m_model->getName() + ", invalid null pointer");
      }
      m_model->setActiveAccount(account);
    }

    void AbstractActionListener::setActiveSystemCoordinate(const unsigned& coordinate) const {
      m_model->setActiveSystemCoordinate(coordinate);
    }

    void AbstractActionListener::setActiveGalaxyCoordinate(const unsigned& coordinate) const {
      m_model->setActiveGalaxyCoordinate(coordinate);
    }

    void AbstractActionListener::setActiveResearch(const core::Research::Type& research) const {
      m_model->setActiveResearch(research);
    }

    void AbstractActionListener::setActiveBuilding(const core::Building::Type& building) const {
      m_model->setActiveBuilding(building);
    }

    void AbstractActionListener::setActiveShip(const core::Ship::Type& ship) const {
      m_model->setActiveShip(ship);
    }

    void AbstractActionListener::setActiveDefense(const core::Defense::Type& defense) const {
      m_model->setActiveDefense(defense);
    }

    void AbstractActionListener::triggerAction(const Action& action) const {
      if (m_model == nullptr) {
        throw DataModelException(std::string("Cannot trigger action, invalid null data model"));
      }
      m_model->triggerAction(action);
    }

  }
}
