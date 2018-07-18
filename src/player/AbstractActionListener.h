#ifndef ABSTRACTACTIONLISTENER_H
#define ABSTRACTACTIONLISTENER_H

#include <memory>
#include "AbstractDataModel.h"

namespace ogame {
  namespace player {

    template <class Action>
    class AbstractDataModel;

    template <typename Action>
    class AbstractActionListener
    {
      public:

        AbstractActionListener(AbstractDataModel<Action>* model);

        ~AbstractActionListener();

        virtual void onActionTriggered(const player::AbstractDataModel<Action>& model) = 0;

      public:

        template <typename Property>
        void setProperty(const std::string& name, Property* property);

        void triggerAction(const Action& action);

      private:

        AbstractDataModel<Action>* m_model;

    };

  }
}

#include "AbstractActionListener.hxx"

#endif // ABSTRACTACTIONLISTENER_H
