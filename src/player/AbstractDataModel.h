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
#include "Research.h"
#include "Building.h"
#include "Ship.h"
#include "Defense.h"

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

        void setActiveResearch(const core::Research::Type& research);

        void setActiveBuilding(const core::Building::Type& research);

        void setActiveShip(const core::Ship::Type& research);

        void setActiveDefense(const core::Defense::Type& research);

        const View& getActiveView() const;

        const core::Planet& getActivePlanet() const;

        core::Planet& getActivePlanet();

        const core::Account& getActiveAccount() const;

        core::Account& getActiveAccount();

        const unsigned& getActiveSystemCoordinate() const;

        const unsigned& getActiveGalaxyCoordinate() const;

        const core::Research::Type& getActiveResearch() const noexcept;

        const core::Building::Type& getActiveBuilding() const noexcept;

        const core::Ship::Type& getActiveShip() const noexcept;

        const core::Defense::Type& getActiveDefense() const noexcept;

      private:

        using ListenersByAction = std::map<Action, std::vector<AbstractActionListener*>>;

        std::string m_name;
        ListenersByAction m_listeners;

        View m_activeView;
        core::Planet* m_activePlanet;
        core::Account* m_activeAccount;
        unsigned m_activeSystemCoordinate;
        unsigned m_activeGalaxyCoordinate;
        core::Research::Type m_research;
        core::Building::Type m_building;
        core::Ship::Type m_ship;
        core::Defense::Type m_defense;

    };

  }
}

#include "AbstractDataModel.hxx"

#endif // ABSTRACTDATAMODEL_H
