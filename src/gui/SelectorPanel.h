#ifndef SELECTORPANEL_H
#define SELECTORPANEL_H

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "GraphicContainer.h"

namespace ogame {
  namespace gui {

    class SelectorPanel: public view::GraphicContainer
    {
      public:

        SelectorPanel(const std::string& name,
                      const view::EventListener::Interaction::Mask& mask = view::EventListener::Interaction::NoInteraction,
                      const bool transparent = false);

        virtual ~SelectorPanel();

        void addChild(std::shared_ptr<GraphicContainer> child) override;

        void removeChild(std::shared_ptr<GraphicContainer> child) override;

        void setActiveChild(const std::string& name);

        void setActiveChild(const int& index);

        const std::string getActiveChild();

      protected:

        template <typename ContainerPtr>
        ContainerPtr getChildFromCompleteList(const std::string& name) const;

      private:

          // We assume that this index is valid based on the number of children in the 'm_availableChildren'.
          void activateChild(const int& index);

      private:

      int m_activeChild;
      std::unordered_map<std::string, int> m_indices;
      std::vector<view::GraphicContainerShPtr> m_availableChildren;

    };

    using SelectorPanelShPtr = std::shared_ptr<SelectorPanel>;
  }
}

#include "SelectorPanel.hxx"

#endif // SELECTORPANEL_H
