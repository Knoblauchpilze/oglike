#ifndef STATE_CONTAINER_HXX
#define STATE_CONTAINER_HXX

#include "StateContainer.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    inline
    const StateContainer::State StateContainer::getState() {
      lock();
      State state = getStatePrivate();
      unlock();
      return state;
    }

    inline
    void StateContainer::onMouseMotionEventPrivate(const SDL_MouseMotionEvent& mouseMotionEvent) {
      // This container can be highlighted using a mouse motion.
      const float x = static_cast<float>(mouseMotionEvent.x);
      const float y = static_cast<float>(mouseMotionEvent.y);

      // std::cout << "-----" << std::endl;
      if (isInside(x, y) && m_state != State::Selected) {
        if (m_state != State::Highlighted) {
          // std::cout << "[STATE] " << getName()
          //           << " mouse: " << x << "x" << y
          //           << ", area=" << getRenderingAreaPrivate().x() << "x" << getRenderingAreaPrivate().y()
          //           << " dims=" << getRenderingAreaPrivate().w() << "x" << getRenderingAreaPrivate().h()
          //           << ", state was " << (m_state == State::Selected ? "selected" : m_state == State::Highlighted ? "highlighted": "normal")
          //           << " and is now highlighted"
          //           << std::endl;
          m_state = State::Highlighted;
          assignColorFromState(m_state);
        }
      }
      // std::cout << "-----" << std::endl;
      // std::cout << "*****" << std::endl;
      if (!isInside(x, y) && m_state != State::Normal) {
        if (m_state != State::Selected) {
          // std::cout << "[STATE] " << getName()
          //           << " mouse: " << x << "x" << y
          //           << ", area=" << getRenderingAreaPrivate().x() << "x" << getRenderingAreaPrivate().y()
          //           << " dims=" << getRenderingAreaPrivate().w() << "x" << getRenderingAreaPrivate().h()
          //           << ", state was " << (m_state == State::Selected ? "selected" : m_state == State::Highlighted ? "highlighted": "normal")
          //           << " and is now normal"
          //           << std::endl;
          m_state = State::Normal;
          assignColorFromState(m_state);
        }
      }
      // std::cout << "*****" << std::endl;
    }

    inline
    void StateContainer::onMouseButtonReleasedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent) {
      // This container can be selected using a mouse button pressed.
      const float x = static_cast<float>(mouseButtonEvent.x);
      const float y = static_cast<float>(mouseButtonEvent.y);

      if (isInside(x, y) && m_state != State::Selected) {
        m_state = State::Selected;
        assignColorFromState(m_state);
      }
      if (!isInside(x, y) && m_state != State::Normal) {
        m_state = State::Normal;
        assignColorFromState(m_state);
      }
    }

    inline
    void StateContainer::onStateModified() {
      // Nothing to do here.
    }

    inline
    const StateContainer::State& StateContainer::getStatePrivate() const noexcept {
      return m_state;
    }

    inline
    const SDL_Color StateContainer::getColorFromState(const State& state) const noexcept {
      const StateAssociation::const_iterator color = m_colors.find(state);
      if (color != m_colors.cend()) {
          return color->second;
      }

      // Could not find a color for this state.
      throw GuiException(std::string("Could not find color for state in container ") + getName());
    }

    inline
    void StateContainer::assignColorFromState(const State& state) {
      try {
        SDL_Color color = getColorFromState(state);
        setBackgroundColor(color);
      }
      catch (const GuiException& e) {
        // Handle according to the policy.
        if (m_policy == FailPolicy::Aggressive) {
          assignNormalStateOrDefault();
        }
      }
    }

    inline
    void StateContainer::assignNormalStateOrDefault() {
      // Search for the normal state.
      const StateAssociation::const_iterator color = m_colors.find(State::Normal);
      if (color != m_colors.cend()) {
        setBackgroundColor(color->second);
      }
    }

  }
}

#endif // STATE_CONTAINER_HXX