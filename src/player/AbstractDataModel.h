#ifndef ABSTRACTDATAMODEL_H
#define ABSTRACTDATAMODEL_H

#include <memory>
#include <vector>
#include <map>
#include "AbstractActionListener.h"

namespace ogame {
  namespace player {

    template <class Action>
    class AbstractActionListener;

    template <typename Action>
    class AbstractDataModel
    {
      public:

        AbstractDataModel(const std::string& name);

        ~AbstractDataModel();

        const std::string& getName() const noexcept;

        void registerForAction(const Action& action, AbstractActionListener<Action>* listener);

        void triggerAction(const Action& action);

      private:

        using ListenersByAction = std::map<Action, std::vector<AbstractActionListener<Action>*>>;

        std::string m_name;
        ListenersByAction m_listeners;

    };

  }
}

#include "AbstractDataModel.hxx"

#endif // ABSTRACTDATAMODEL_H
