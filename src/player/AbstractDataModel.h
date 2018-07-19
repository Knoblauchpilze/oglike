#ifndef ABSTRACTDATAMODEL_H
#define ABSTRACTDATAMODEL_H

#include <memory>
#include <vector>
#include <map>
#include "AbstractActionListener.h"
#include "DataModelConstants.h"
#include "Planet.h"
#include "Account.h"
#include "SystemCoordinates.h"

namespace ogame {
  namespace player {

    class AbstractActionListener;

    class AbstractDataModel
    {
      public:

        AbstractDataModel(const std::string& name);

        ~AbstractDataModel();

        const std::string& getName() const noexcept;

        void registerForAction(const Action& action, AbstractActionListener* listener);

        void triggerAction(const Action& action);

        void setActiveView(const View& view);

        void setActivePlanet(core::Planet* planet);

        void setActiveAccount(core::Account* account);

        void setActiveSystemCoordinate(const unsigned& coordinate);

        void setActiveGalaxyCoordinate(const unsigned& coordinate);

        const View& getActiveView() const;

        const core::Planet& getActivePlanet() const;

        const core::Account& getActiveAccount() const;

        const unsigned& getActiveSystemCoordinate() const;

        const unsigned& getActiveGalaxyCoordinate() const;

      private:

        using ListenersByAction = std::map<Action, std::vector<AbstractActionListener*>>;

        std::string m_name;
        ListenersByAction m_listeners;

        View m_activeView;
        core::Planet* m_activePlanet;
        core::Account* m_activeAccount;
        unsigned m_activeSystemCoordinate;
        unsigned m_activeGalaxyCoordinate;

    };

  }
}

#endif // ABSTRACTDATAMODEL_H
