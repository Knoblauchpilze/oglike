#ifndef BACKGROUNDEDLABEL_H
#define BACKGROUNDEDLABEL_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "ColoredFont.h"
#include "LinearLayout.h"
#include "PictureContainer.h"
#include "LabelContainer.h"

namespace ogame {
  namespace gui {

    class BackgroundedLabel: public view::GraphicContainer
    {
      public:

        // Describe the position of the picture relatively to the label.
        enum class Alignment {
          Left,
          Right,
          Above,
          Below
        };

        BackgroundedLabel(const std::string& name,
                          view::ColoredFontShPtr font,
                          const std::string& picture,
                          const std::string& text = std::string(),
                          const Alignment& alignment = Alignment::Below,
                          const EventListener::Interaction::Mask& mask = EventListener::Interaction::NoInteraction);

        virtual ~BackgroundedLabel();

        void setLabel(const std::string& text);

      private:

        void createView(view::ColoredFontShPtr font, const std::string& picture, const std::string& text);

        view::LinearLayoutShPtr createLayoutFromAlignment(const Alignment& alignment,
                                                          const float& margin = 0.0f,
                                                          const float& componentMargin = 0.0f) const;

        void addComponentFromLayout(PictureContainerShPtr picture, LabelContainerShPtr label);

      private:

        Alignment m_alignment;

    };

    using BackgroundedLabelShPtr = std::shared_ptr<BackgroundedLabel>;
  }
}

#include "BackgroundedLabel.hxx"

#endif // BACKGROUNDEDLABEL_H
