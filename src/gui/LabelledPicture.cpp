
#include "LabelledPicture.h"
#include "ComponentFactory.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    LabelledPicture::LabelledPicture(const std::string& name,
                                     view::ColoredFontShPtr font,
                                     const std::string& picture,
                                     const std::string& text,
                                     const Alignment& alignment,
                                     const EventListener::Interaction::Mask& mask):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             mask),
      m_alignment(alignment)
    {
      createView(font, picture, text);
    }

    LabelledPicture::~LabelledPicture() {}

    void LabelledPicture::createView(view::ColoredFontShPtr font, const std::string& picture, const std::string& text) {
      // Create the layout based on the alignment.
      view::LinearLayoutShPtr layout = createLayoutFromAlignment(m_alignment);
      setLayout(layout);

      // Create each container.
      PictureContainerShPtr image = ComponentFactory::createPicturePanel(
        std::string("picture_panel"),
        picture
      );

      LabelContainerShPtr label = ComponentFactory::createLabelPanel(
        std::string("label_panel"),
        text,
        font
      );

      if (image == nullptr || label == nullptr) {
        throw GuiException(std::string("Could not create one or more component for container ") + getName());
      }

      addComponentFromLayout(image, label);
    }
  }
}
