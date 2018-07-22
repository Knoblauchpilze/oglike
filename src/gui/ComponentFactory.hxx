#ifndef COMPONENTFACTORY_HXX
#define COMPONENTFACTORY_HXX

#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    inline
    PictureContainerShPtr
    ComponentFactory::createPicturePanel(const std::string& name,
                                         const std::string& file,
                                         const view::EventListener::Interaction::Mask& mask)
    {
      return std::make_shared<PictureContainer>(
        name,
        file,
        mask
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
    ConditionalPictureContainerShPtr
    ComponentFactory::createConditionalPicturePanel(const std::string& name,
                                                    const std::string& file,
                                                    const view::EventListener::Interaction::Mask& mask,
                                                    const bool active)
    {
      return std::make_shared<ConditionalPictureContainer>(
        name,
        file,
        mask,
        active
      );
    }

    inline
    LabelContainerShPtr
    ComponentFactory::createLabelPanel(const std::string& name,
                                       const std::string& text,
                                       view::ColoredFontShPtr font,
                                       const LabelContainer::Alignment& alignment,
                                       const SDL_Color& bgColor,
                                       const bool transparent)
    {
      return std::make_shared<LabelContainer>(
        name,
        text,
        font,
        alignment,
        bgColor,
        transparent
      );
    }

    inline
    StateLabelContainerShPtr
    ComponentFactory::createStateLabelPanel(const std::string& name,
                                            const std::string& text,
                                            const player::View& view,
                                            player::GeneralDataModel* model,
                                            view::ColoredFontShPtr font,
                                            view::ColoredFontShPtr highlightFont,
                                            const StateContainer::StateAssociation& colors,
                                            const StateContainer::FailPolicy& policy)
    {
      return std::make_shared<StateLabelContainer>(
        name,
        text,
        view,
        model,
        font,
        (highlightFont == nullptr ? font : highlightFont),
        colors,
        policy
      );
    }

    inline
    ValueSelectorShPtr
    ComponentFactory::createValueSelectorPanel(const std::string& name,
                                               player::GeneralDataModel* model,
                                               view::ColoredFontShPtr font,
                                               const std::vector<std::string>& options)
    {
      return std::make_shared<ValueSelector>(
        name,
        model,
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
                                                 const LabelledPicture::Alignment& alignment,
                                                 const view::EventListener::Interaction::Mask& mask)
    {
      return std::make_shared<LabelledPicture>(
        name,
        font,
        picture,
        text,
        alignment,
        mask
      );
    }

  }
}

#endif // COMPONENTFACTORY_XX
