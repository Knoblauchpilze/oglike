#ifndef ACTIONLISTENER_H
#define ACTIONLISTENER_H

#include <memory>

namespace ogame {
  namespace player {

    class DataModel;

    class ActionListener
    {
      public:

        enum class Action {
          None,
          ChangeView,
          ChangePlanet,
          ChangeAccount
        };

        ActionListener(const Action& action,
                       DataModel* model);

        ~ActionListener();

        const Action& getAction() const noexcept;

        const bool hasAction() const noexcept;

        void setAction(const Action& action);

        virtual void onActionTriggered(const player::DataModel& model) = 0;

      protected:

        void triggerAction();

      private:

        Action m_action;
        DataModel* m_model;

    };

    using ActionListenerShPtr = std::shared_ptr<ActionListener>;
  }
}

#include "ActionListener.hxx"

#endif // ACTIONLISTENER_H
