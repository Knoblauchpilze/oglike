
#include "LabelledPicture.h"
#include "ComponentFactory.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    LabelledPicture::LabelledPicture(const std::string& name,
                                     view::ColoredFontShPtr font,
                                     const std::string& picture,
                                     const Alignment& alignment):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction),
      m_alignment(alignment)
    {
      createView(font, picture);
    }

    LabelledPicture::~LabelledPicture() {}

    void LabelledPicture::createView(view::ColoredFontShPtr font, const std::string& picture) {
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
        std::string(""),
        font
      );

      if (image == nullptr || label == nullptr) {
        throw GuiException(std::string("Could not create one or more component for container ") + getName());
      }

      addComponentFromLayout(image, label);
    }
  }
}
