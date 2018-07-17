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

        template <typename Property>
        void addProperty(const std::string& name, Property* property);

        template <typename Property>
        void setProperty(const std::string& name, Property* property);

      private:

        using ListenersByAction = std::map<Action, std::vector<AbstractActionListener<Action>*>>;
        using Properties = std::unordered_map<std::string, void*>;

        std::string m_name;
        ListenersByAction m_listeners;
        Properties m_properties;

    };

  }
}

#include "AbstractDataModel.hxx"

#endif // ABSTRACTDATAMODEL_H
