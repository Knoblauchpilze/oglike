#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <memory>
#include <vector>
#include "ActionListener.h"
#include "Account.h"
#include "Planet.h"

namespace ogame {
  namespace player {

    class ActionListener;

    class DataModel
    {
      public:

        enum class View {
          Overview,
          Resources,
          Facilities,
          Research,
          Shipyard,
          Defense,
          Fleet,
          Galaxy,
          Alliance
        };

        DataModel(const View& initView);

        ~DataModel();

        void registerForAction(const ActionListener::Action& action, ActionListener* listener);

        void triggerAction(const ActionListener::Action& action);

        void setActiveAccount(core::Account* account);

        void setActivePlanet(core::Planet* planet);

        void setActiveView(const View& view);

        const core::Account& getActiveAccount() const;

        const core::Planet& getActivePlanet() const;

        const View& getActiveView() const;

      private:

        std::vector<ActionListener*> m_listeners;
        core::Account* m_activeAccount;
        core::Planet* m_activePlanet;
        View m_activeView;

    };

    using DataModelShPtr = std::shared_ptr<DataModel>;
  }
}

#include "DataModel.hxx"

#endif // DATAMODEL_H
