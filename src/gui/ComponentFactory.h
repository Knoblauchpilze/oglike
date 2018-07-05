#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include "PictureContainer.h"
#include "SwitchPictureContainer.h"
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
                         const std::string& font,
                         const SDL_Color& textColor = {255, 255, 255, SDL_ALPHA_OPAQUE},
                         const int& fontSize = 25);

        static
        ValueSelectorShPtr
        createValueSelectorPanel(const std::string& name,
                                 const std::string& font,
                                 const SDL_Color& optionsColor = {255, 255, 255, SDL_ALPHA_OPAQUE},
                                 const std::vector<std::string>& options = std::vector<std::string>(),
                                 const int& fontSize = 25);

    };
  }
}

#include "ComponentFactory.hxx"

#endif // COMPONENTFACTORY_H
