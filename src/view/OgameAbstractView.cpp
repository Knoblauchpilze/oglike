
#include "OgameAbstractView.h"
#include "ViewException.h"
#include "EventException.h"

namespace ogame {
  namespace view {

    OgameAbstractView::OgameAbstractView(const std::string& title, const std::string& icon, const unsigned& width, const unsigned& height):
      m_title(title),
      m_icon(icon),
      m_framerate(60.0),
      m_frameDuration(1000.0 / m_framerate),
      m_screen(nullptr),
      m_processing(false),
      m_listeners(),
      m_drawables()
    {
      // Create the main window.
      createWindow(width, height);
    }

    OgameAbstractView::~OgameAbstractView() {
      // Do not destroy the main screen as it is the main sdl window.
    }

    void OgameAbstractView::createWindow(const unsigned& width, const unsigned& height) {
      int initializationStatus(SDL_Init(SDL_INIT_VIDEO));
      if (initializationStatus != 0) {
        throw ogame::view::ViewException("Could not properly initialize sdl rendering context, window not created.");
      }
      m_screen = SDL_SetVideoMode(width, height, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
      SDL_FillRect(m_screen, nullptr, SDL_MapRGB(m_screen->format, 0, 128, 0));
      if (m_screen == nullptr) {
        std::string errorMessage("Could not create sdl window: ");
        errorMessage += SDL_GetError();
        throw ogame::view::ViewException(errorMessage);
      }
      SDL_Surface* iconAsSurface(SDL_LoadBMP(m_icon.c_str()));
      SDL_WM_SetIcon(iconAsSurface, nullptr);
      SDL_WM_SetCaption(m_title.c_str(), nullptr);
    }

    void OgameAbstractView::performRendering() {
      m_processing = true;
      do {
        events();
        render();
      }
      while (m_processing);
    }

    void OgameAbstractView::events() {
      bool stillEventsInQueue(true);
      while (stillEventsInQueue) {
        // Retrieve a single event
        SDL_Event currentEvent;
        int retValue(SDL_PollEvent(&currentEvent));
        // Check if we need to process this event
        if (!retValue) {
          // No more events
          stillEventsInQueue = false;
        }
        else {
          try {
            processSingleEvent(currentEvent);
          }
          catch (ogame::view::EventException& e) {
            std::cerr << "[VIEW] Caught exception while processing event: " << std::endl << e.what() << std::endl;
          }
        }
      }
    }

    void OgameAbstractView::processSingleEvent(const SDL_Event& event) {
      switch (event.type) {
      case SDL_QUIT:
        processExitEvent(event);
        break;
      case SDL_KEYDOWN:
        processKeyPressedEvent(event);
        break;
      case SDL_KEYUP:
        processKeyReleasedEvent(event);
        break;
      case SDL_MOUSEMOTION:
        processMouseMotionEvent(event);
        break;
      case SDL_MOUSEBUTTONDOWN:
        processMouseButtonPressedEvent(event);
        break;
      case SDL_MOUSEBUTTONUP:
        processMouseButtonReleasedEvent(event);
        break;
      default:
        // Do nothing
        break;
      }
    }

    void OgameAbstractView::processExitEvent(const SDL_Event& event) {
      std::cout << "[VIEW] Processing exit event and calling " << m_listeners.size() << " listeners" << std::endl;
      m_processing = false;
      for (std::vector<SdlEventListener*>::iterator listenersIterator = m_listeners.begin();
          listenersIterator != m_listeners.end();
          ++listenersIterator)
      {
        (*listenersIterator)->onExitEvent(event);
      }
    }

    void OgameAbstractView::processKeyPressedEvent(const SDL_Event& event) {
      std::cout << "[VIEW] Processing key pressed event and calling " << m_listeners.size() << " listeners" << std::endl;
      for (std::vector<SdlEventListener*>::iterator listenersIterator = m_listeners.begin();
          listenersIterator != m_listeners.end();
          ++listenersIterator)
      {
        (*listenersIterator)->onKeyPressedEvent(event.key);
      }
    }

    void OgameAbstractView::processKeyReleasedEvent(const SDL_Event& event) {
      std::cout << "[VIEW] Processing key released event and calling " << m_listeners.size() << " listeners" << std::endl;
      for (std::vector<SdlEventListener*>::iterator listenersIterator = m_listeners.begin();
          listenersIterator != m_listeners.end();
          ++listenersIterator)
      {
        (*listenersIterator)->onKeyReleasedEvent(event.key);
      }
    }

    void OgameAbstractView::processMouseMotionEvent(const SDL_Event& event) {
      // std::cout << "[VIEW] Processing mouse motion event and calling " << m_listeners.size() << " listeners" << std::endl;
      for (std::vector<SdlEventListener*>::iterator listenersIterator = m_listeners.begin();
          listenersIterator != m_listeners.end();
          ++listenersIterator)
      {
        (*listenersIterator)->onMouseMotionEvent(event.motion);
      }
    }

    void OgameAbstractView::processMouseButtonPressedEvent(const SDL_Event& event) {
      // Check for wheel event.
      if (event.button.button == SDL_BUTTON_WHEELDOWN ||
          event.button.button == SDL_BUTTON_WHEELUP)
      {
        processMouseWheelEvent(event);
      }
      else {
        std::cout << "[VIEW] Processing mouse button pressed event and calling " << m_listeners.size() << " listeners" << std::endl;
        for (std::vector<SdlEventListener*>::iterator listenersIterator = m_listeners.begin();
            listenersIterator != m_listeners.end();
            ++listenersIterator)
        {
          (*listenersIterator)->onMouseButtonPressedEvent(event.button);
        }
      }
    }

    void OgameAbstractView::processMouseButtonReleasedEvent(const SDL_Event& event) {
      std::cout << "[VIEW] Processing mouse button released event and calling " << m_listeners.size() << " listeners" << std::endl;
      for (std::vector<SdlEventListener*>::iterator listenersIterator = m_listeners.begin();
          listenersIterator != m_listeners.end();
          ++listenersIterator)
      {
        (*listenersIterator)->onMouseButtonReleasedEvent(event.button);
      }
    }

    void OgameAbstractView::processMouseWheelEvent(const SDL_Event& event) {
      std::cout << "[VIEW] Processing mouse wheel " << (event.button.button==SDL_BUTTON_WHEELUP?"up":"down") << " event and calling " << m_listeners.size() << " listeners" << std::endl;
      for (std::vector<SdlEventListener*>::iterator listenersIterator = m_listeners.begin();
          listenersIterator != m_listeners.end();
          ++listenersIterator)
      {
        (*listenersIterator)->onMouseWheelEvent(event.button.button == SDL_BUTTON_WHEELUP);
      }
    }

    void OgameAbstractView::render() {
      const unsigned int startingRenderingTime(SDL_GetTicks());
      renderDrawables();
      SDL_Flip(m_screen);
      const unsigned int renderingDuration(SDL_GetTicks() - startingRenderingTime);
      if (renderingDuration > m_frameDuration) {
        std::cerr << "Frame took " << renderingDuration << "ms which is greater than the " << m_frameDuration << "ms authorized to maintain " << m_framerate << "fps" << std::endl;
      }
      else {
        const unsigned int remainingDuration(m_frameDuration - renderingDuration);
        if (remainingDuration > 3u) {
          SDL_Delay(remainingDuration);
        }
      }
    }

    void OgameAbstractView::renderDrawables() {
      //std::cout << "[APPLICATION] Rendering " << m_drawables.size() << " drawables (" << m_framerate << " fps)" << std::endl;
      for (std::vector<Drawable*>::iterator drawablesIterator = m_drawables.begin() ;
          drawablesIterator != m_drawables.end() ;
          ++drawablesIterator)
      {
        Drawable* drawable(*drawablesIterator);
        // Draw this object (caching is handled by the object itself).
        SDL_Surface* picture = drawable->draw();
        // Draw the picture
        utils::Area render = drawable->getRenderingArea();
        SDL_Rect dstArea;
        dstArea.x = static_cast<short int>(render.x());
        dstArea.y = static_cast<short int>(render.y());
        dstArea.w = static_cast<short int>(render.w());
        dstArea.h = static_cast<short int>(render.h());
        drawSurface(picture, nullptr, &dstArea);
      }
    }

  }
}
