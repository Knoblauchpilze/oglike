#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <memory>
#include <vector>
#include <map>
#include "ActionListener.h"
#include "Account.h"
#include "Planet.h"

namespace ogame {
  namespace player {

    class ActionListener;
    enum class Action;

    // Enumeration to describe available views.
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

    class DataModel
    {
      public:

        DataModel(const std::string& name,
                  const View& initView);

        ~DataModel();

        const std::string& getName() const noexcept;

        void registerForAction(const Action& action, ActionListener* listener);

        void triggerAction(const Action& action);

        void setActiveAccount(core::Account* account);

        void setActivePlanet(core::Planet* planet);

        void setActiveView(const View& view);

        const core::Account& getActiveAccount() const;

        const core::Planet& getActivePlanet() const;

        const View& getActiveView() const;

      private:

        using ListenersByAction = std::map<Action, std::vector<ActionListener*>>;

        std::string m_name;
        ListenersByAction m_listeners;
        core::Account* m_activeAccount;
        core::Planet* m_activePlanet;
        View m_activeView;

    };

    using DataModelShPtr = std::shared_ptr<DataModel>;
  }
}

#include "DataModel.hxx"

#endif // DATAMODEL_H
