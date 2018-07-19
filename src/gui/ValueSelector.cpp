
#include "ValueSelector.h"
#include "LinearLayout.h"
#include "GuiException.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    ValueSelector::ValueSelector(const std::string& name,
                                 player::GeneralDataModel* model,
                                 view::ColoredFontShPtr font,
                                 const std::vector<std::string>& options):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::MouseButton,
                             view::EventListener::Sensitivity::Local,
                             std::make_shared<view::LinearLayout>(
                               view::LinearLayout::Direction::Horizontal,
                               0.0f, 0.0f,
                               this
                             )),
      player::GeneralActionListener(model),
      m_selectedOption(0u),
      m_options(options)
    {
      // Assign the background color.
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});

      createView(font);

      buildIndicesTableFromOptions();
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

        notifyGraphicListeners(view::EventListener::Interaction::MouseButtonPressed);
      }
    }

    void ValueSelector::createView(view::ColoredFontShPtr font)
    {
      // Left switch option.
      PictureContainerShPtr left = ComponentFactory::createPicturePanel(
        std::string("left_switch"),
        std::string("data/img/switch_left.bmp"),
        view::EventListener::Interaction::MouseButtonReleased
      );
      // The main label.
      LabelContainerShPtr label = ComponentFactory::createLabelPanel(std::string("current_value"), std::string(""), font);
      // Right switch option.
      PictureContainerShPtr right = ComponentFactory::createPicturePanel(
        std::string("right_switch"),
        std::string("data/img/switch_right.bmp"),
        view::EventListener::Interaction::MouseButtonReleased
      );

      if (left == nullptr ||
          label == nullptr ||
          right == nullptr)
      {
        throw GuiException(std::string("Could not allocate one of the panel needed for selector ") + getName());
      }

      addChild(left);
      addChild(label);
      addChild(right);

      left->addEventListener(this);
      right->addEventListener(this);

      label->setBackgroundColor({255, 255, 255, SDL_ALPHA_OPAQUE});
    }

    void ValueSelector::buildIndicesTableFromOptions() {
      for (unsigned indexOption = 0u ; indexOption < m_options.size() ; ++indexOption) {
        m_indices[m_options[indexOption]] = indexOption;
      }
    }

  }
}
