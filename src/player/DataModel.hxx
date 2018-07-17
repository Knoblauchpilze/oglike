#ifndef DATAMODEL_HXX
#define DATAMODEL_HXX

#include "DataModel.h"
#include "DataModelException.h"
#include "ActionListener.h"

namespace ogame {
  namespace player {

    inline
    const std::string& DataModel::getName() const noexcept {
      return m_name;
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
    const View& DataModel::getActiveView() const {
      return m_activeView;
    }

  }
}

#endif // DATAMODEL_HXX
