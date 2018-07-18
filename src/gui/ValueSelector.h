#ifndef VALUESELECTOR_H
#define VALUESELECTOR_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "GraphicContainerListener.h"
#include "ColoredFont.h"
#include "DataModelImplementation.h"

namespace ogame {
  namespace gui {

    class ValueSelector: public view::GraphicContainer, public view::GraphicContainerListener, public player::GeneralActionListener
    {
      public:

        ValueSelector(const std::string& name,
                      player::GeneralDataModel* model,
                      view::ColoredFontShPtr font,
                      const std::vector<std::string>& options = std::vector<std::string>());

        virtual ~ValueSelector();

        void setActiveOption(const unsigned& index);

        void onInteractionPerformed(const std::string& origin, const view::EventListener::Interaction::Mask& mask) override;

        void onActionTriggered(const player::GeneralDataModel& model) override;

      private:

        void createView(view::ColoredFontShPtr font);

        void buildIndicesTableFromOptions();

      private:

        unsigned m_selectedOption;
        std::vector<std::string> m_options;
        std::unordered_map<std::string, unsigned> m_indices;

    };

    using ValueSelectorShPtr = std::shared_ptr<ValueSelector>;
  }
}

#include "ValueSelector.hxx"

#endif // VALUESELECTOR_H
