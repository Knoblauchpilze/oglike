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
                                       view::ColoredFontShPtr font,
                                       view::ColoredFontShPtr highlightFont)
    {
      return std::make_shared<LabelContainer>(
        name,
        text,
        font,
        (highlightFont == nullptr ? font : highlightFont)
      );
    }

    inline
    ValueSelectorShPtr
    ComponentFactory::createValueSelectorPanel(const std::string& name,
                                               view::ColoredFontShPtr font,
                                               const std::vector<std::string>& options)
    {
      return std::make_shared<ValueSelector>(
        name,
        font,
        options
      );
    }

  }
}

#endif // COMPONENTFACTORY_XX
