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
                                       view::ColoredFontShPtr font)
    {
      return std::make_shared<LabelContainer>(
        name,
        text,
        font
      );
    }

    inline
    StateLabelContainerShPtr
    ComponentFactory::createStateLabelPanel(const std::string& name,
                                            const std::string& text,
                                            view::ColoredFontShPtr font,
                                            view::ColoredFontShPtr highlightFont,
                                            const StateContainer::StateAssociation& colors,
                                            const StateContainer::FailPolicy& policy)
    {
      return std::make_shared<StateLabelContainer>(
        name,
        text,
        font,
        (highlightFont == nullptr ? font : highlightFont),
        colors,
        policy
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

    inline
    LabelledPictureShPtr
    ComponentFactory::createLabelledPicturePanel(const std::string& name,
                                                 view::ColoredFontShPtr font,
                                                 const std::string& picture,
                                                 const std::string& text,
                                                 const LabelledPicture::Alignment& alignment)
    {
      return std::make_shared<LabelledPicture>(
        name,
        font,
        picture,
        text,
        alignment
      );
    }

  }
}

#endif // COMPONENTFACTORY_XX
