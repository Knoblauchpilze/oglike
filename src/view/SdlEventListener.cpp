
#include "SdlEventListener.h"

namespace ogame {
  namespace view {

    SdlEventListener::SdlEventListener() {}

    SdlEventListener::~SdlEventListener() {}

    void SdlEventListener::onExitEvent(const SDL_Event&) {}

    void SdlEventListener::onKeyPressedEvent(const SDL_KeyboardEvent&) {}

    void SdlEventListener::onKeyReleasedEvent(const SDL_KeyboardEvent&) {}

    void SdlEventListener::onMouseMotionEvent(const SDL_MouseMotionEvent&) {}

    void SdlEventListener::onMouseButtonPressedEvent(const SDL_MouseButtonEvent&) {}

    void SdlEventListener::onMouseButtonReleasedEvent(const SDL_MouseButtonEvent&) {}

    void SdlEventListener::onMouseWheelEvent(bool upwheel) {}

  }
}
