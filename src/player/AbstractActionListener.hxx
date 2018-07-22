#ifndef ABSTRACTACTIONLISTENER_HXX
#define ABSTRACTACTIONLISTENER_HXX

#include "AbstractActionListener.h"
#include "DataModelException.h"

namespace ogame {
  namespace player {

    inline
    AbstractDataModel& AbstractActionListener::getDataModel() {
      if (m_model == nullptr) {
        throw DataModelException(std::string("Cannot retrieve data model, no model associated to this action listener"));
      }
      return *m_model;
    }

    inline
    const AbstractDataModel& AbstractActionListener::getDataModel() const {
      if (m_model == nullptr) {
        throw DataModelException(std::string("Cannot retrieve data model, no model associated to this action listener"));
      }
      return *m_model;
    }

  }
}

#endif // ABSTRACTACTIONLISTENER_HXX
