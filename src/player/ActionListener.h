#ifndef ACTIONLISTENER_H
#define ACTIONLISTENER_H

#include <memory>
#include "DataModel.h"

namespace ogame {
  namespace player {

    class DataModel;
    enum class View;

    // Enumeration to describe available actions.
    enum class Action {
      None,
      ChangeView,
      ChangePlanet,
      ChangeAccount
    };

    class ActionListener
    {
      public:

        ActionListener(DataModel* model);

        ~ActionListener();

        virtual void onActionTriggered(const player::DataModel& model) = 0;

      protected:

        void setActiveView(const View& view);

        void triggerAction(const Action& action);

      private:

        DataModel* m_model;

    };

    using ActionListenerShPtr = std::shared_ptr<ActionListener>;
  }
}

#include "ActionListener.hxx"

#endif // ACTIONLISTENER_H
