
#include "EventListener.h"

namespace ogame {
  namespace view {

    constexpr EventListener::Interaction::Mask EventListener::Interaction::NoInteraction;

    constexpr EventListener::Interaction::Mask EventListener::Interaction::KeyPressed;
    constexpr EventListener::Interaction::Mask EventListener::Interaction::KeyReleased;
    constexpr EventListener::Interaction::Mask EventListener::Interaction::Key;

    constexpr EventListener::Interaction::Mask EventListener::Interaction::MouseButtonPressed;
    constexpr EventListener::Interaction::Mask EventListener::Interaction::MouseButtonReleased;
    constexpr EventListener::Interaction::Mask EventListener::Interaction::MouseButton;

    constexpr EventListener::Interaction::Mask EventListener::Interaction::MouseMotion;

    constexpr EventListener::Interaction::Mask EventListener::Interaction::MouseWheelDown;
    constexpr EventListener::Interaction::Mask EventListener::Interaction::MouseWheelUp;
    constexpr EventListener::Interaction::Mask EventListener::Interaction::MouseWheel;

    constexpr EventListener::Interaction::Mask EventListener::Interaction::Mouse;

    constexpr EventListener::Interaction::Mask EventListener::Interaction::FullInteraction;

    EventListener::EventListener(const Interaction::Mask& mask):
      m_mask(mask)
    {
      // Nothing to do.
    }

    EventListener::~EventListener() {}

    void EventListener::onExitEvent(const SDL_Event&) {}

    void EventListener::onKeyPressedEvent(const SDL_KeyboardEvent&) {}

    void EventListener::onKeyReleasedEvent(const SDL_KeyboardEvent&) {}

    void EventListener::onMouseMotionEvent(const SDL_MouseMotionEvent&) {}

    void EventListener::onMouseButtonPressedEvent(const SDL_MouseButtonEvent&) {}

    void EventListener::onMouseButtonReleasedEvent(const SDL_MouseButtonEvent&) {}

    void EventListener::onMouseWheelEvent(bool upWheel) {}

  }
}
