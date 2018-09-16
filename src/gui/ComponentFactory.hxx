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
                                               const std::string& offPicture,
                                               const view::EventListener::Interaction::Mask& mask)
    {
      return std::make_shared<SwitchPictureContainer>(
        name,
        onPicture,
        offPicture,
        mask
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

  static
        StateLabelContainerShPtr
        createStateLabelPanel();

    inline
    StateLabelContainerShPtr
    ComponentFactory::createStateLabelPanel(const std::string& name,
                                            const std::string& text,
                                            const StateLabelContainer::FontAssociation& fonts,
                                            const LabelContainer::Alignment& alignment,
                                            const StateContainer::FailPolicy& policy)
    {
      return std::make_shared<StateLabelContainer>(
        name,
        text,
        fonts,
        alignment,
        policy
      );
    }

    inline
    ActionProviderLabelStateContainerShPtr
    ComponentFactory::createActionProviderLabelStatePanel(const std::string& name,
                                                          const std::string& text,
                                                          const player::View& view,
                                                          player::GeneralDataModel* model,
                                                          view::ColoredFontShPtr font,
                                                          view::ColoredFontShPtr highlightFont,
                                                          const StateContainer::StateAssociation& colors,
                                                          const StateContainer::FailPolicy& policy)
    {
      return std::make_shared<ActionProviderLabelStateContainer>(
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
                                               view::ColoredFontShPtr font,
                                               const std::vector<std::string>& options,
                                               const ValueSelector::Alignment& alignment)
    {
      return std::make_shared<ValueSelector>(
        name,
        font,
        options,
        alignment
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

    inline
    BackgroundedLabelShPtr
    ComponentFactory::createBackgroundedLabelPanel(const std::string& name,
                                                   view::ColoredFontShPtr font,
                                                   const std::string& picture,
                                                   const std::string& text,
                                                   const SDL_Color& textBackgroundColor,
                                                   const BackgroundedLabel::Alignment& alignment,
                                                   const view::EventListener::Interaction::Mask& mask)
    {
      return std::make_shared<BackgroundedLabel>(
        name,
        font,
        picture,
        text,
        textBackgroundColor,
        alignment,
        mask
      );
    }

    inline
    PhotoGalleryShPtr
    ComponentFactory::createPhotoGalleryPanel(const std::string& name,
                                              const unsigned& picturesCount,
                                              const view::LinearLayout::Direction& alignment)
    {
      return std::make_shared<PhotoGallery>(
        name,
        picturesCount,
        alignment
      );
    }

  }
}

#endif // COMPONENTFACTORY_XX
