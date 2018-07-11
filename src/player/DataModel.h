#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <memory>
#include <vector>
#include "ActionListener.h"

namespace ogame {
  namespace player {

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

        void registerForAction(const ActionListener::Action& action, ActionListenerShPtr listener);

        void triggerActiveViewModification(const View& view);

      private:

        View m_activeView;
        std::vector<ActionListenerShPtr> m_listeners;

    };

    using DataModelShPtr = std::shared_ptr<DataModel>;
  }
}

#include "DataModel.hxx"

#endif // DATAMODEL_H
