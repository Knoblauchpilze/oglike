#ifndef LABELLEDPICTURE_H
#define LABELLEDPICTURE_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "ColoredFont.h"
#include "Planet.h"
#include "LinearLayout.h"
#include "PictureContainer.h"
#include "LabelContainer.h"

namespace ogame {
  namespace gui {

    class LabelledPicture: public view::GraphicContainer
    {
      public:

        // Describe the position of the picture relatively to the label.
        enum class Alignment {
          Left,
          Right,
          Above,
          Below
        };

        LabelledPicture(const std::string& name,
                        view::ColoredFontShPtr font,
                        const std::string& picture,
                        const Alignment& alignment = Alignment::Below);

        virtual ~LabelledPicture();

        void setLabel(const std::string& text);

      private:

        void createView(view::ColoredFontShPtr font, const std::string& picture);

        view::LinearLayoutShPtr createLayoutFromAlignment(const Alignment& alignment,
                                                          const float& margin = 0.0f,
                                                          const float& componentMargin = 0.0f) const;

        void addComponentFromLayout(PictureContainerShPtr picture, LabelContainerShPtr label);

      private:

        Alignment m_alignment;

    };

    using LabelledPictureShPtr = std::shared_ptr<LabelledPicture>;
  }
}

#include "LabelledPicture.hxx"

#endif // LABELLEDPICTURE_H
