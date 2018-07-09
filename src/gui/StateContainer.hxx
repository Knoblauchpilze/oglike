#ifndef STATE_CONTAINER_HXX
#define STATE_CONTAINER_HXX

#include <memory>
#include <unordered_map>
#include <SDL/SDL.h>
#include "GraphicContainer.h"

namespace ogame {
  namespace gui {

    inline
    void StateContainer::onMouseMotionEventPrivate(const SDL_MouseMotionEvent& mouseMotionEvent) {
      // This container can be highlighted using a mouse motion.
      const float x = static_cast<float>(mouseMotionEvent.x);
      const float y = static_cast<float>(mouseMotionEvent.y);

      std::cout << "-----" << std::endl;
      if (isInside(x, y) && m_state != State::Selected) {
        if (m_state != State::Highlighted) {
          std::cout << "[STATE] " << getName()
                    << " mouse: " << x << "x" << y
                    << ", area=" << getRenderingAreaPrivate().x() << "x" << getRenderingAreaPrivate().y()
                    << " dims=" << getRenderingAreaPrivate().w() << "x" << getRenderingAreaPrivate().h()
                    << ", state was " << (m_state == State::Selected ? "selected" : m_state == State::Highlighted ? "highlighted": "normal")
                    << " and is now highlighted"
                    << std::endl;
          m_state = State::Highlighted;
          setBackgroundColor(getColorFromState(m_state));
        }
      }
      std::cout << "-----" << std::endl;
      std::cout << "*****" << std::endl;
      if (!isInside(x, y) && m_state != State::Normal) {
        if (m_state != State::Selected) {
          std::cout << "[STATE] " << getName()
                    << " mouse: " << x << "x" << y
                    << ", area=" << getRenderingAreaPrivate().x() << "x" << getRenderingAreaPrivate().y()
                    << " dims=" << getRenderingAreaPrivate().w() << "x" << getRenderingAreaPrivate().h()
                    << ", state was " << (m_state == State::Selected ? "selected" : m_state == State::Highlighted ? "highlighted": "normal")
                    << " and is now normal"
                    << std::endl;
          m_state = State::Normal;
          setBackgroundColor(getColorFromState(m_state));
        }
      }
      std::cout << "*****" << std::endl;
    }

    inline
    void StateContainer::onMouseButtonReleasedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent) {
      // This container can be selected using a mouse button pressed.
      const float x = static_cast<float>(mouseButtonEvent.x);
      const float y = static_cast<float>(mouseButtonEvent.y);

      if (isInside(x, y) && m_state != State::Selected) {
        m_state = State::Selected;
        setBackgroundColor(getColorFromState(m_state));
      }
      if (!isInside(x, y) && m_state != State::Normal) {
        m_state = State::Normal;
        setBackgroundColor(getColorFromState(m_state));
      }
    }

    inline
    const SDL_Color StateContainer::getColorFromState(const State& state) const noexcept {
      unsigned index = 0u;
      while (index < m_colors.size()) {
        if (m_colors[index].first == state) {
          return m_colors[index].second;
        }
        ++index;
      }

      return SDL_Color{0, 0, 0, SDL_ALPHA_OPAQUE};
    }

  }
}

#endif // STATE_CONTAINER_HXX
