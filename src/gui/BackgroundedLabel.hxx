#ifndef BACKGROUNDEDLABEL_HXX
#define BACKGROUNDEDLABEL_HXX

#include "BackgroundedLabel.h"
#include "GuiException.h"

namespace ogame {
  namespace gui {

    inline
    void BackgroundedLabel::setLabel(const std::string& text) {
      lock();

      LabelContainer* label = getChild<LabelContainer*>(std::string("label_panel"));
      if (checkChild(label, std::string("Label panel"))) {
        label->setText(text);
      }

      makeDeepDirty();
      unlock();
    }

    inline
    view::LinearLayoutShPtr BackgroundedLabel::createLayoutFromAlignment(const Alignment& alignment,
                                                                         const float& margin,
                                                                         const float& componentMargin) const
    {
      view::LinearLayoutShPtr layout = nullptr;
      view::LinearLayout::Direction dir = view::LinearLayout::Direction::Horizontal;
      if (alignment == Alignment::Above || alignment == Alignment::Below) {
        dir = view::LinearLayout::Direction::Vertical;
      }

      layout = std::make_shared<view::LinearLayout>(dir, margin, componentMargin);
      if (layout == nullptr) {
        throw GuiException(std::string("Could not create layout for backgrounded picture ") + getName());
      }

      return layout;
    }

    inline
    void BackgroundedLabel::addComponentFromLayout(PictureContainerShPtr picture, LabelContainerShPtr label) {
      std::vector<view::GraphicContainerShPtr> components;

      if (m_alignment == Alignment::Above || m_alignment == Alignment::Left) {
        components.push_back(picture);
        components.push_back(label);
      }
      else {
        components.push_back(label);
        components.push_back(picture);
      }

      for (unsigned index = 0u ; index < components.size() ; ++index) {
        addChild(components[index]);
      }
    }

  }
}

#endif // BACKGROUNDEDLABEL_HXX
