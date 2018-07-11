#ifndef ACTIONLISTENER_H
#define ACTIONLISTENER_H

#include <memory>

namespace ogame {
  namespace player {

    class ActionListener
    {
      public:

        enum class Action {
          None,
          ChangeView,
          ChangePlanet,
          ChangePlayer
        };

        ActionListener(const Action& action);

        ~ActionListener();

        const Action& getAction() const noexcept;

        const bool hasAction() const noexcept;

        void setAction(const Action& action);

        virtual void onActionTriggered() = 0;

      private:

        Action m_action;

    };

    using ActionListenerShPtr = std::shared_ptr<ActionListener>;
  }
}

#include "ActionListener.hxx"

#endif // ACTIONLISTENER_H
