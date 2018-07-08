#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include "PictureContainer.h"
#include "SwitchPictureContainer.h"
#include "ColoredFont.h"
#include "LabelContainer.h"
#include "ValueSelector.h"

namespace ogame {
  namespace gui {

    class ComponentFactory
    {
      public:

        ComponentFactory() = default;

        virtual ~ComponentFactory() = default;

        static
        PictureContainerShPtr
        createPicturePanel(const std::string& name,
                           const std::string& file);

        static
        SwitchPictureContainerShPtr
        createSwitchPicturePanel(const std::string& name,
                                 const std::string& onPicture,
                                 const std::string& offPicture);

        static
        LabelContainerShPtr
        createLabelPanel(const std::string& name,
                         const std::string& text,
                         view::ColoredFontShPtr font,
                         view::ColoredFontShPtr highlightFont = nullptr);

        static
        ValueSelectorShPtr
        createValueSelectorPanel(const std::string& name,
                                 view::ColoredFontShPtr font,
                                 const std::vector<std::string>& options = std::vector<std::string>());

    };
  }
}

#include "ComponentFactory.hxx"

#endif // COMPONENTFACTORY_H
