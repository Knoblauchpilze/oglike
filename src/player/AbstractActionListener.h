#ifndef ABSTRACTACTIONLISTENER_H
#define ABSTRACTACTIONLISTENER_H

#include <memory>
#include "AbstractDataModel.h"
#include "DataModelConstants.h"
#include "Planet.h"
#include "Account.h"

namespace ogame {
  namespace player {

    class AbstractDataModel;

    class AbstractActionListener
    {
      public:

        AbstractActionListener(AbstractDataModel* model);

        ~AbstractActionListener();

        virtual void onActionTriggered(const player::AbstractDataModel& model) = 0;

      public:

        void setActiveView(const View& view) const;

        void setActivePlanet(core::Planet* planet) const;

        void setActiveAccount(core::Account* account) const;

        void setActiveSystemCoordinate(const unsigned& coordinate) const;

        void setActiveGalaxyCoordinate(const unsigned& coordinate) const;

        void triggerAction(const Action& action) const;

      protected:

        AbstractDataModel& getDataModel();

      private:

        mutable AbstractDataModel* m_model;

    };

    using AbstractActionListenerShPtr = std::shared_ptr<AbstractActionListener>;

  }
}

#include "AbstractActionListener.hxx"

#endif // ABSTRACTACTIONLISTENER_H
