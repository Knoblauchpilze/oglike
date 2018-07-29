#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include "PictureContainer.h"
#include "SwitchPictureContainer.h"
#include "ColoredFont.h"
#include "LabelContainer.h"
#include "StateLabelContainer.h"
#include "ValueSelector.h"
#include "LabelledPicture.h"
#include "ConditionalPictureContainer.h"
#include "PhotoGallery.h"

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
                           const std::string& file,
                           const view::EventListener::Interaction::Mask& mask = view::EventListener::Interaction::NoInteraction);

        static
        SwitchPictureContainerShPtr
        createSwitchPicturePanel(const std::string& name,
                                 const std::string& onPicture,
                                 const std::string& offPicture,
                                 const view::EventListener::Interaction::Mask& mask = view::EventListener::Interaction::NoInteraction);

        static
        ConditionalPictureContainerShPtr
        createConditionalPicturePanel(const std::string& name,
                                      const std::string& file,
                                      const view::EventListener::Interaction::Mask& mask = view::EventListener::Interaction::NoInteraction,
                                      const bool active = true);

        static
        LabelContainerShPtr
        createLabelPanel(const std::string& name,
                         const std::string& text,
                         view::ColoredFontShPtr font,
                         const LabelContainer::Alignment& alignment = LabelContainer::Alignment::Center,
                         const SDL_Color& bgColor = SDL_Color{14, 57, 83, SDL_ALPHA_OPAQUE},
                         const bool transparent = true);

        static
        StateLabelContainerShPtr
        createStateLabelPanel(const std::string& name,
                              const std::string& text,
                              const player::View& view,
                              player::GeneralDataModel* model,
                              view::ColoredFontShPtr font,
                              view::ColoredFontShPtr highlightFont = nullptr,
                              const StateContainer::StateAssociation& colors = StateContainer::StateAssociation(),
                              const StateContainer::FailPolicy& policy = StateContainer::FailPolicy::Aggressive);

        static
        ValueSelectorShPtr
        createValueSelectorPanel(const std::string& name,
                                 player::GeneralDataModel* model,
                                 view::ColoredFontShPtr font,
                                 const std::vector<std::string>& options = std::vector<std::string>());

        static
        LabelledPictureShPtr
        createLabelledPicturePanel(const std::string& name,
                                   view::ColoredFontShPtr font,
                                   const std::string& picture,
                                   const std::string& text = std::string(),
                                   const LabelledPicture::Alignment& alignment = LabelledPicture::Alignment::Below,
                                   const view::EventListener::Interaction::Mask& mask = view::EventListener::Interaction::NoInteraction);

        static
        PhotoGalleryShPtr
        createPhotoGalleryPanel(const std::string& name,
                                const unsigned& picturesCount,
                                const view::LinearLayout::Direction& alignment = view::LinearLayout::Direction::Horizontal);

    };
  }
}

#include "ComponentFactory.hxx"

#endif // COMPONENTFACTORY_H
