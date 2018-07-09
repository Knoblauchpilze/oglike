#ifndef STATE_CONTAINER_H
#define STATE_CONTAINER_H

#include <memory>
#include <vector>
#include <SDL/SDL.h>
#include "GraphicContainer.h"

namespace ogame {
  namespace gui {

    class StateContainer: public view::GraphicContainer
    {
      public:

        enum class State {
          Normal,
          Highlighted,
          Selected
        };

        using StateAssociation = std::vector<std::pair<State, SDL_Color>>;

        StateContainer(const std::string& name,
                       const State& initState,
                       const StateAssociation& colors);

        virtual ~StateContainer();

      protected:

        void onMouseMotionEventPrivate(const SDL_MouseMotionEvent& mouseMotionEvent) override;

        void onMouseButtonReleasedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent) override;

      private:

        const SDL_Color getColorFromState(const State& state) const noexcept;

      private:

        State m_state;
        StateAssociation m_colors;

    };

    using StateContainerShPtr = std::shared_ptr<StateContainer>;
  }
}

#include "StateContainer.hxx"

#endif // STATE_CONTAINER_H
