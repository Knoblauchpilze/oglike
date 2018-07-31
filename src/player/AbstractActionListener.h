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

        virtual void onActionTriggered(const AbstractDataModel& model, const Action& action) = 0;

      protected:

        void setActiveView(const View& view) const;

        void setActivePlanet(core::Planet* planet) const;

        void setActiveAccount(core::Account* account) const;

        void setActiveSystemCoordinate(const unsigned& coordinate) const;

        void setActiveGalaxyCoordinate(const unsigned& coordinate) const;

        void setActiveResearch(const core::Research::Type& research) const;

        void setActiveBuilding(const core::Building::Type& building) const;

        void setActiveShip(const core::Ship::Type& ship) const;

        void setActiveDefense(const core::Defense::Type& defense) const;

        void setUnitCount(const unsigned& count) const;

        void triggerAction(const Action& action) const;

      protected:

        AbstractDataModel& getDataModel();

        const AbstractDataModel& getDataModel() const;

      private:

        mutable AbstractDataModel* m_model;

    };

    using AbstractActionListenerShPtr = std::shared_ptr<AbstractActionListener>;

  }
}

#include "AbstractActionListener.hxx"

#endif // ABSTRACTACTIONLISTENER_H
