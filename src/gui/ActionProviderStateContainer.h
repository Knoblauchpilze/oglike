#ifndef ACTIONPROVIDERSTATECONTAINER_H
#define ACTIONPROVIDERSTATECONTAINER_H

#include <memory>
#include <vector>
#include <SDL/SDL.h>
#include "StateContainer.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class ActionProviderStateContainer: public StateContainer, public player::GeneralActionListener
    {
      public:

        ActionProviderStateContainer(const std::string& name,
                                     const State& initState,
                                     const StateAssociation& colors,
                                     const player::View& view,
                                     player::GeneralDataModel* model,
                                     const FailPolicy& policy = FailPolicy::Aggressive);

        virtual ~ActionProviderStateContainer();

        // Nothing to do at this level.
        virtual void onActionTriggered(const player::AbstractDataModel<player::Action>& model);

      protected:

        // Called upon modifying the internal state. Can be reimplemented in inheriting classes.
        void onStateModified() override;

      private:

        player::View m_view;

    };

    using ActionProviderStateContainerShPtr = std::shared_ptr<ActionProviderStateContainer>;
  }
}

#include "ActionProviderStateContainer.hxx"

#endif // ACTIONPROVIDERSTATECONTAINER_H
