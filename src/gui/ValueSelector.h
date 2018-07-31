#ifndef VALUESELECTOR_H
#define VALUESELECTOR_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "GraphicContainerListener.h"
#include "ColoredFont.h"
#include "PictureContainer.h"
#include "LabelContainer.h"

namespace ogame {
  namespace gui {

    class ValueSelector: public view::GraphicContainer, public view::GraphicContainerListener
    {
      public:

        // Specify the position of the selector buttons respectively to the value.
        enum class Alignment {
          VerticalLeft,
          VerticalRight,
          Horizontal
        };

        ValueSelector(const std::string& name,
                      view::ColoredFontShPtr font,
                      const std::vector<std::string>& options = std::vector<std::string>(),
                      const Alignment& alignment = Alignment::Horizontal);

        virtual ~ValueSelector();

        void setActiveOption(const unsigned& index);

        const unsigned getActiveOption();

        void onInteractionPerformed(const std::string& origin, const view::EventListener::Interaction::Mask& mask) override;

      protected:

        void onMouseButtonReleasedEventPrivate(const SDL_MouseButtonEvent& mouseButtonEvent) override;

      private:

        void createView(view::ColoredFontShPtr font, const Alignment& alignment);

        void createHorizontalAlignment(PictureContainerShPtr inferior,
                                       PictureContainerShPtr superior,
                                       LabelContainerShPtr value);

        void createVerticalAlignment(PictureContainerShPtr inferior,
                                     PictureContainerShPtr superior,
                                     LabelContainerShPtr value,
                                     const Alignment& alignment);

      private:

        unsigned m_selectedOption;
        std::vector<std::string> m_options;

    };

    using ValueSelectorShPtr = std::shared_ptr<ValueSelector>;
  }
}

#include "ValueSelector.hxx"

#endif // VALUESELECTOR_H
