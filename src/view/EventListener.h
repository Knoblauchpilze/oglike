#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include <SDL/SDL.h>

namespace ogame {
  namespace view {

    class EventListener
    {
      public:

        struct Interaction {
          using Mask = unsigned char;

          static constexpr Mask NoInteraction = 0x00;

          static constexpr Mask KeyPressed = 0x01;
          static constexpr Mask KeyReleased = 0x02;
          static constexpr Mask Key = KeyPressed | KeyReleased;

          static constexpr Mask MouseButtonPressed = 0x04;
          static constexpr Mask MouseButtonReleased = 0x08;
          static constexpr Mask MouseButton = MouseButtonPressed | MouseButtonReleased;

          static constexpr Mask MouseMotion = 0x10;

          static constexpr Mask MouseWheelDown = 0x20;
          static constexpr Mask MouseWheelUp = 0x40;
          static constexpr Mask MouseWheel = MouseWheelDown | MouseWheelUp;

          static constexpr Mask Mouse = MouseButton | MouseMotion | MouseWheel;

          static constexpr Mask FullInteraction = Key | Mouse;

        };

        enum class Sensitivity {
          Global,
          Local
        };

      public:

        EventListener(const Interaction::Mask& mask, const Sensitivity& sensitivity = Sensitivity::Local);

        virtual ~EventListener();

        const Interaction::Mask& getInteractionMask() const noexcept;

        virtual void onExitEvent(const SDL_Event& exitEvent);

        virtual void onKeyPressedEvent(const SDL_KeyboardEvent& keyEvent);

        virtual void onKeyReleasedEvent(const SDL_KeyboardEvent& keyEvent);

        virtual void onMouseMotionEvent(const SDL_MouseMotionEvent& mouseMotionEvent);

        virtual void onMouseButtonPressedEvent(const SDL_MouseButtonEvent& mouseButtonEvent);

        virtual void onMouseButtonReleasedEvent(const SDL_MouseButtonEvent& mouseButtonEvent);

        virtual void onMouseWheelEvent(bool upWheel);

      protected:

        bool isRelevant(const Interaction::Mask& event, const bool inside) const noexcept;

      private:

        Interaction::Mask m_mask;
        Sensitivity m_sensitivity;

    };

  }
}

#include "EventListener.hxx"

#endif // EVENTLISTENER_H
