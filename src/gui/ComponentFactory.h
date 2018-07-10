#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include "PictureContainer.h"
#include "SwitchPictureContainer.h"
#include "ColoredFont.h"
#include "LabelContainer.h"
#include "StateLabelContainer.h"
#include "ValueSelector.h"
#include "LabelledPicture.h"

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
                         view::ColoredFontShPtr font);

        static
        StateLabelContainerShPtr
        createStateLabelPanel(const std::string& name,
                              const std::string& text,
                              view::ColoredFontShPtr font,
                              view::ColoredFontShPtr highlightFont = nullptr,
                              const StateContainer::StateAssociation& colors = StateContainer::StateAssociation(),
                              const StateContainer::FailPolicy& policy = StateContainer::FailPolicy::Aggressive);

        static
        ValueSelectorShPtr
        createValueSelectorPanel(const std::string& name,
                                 view::ColoredFontShPtr font,
                                 const std::vector<std::string>& options = std::vector<std::string>());

        static
        LabelledPictureShPtr
        createLabelledPicturePanel(const std::string& name,
                                   view::ColoredFontShPtr font,
                                   const std::string& picture,
                                   const std::string& text = std::string(),
                                   const LabelledPicture::Alignment& alignment = LabelledPicture::Alignment::Below);

    };
  }
}

#include "ComponentFactory.hxx"

#endif // COMPONENTFACTORY_H
