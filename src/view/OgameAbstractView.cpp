
#include "OgameAbstractView.h"
#include "ViewException.h"
#include "EventException.h"

namespace ogame {
  namespace view {

    OgameView::OgameView(const std::string& title, const std::string& icon, const unsigned& width, const unsigned& height):
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

    OgameView::~OgameView() {
      // Do not destroy the main screen as it is the main sdl window.
    }
    
    void OgameView::addListener(SdlEventListener* listener) {
      m_listeners.push_back(listener);
    }

    void OgameView::run() {
      performRendering();
    }

    void OgameView::createWindow(const unsigned& width, const unsigned& height) {
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

    void OgameView::performRendering() {
      m_processing = true;
      do {
        events();
        render();
      }
      while (m_processing);
    }

    void OgameView::events() {
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
            std::cerr << "[VIEW] Caught exception while processing event: " << e.what() << std::endl;
          }
        }
      }
    }

    void OgameView::processSingleEvent(const SDL_Event& event) {
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

    void OgameView::processExitEvent(const SDL_Event& event) {
      std::cout << "[VIEW] Processing exit event and calling " << m_listeners.size() << " listeners" << std::endl;
      m_processing = false;
      for (std::vector<SdlEventListener*>::iterator listenersIterator = m_listeners.begin();
          listenersIterator != m_listeners.end();
          ++listenersIterator)
      {
        (*listenersIterator)->onExitEvent(event);
      }
    }

    void OgameView::processKeyPressedEvent(const SDL_Event& event) {
      std::cout << "[VIEW] Processing key pressed event and calling " << m_listeners.size() << " listeners" << std::endl;
      for (std::vector<SdlEventListener*>::iterator listenersIterator = m_listeners.begin();
          listenersIterator != m_listeners.end();
          ++listenersIterator)
      {
        (*listenersIterator)->onKeyPressedEvent(event.key);
      }
    }

    void OgameView::processKeyReleasedEvent(const SDL_Event& event) {
      std::cout << "[VIEW] Processing key released event and calling " << m_listeners.size() << " listeners" << std::endl;
      for (std::vector<SdlEventListener*>::iterator listenersIterator = m_listeners.begin();
          listenersIterator != m_listeners.end();
          ++listenersIterator)
      {
        (*listenersIterator)->onKeyReleasedEvent(event.key);
      }
    }

    void OgameView::processMouseMotionEvent(const SDL_Event& event) {
      std::cout << "[VIEW] Processing mouse motion event and calling " << m_listeners.size() << " listeners" << std::endl;
      for (std::vector<SdlEventListener*>::iterator listenersIterator = m_listeners.begin();
          listenersIterator != m_listeners.end();
          ++listenersIterator)
      {
        (*listenersIterator)->onMouseMotionEvent(event.motion);
      }
    }

    void OgameView::processMouseButtonPressedEvent(const SDL_Event& event) {
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

    void OgameView::processMouseButtonReleasedEvent(const SDL_Event& event) {
      std::cout << "[VIEW] Processing mouse button released event and calling " << m_listeners.size() << " listeners" << std::endl;
      for (std::vector<SdlEventListener*>::iterator listenersIterator = m_listeners.begin();
          listenersIterator != m_listeners.end();
          ++listenersIterator)
      {
        (*listenersIterator)->onMouseButtonReleasedEvent(event.button);
      }
    }

    void OgameView::processMouseWheelEvent(const SDL_Event& event) {
      std::cout << "[VIEW] Processing mouse wheel " << (event.button.button==SDL_BUTTON_WHEELUP?"up":"down") << " event and calling " << m_listeners.size() << " listeners" << std::endl;
      for (std::vector<SdlEventListener*>::iterator listenersIterator = m_listeners.begin();
          listenersIterator != m_listeners.end();
          ++listenersIterator)
      {
        (*listenersIterator)->onMouseWheelEvent(event.button.button == SDL_BUTTON_WHEELUP);
      }
    }

    void OgameView::render() {
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

    void OgameView::renderDrawables() {
      //std::cout << "[APPLICATION] Rendering " << m_drawables.size() << " drawables (" << m_framerate << " fps)" << std::endl;
      for (std::vector<Drawable*>::iterator drawablesIterator = m_drawables.begin() ;
          drawablesIterator != m_drawables.end() ;
          ++drawablesIterator)
      {
        Drawable* drawable(*drawablesIterator);
        if (drawable->hasChanged()) {
          SDL_Surface* picture = drawable->draw();
          // Draw the picture
          utils::Area render = drawable->getRenderingArea();
          SDL_Rect dstArea;
          dstArea.x = static_cast<short int>(render.getX());
          dstArea.y = static_cast<short int>(render.getY());
          dstArea.w = static_cast<short int>(render.getWidth());
          dstArea.h = static_cast<short int>(render.getHeight());
          drawSurface(picture, nullptr, &dstArea);
        }
      }
    }

    void OgameView::drawSurface(SDL_Surface* surface, SDL_Rect* sourceArea, SDL_Rect* destinationArea) {
      if (surface != nullptr) {
        SDL_BlitSurface(surface, sourceArea, m_screen, destinationArea);
      }
    }

  }
}
