#ifndef STATE_CONTAINER_H
#define STATE_CONTAINER_H

#include <memory>
#include <vector>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include <map>

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

        // Used to describe the policy to apply by this container if a given state does not have an associated color.
        enum class FailPolicy {
          Preserve,       //< Preserve the current color (do nothing)
          Aggressive      //< Aggressively replace the color with the default state (i.e. normal).
                          //  If it is not defined fallback to preserve strategy.
        };

        using StateAssociation = std::map<State, SDL_Color>;

        StateContainer(const std::string& name,
                       const State& initState,
                       const StateAssociation& colors,
                       const FailPolicy& policy = FailPolicy::Aggressive);

        virtual ~StateContainer();

        const State getState();

        void setState(const State& state);

      protected:

        void onMouseMotionEventPrivate(const SDL_MouseMotionEvent& mouseMotionEvent) override;

        void onMouseButtonReleasedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent) override;

        // Called upon modifying the internal state. Can be reimplemented in inheriting classes.
        virtual void onStateModified();

        const State& getStatePrivate() const noexcept;

      private:

        const SDL_Color getColorFromState(const State& state) const noexcept;

        void assignColorFromState(const State& state);

        void assignNormalStateOrDefault();

      private:

        State m_state;
        FailPolicy m_policy;
        StateAssociation m_colors;
        std::map<State, int> m_toto;

    };

    using StateContainerShPtr = std::shared_ptr<StateContainer>;
  }
}

#include "StateContainer.hxx"

#endif // STATE_CONTAINER_H
