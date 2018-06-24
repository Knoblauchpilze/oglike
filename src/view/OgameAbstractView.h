#ifndef OGAMEABSTRACTVIEW_H
#define OGAMEABSTRACTVIEW_H

#include <memory>
#include <vector>
#include <SDL/SDL.h>
#include "EventListener.h"
#include "Drawable.h"

namespace ogame {
  namespace view {

    class OgameAbstractView
    {
      public:

        OgameAbstractView(const std::string& title, const std::string& icon, const unsigned& width, const unsigned& height);
        
        virtual ~OgameAbstractView();

        void addListener(EventListener* listener);

        void addDrawable(Drawable* drawable);
      
        virtual void run();

      protected:

        const int& getWidth() const noexcept;

        const int& getHeight() const noexcept;

      private:

        void createWindow(const unsigned& width, const unsigned& height);

        void performRendering();

        void events();

        void processSingleEvent(const SDL_Event& event);

        void processExitEvent(const SDL_Event& event);

        void processKeyPressedEvent(const SDL_Event& event);

        void processKeyReleasedEvent(const SDL_Event& event);

        void processMouseMotionEvent(const SDL_Event& event);

        void processMouseButtonPressedEvent(const SDL_Event& event);

        void processMouseButtonReleasedEvent(const SDL_Event& event);

        void processMouseWheelEvent(const SDL_Event& event);

        void render();

        void renderDrawables();

        void drawSurface(SDL_Surface* surface, SDL_Rect* sourceArea, SDL_Rect* destinationArea);

      private:

        std::string m_title;
        std::string m_icon;
        double m_framerate;
        double m_frameDuration;
        SDL_Surface* m_screen;
        bool m_processing;
        std::vector<EventListener*> m_listeners;
        std::vector<Drawable*> m_drawables;

    };

    using OgameAbstractViewShPtr = std::shared_ptr<OgameAbstractView>;
  }
}

#include "OgameAbstractView.hxx"

#endif // OGAMEABSTRACTVIEW_H
