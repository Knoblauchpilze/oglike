#ifndef DATAMODEL_HXX
#define DATAMODEL_HXX

#include "DataModel.h"
#include "DataModelException.h"

namespace ogame {
  namespace player {

    inline
    void DataModel::registerForAction(const ActionListener::Action& action, ActionListener* listener) {
      if (listener != nullptr) {
        if (!listener->hasAction()) {
          listener->setAction(action);
        }
        m_listeners.push_back(listener);
      }
    }

    inline
    void DataModel::setActiveAccount(core::Account* account) {
      if (m_activeAccount != account) {
        m_activeAccount = account;

        // Assign the active planet to be the homeworld of this account.
        if (m_activeAccount != nullptr) {
          setActivePlanet(&m_activeAccount->getHomeWorld());
        }

        // Finally trigger the change account action.
        triggerAction(ActionListener::Action::ChangeAccount);
      }
    }

    inline
    void DataModel::setActivePlanet(core::Planet* planet) {
      if (m_activePlanet != planet) {
        m_activePlanet = planet;
        triggerAction(ActionListener::Action::ChangePlanet);
      }
    }

    inline
    void DataModel::setActiveView(const View& view) {
      if (m_activeView != view) {
        m_activeView = view;
        triggerAction(ActionListener::Action::ChangeView);
      }
    }

    inline
    const core::Account& DataModel::getActiveAccount() const {
      if (m_activeAccount == nullptr) {
        throw DataModelException(std::string("Cannot retrieve active account, invalid null pointer"));
      }
      return *m_activeAccount;
    }

    inline
    const core::Planet& DataModel::getActivePlanet() const {
      if (m_activePlanet == nullptr) {
        throw DataModelException(std::string("Cannot retrieve active planet, invalid null pointer"));
      }
      return *m_activePlanet;
    }

    inline
    const DataModel::View& DataModel::getActiveView() const {
      return m_activeView;
    }

  }
}

#endif // DATAMODEL_HXX
