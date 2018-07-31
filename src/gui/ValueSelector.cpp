
#include "ValueSelector.h"
#include "LinearLayout.h"
#include "GridLayout.h"
#include "GuiException.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    ValueSelector::ValueSelector(const std::string& name,
                                 view::ColoredFontShPtr font,
                                 const std::vector<std::string>& options,
                                 const Alignment& alignment):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::MouseButtonReleased,
                             true),
      view::GraphicContainerListener(),
      m_selectedOption(0u),
      m_options(options)
    {
      // Assign the background color.
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});

      createView(font, alignment);
    }

    ValueSelector::~ValueSelector() {
      // Nothing to do here.
    }

    void ValueSelector::setActiveOption(const unsigned& index) {
      lock();

      // Check whether this option is valid.
      if (index >= m_options.size()) {
        unlock();
        throw GuiException(std::string("Cannot set invalid option ") +
          std::to_string(index) +
          " as active, only " +
          std::to_string(m_options.size()) +
          " options available"
        );
      }
      m_selectedOption = index;
      
      LabelContainer* label = getChild<LabelContainer*>(std::string("current_value"));
      if (checkChild(label, std::string("Selector label"))) {
        label->setText(m_options[m_selectedOption]);
      }

      makeDeepDirty();

      unlock();
    }

    void ValueSelector::onInteractionPerformed(const std::string& origin, const view::EventListener::Interaction::Mask& mask) {
      if (mask == view::EventListener::Interaction::MouseButtonReleased) {
        // Notify the new value.
        unsigned optionToSet = 0u;

        // Update the value displayed in this selector.
        if (origin == std::string("left_switch")) {
          lock();
          optionToSet = (m_selectedOption + m_options.size() - 1u) % m_options.size();
          unlock();
          setActiveOption(optionToSet);
        }
        else if (origin == std::string("right_switch")) {
          lock();
          optionToSet = (m_selectedOption + 1u) % m_options.size();
          unlock();
          setActiveOption(optionToSet);
        }
        std::cout << "[VS] Notifying for value " << m_selectedOption << " mask is " << static_cast<int>(mask) << std::endl;
        notifyGraphicListeners(view::EventListener::Interaction::MouseButtonPressed);
      }
    }

    void ValueSelector::createView(view::ColoredFontShPtr font, const Alignment& alignment)
    {
      // Left switch option.
      PictureContainerShPtr inferior = ComponentFactory::createPicturePanel(
        std::string("left_switch"),
        alignment == Alignment::Horizontal ?
          std::string("data/img/switch_left.bmp") :
          std::string("data/img/switch_down.bmp")
        ,
        view::EventListener::Interaction::MouseButtonReleased
      );

      // The main label.
      LabelContainerShPtr label = ComponentFactory::createLabelPanel(
        std::string("current_value"),
        std::string(""),
        font,
        LabelContainer::Alignment::Center,
        SDL_Color{255, 255, 255, SDL_ALPHA_OPAQUE},
        false
      );

      // Right switch option.
      PictureContainerShPtr superior = ComponentFactory::createPicturePanel(
        std::string("right_switch"),
        alignment == Alignment::Horizontal ?
          std::string("data/img/switch_right.bmp") :
          std::string("data/img/switch_up.bmp")
        ,
        view::EventListener::Interaction::MouseButtonReleased
      );

      if (inferior == nullptr ||
          label == nullptr ||
          superior == nullptr)
      {
        throw GuiException(std::string("Could not allocate one of the panel needed for selector ") + getName());
      }

      if (alignment == Alignment::Horizontal) {
        createHorizontalAlignment(inferior, superior, label);
      }
      else {
        createVerticalAlignment(inferior, superior, label, alignment);
      }

      inferior->addEventListener(this);
      superior->addEventListener(this);

    }

    void ValueSelector::createHorizontalAlignment(PictureContainerShPtr inferior,
                                                  PictureContainerShPtr superior,
                                                  LabelContainerShPtr value)
    {
      view:: LinearLayoutShPtr layout = std::make_shared<view::LinearLayout>(
        view::LinearLayout::Direction::Horizontal,
        0.0f, 0.0f,
        this
      );

      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate layout needed for selector ") + getName());
      }

      setLayout(layout);

      addChild(inferior);
      addChild(value);
      addChild(superior);
    }

    void ValueSelector::createVerticalAlignment(PictureContainerShPtr inferior,
                                                PictureContainerShPtr superior,
                                                LabelContainerShPtr value,
                                                const Alignment& alignment)
    {
      view:: GridLayoutShPtr layout = std::make_shared<view::GridLayout>(4u, 2u, 0.0f, this);

      if (layout == nullptr) {
        throw GuiException(std::string("Could not allocate layout needed for selector ") + getName());
      }

      setLayout(layout);

      if (alignment == Alignment::VerticalLeft) {
        addChild(superior, 0u, 0u, 1u, 1u);
        addChild(inferior, 0u, 1u, 1u, 1u);
        addChild(value,    1u, 0u, 3u, 2u);
      }
      else {
        addChild(superior, 3u, 0u, 1u, 1u);
        addChild(inferior, 3u, 1u, 1u, 1u);
        addChild(value,    0u, 0u, 3u, 2u);
      }
    }

  }
}
