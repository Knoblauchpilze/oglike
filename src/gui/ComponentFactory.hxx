#ifndef COMPONENTFACTORY_HXX
#define COMPONENTFACTORY_HXX

#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    inline
    PictureContainerShPtr
    ComponentFactory::createPicturePanel(const std::string& name,
                                         const std::string& file)
    {
      return std::make_shared<PictureContainer>(
        name,
        file
      );
    }

    inline
    SwitchPictureContainerShPtr
    ComponentFactory::createSwitchPicturePanel(const std::string& name,
                                               const std::string& onPicture,
                                               const std::string& offPicture)
    {
      return std::make_shared<SwitchPictureContainer>(
        name,
        onPicture,
        offPicture
      );
    }

    inline
    LabelContainerShPtr
    ComponentFactory::createLabelPanel(const std::string& name,
                      const std::string& text,
                      const std::string& font,
                      const SDL_Color& textColor,
                      const int& fontSize)
    {
      return std::make_shared<LabelContainer>(
        text,
        textColor,
        font,
        name,
        fontSize
      );
    }

    inline
    ValueSelectorShPtr
    ComponentFactory::createValueSelectorPanel(const std::string& name,
                                               const std::string& font,
                                               const SDL_Color& optionsColor,
                                               const std::vector<std::string>& options,
                                               const int& fontSize)
    {
      return std::make_shared<ValueSelector>(
        optionsColor,
        font,
        name,
        options,
        fontSize
      );
    }

  }
}

#endif // COMPONENTFACTORY_XX
