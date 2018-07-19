#ifndef GRAPHIC_CONTAINER_H
#define GRAPHIC_CONTAINER_H

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include "Drawable.h"
#include "Area.h"
#include "Layout.h"
#include "EventListener.h"
#include "GraphicContainerListener.h"

namespace ogame {
  namespace view {

    class Layout;

    class GraphicContainer: public Drawable, public EventListener
    {
      public:

        GraphicContainer(const std::string& name,
                         const utils::Area& area,
                         const EventListener::Interaction::Mask& mask = EventListener::Interaction::NoInteraction,
                         const EventListener::Sensitivity& sensitivity = EventListener::Sensitivity::Local,
                         std::shared_ptr<Layout> layout = nullptr,
                         GraphicContainer* parent = nullptr);

        virtual ~GraphicContainer();

        const std::string&
        getName() const noexcept;

        virtual void addChild(std::shared_ptr<GraphicContainer> child);

        virtual void addChild(std::shared_ptr<GraphicContainer> child,
                              const unsigned& x,
                              const unsigned& y,
                              const unsigned& w,
                              const unsigned& h);

        virtual void removeChild(std::shared_ptr<GraphicContainer> child);

        const unsigned getChildCount() const noexcept;

        void addEventListener(GraphicContainerListener* listener);

        void removeEventListener(GraphicContainerListener* listener);

        utils::Area getRenderingArea() override;

        void setRenderingArea(const utils::Area& area) override;

        SDL_Surface* draw() override;

        void setLayout(std::shared_ptr<Layout> layout);

        void setBackgroundColor(const SDL_Color& color);

        void onKeyPressedEvent(const SDL_KeyboardEvent& keyEvent) override;

        void onKeyReleasedEvent(const SDL_KeyboardEvent& keyEvent) override;

        void onMouseMotionEvent(const SDL_MouseMotionEvent& mouseMotionEvent) override;

        void onMouseButtonPressedEvent(const SDL_MouseButtonEvent& mouseButtonEvent) override;

        void onMouseButtonReleasedEvent(const SDL_MouseButtonEvent& mouseButtonEvent) override;

        void onMouseWheelEvent(bool upWheel) override;

      protected:

        template <typename ContainerPtr>
        inline
        ContainerPtr getChild(const std::string& name) const;

        template <typename Type>
        bool checkChild(const Type* child, const std::string& name) const noexcept;

        template <typename LayoutPtr>
        inline
        LayoutPtr getLayout() const;

        template <typename Type>
        bool checkLayout(const Type* layout, const std::string& type) const noexcept;

        // We assume that the object is locked before entering this method.
        void makeDirty();

        // We assume that the object is locked before entering this method.
        void makeDeepDirty();

        void setParent(GraphicContainer* parent);

        const GraphicContainer* getParent() const noexcept;

        bool hasChanged() const noexcept override;

        virtual bool hasInternallyChanged() const noexcept;

        const utils::Area& getRenderingAreaPrivate() const noexcept;

        const bool isInside(const float& x, const float& y);

        const bool isInside(const utils::Vector2f& point);

        virtual void onKeyPressedEventPrivate(const SDL_KeyboardEvent& keyEvent);

        virtual void onKeyReleasedEventPrivate(const SDL_KeyboardEvent& keyEvent);

        virtual void onMouseMotionEventPrivate(const SDL_MouseMotionEvent& mouseMotionEvent);

        virtual void onMouseButtonPressedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent);

        virtual void onMouseButtonReleasedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent);

        virtual void onMouseWheelEventPrivate(bool upWheel);

        virtual SDL_Surface* createContentPrivate();

        virtual void clearContentPrivate(SDL_Surface* render);

        void notifyGraphicListeners(const view::EventListener::Interaction::Mask& interaction);

      private:

        bool childrenChanged() const noexcept;

        void createContent();

        void destroyContent();

        void drawChild(std::shared_ptr<GraphicContainer> child);

        const utils::Vector2f convertCoordinates(const utils::Vector2f& point) noexcept;

      private:

        std::string m_name;
        utils::Area m_area;
        GraphicContainer* m_parent;
        std::shared_ptr<Layout> m_layout;
        bool m_dirty;
        bool m_deepDirty;
        std::unordered_map<std::string, std::shared_ptr<GraphicContainer>> m_children;
        std::unordered_set<GraphicContainerListener*> m_listeners;
        SDL_Surface* m_panel;
        SDL_Color m_color;

    };

    using GraphicContainerShPtr = std::shared_ptr<GraphicContainer>;
  }
}

#include "GraphicContainer.hxx"

#endif // GRAPHIC_CONTAINER_H
