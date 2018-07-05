
#include "ValueSelector.h"
#include "LinearLayout.h"
#include "GuiException.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    ValueSelector::ValueSelector(const SDL_Color& textColor,
                                 const std::string& font,
                                 const std::string& name,
                                 const std::vector<std::string>& options,
                                 const int& fontSize):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::MouseButton,
                             std::make_shared<view::LinearLayout>(
                               view::LinearLayout::Direction::Horizontal,
                               0.0f, 0.0f,
                               this
                             )),
      m_selectedOption(0u),
      m_options(options)
    {
      // Assign the background color.
      setBackgroundColor({14, 57, 83, SDL_ALPHA_OPAQUE});

      createView(textColor,
                 font,
                 fontSize);

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

    void ValueSelector::createView(const SDL_Color& textColor,
                                   const std::string& font,
                                   const int& fontSize)
    {
      // Left switch option.
      PictureContainerShPtr left = ComponentFactory::createPicturePanel(std::string("left_switch"), std::string("data/img/switch_left.bmp"));
      // The main label.
      LabelContainerShPtr label = ComponentFactory::createLabelPanel(std::string("current_value"), std::string(""), font, textColor, fontSize);
      // Right switch option.
      PictureContainerShPtr right = ComponentFactory::createPicturePanel(std::string("right_switch"), std::string("data/img/switch_right.bmp"));

      if (left == nullptr ||
          label == nullptr ||
          right == nullptr)
      {
        throw GuiException(std::string("Could not allocate one of the panel needed for selector ") + getName());
      }

      addChild(left);
      addChild(label);
      addChild(right);

      label->setBackgroundColor({255, 255, 255, SDL_ALPHA_OPAQUE});
    }

    void ValueSelector::buildIndicesTableFromOptions() {
      for (unsigned indexOption = 0u ; indexOption < m_options.size() ; ++indexOption) {
        m_indices[m_options[indexOption]] = indexOption;
      }
    }

  }
}
