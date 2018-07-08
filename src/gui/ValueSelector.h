#ifndef VALUESELECTOR_H
#define VALUESELECTOR_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "GraphicContainer.h"
#include "Font.h"

namespace ogame {
  namespace gui {

    class ValueSelector: public view::GraphicContainer
    {
      public:

        ValueSelector(const std::string& name,
                      view::FontShPtr font,
                      const std::vector<std::string>& options = std::vector<std::string>());

        virtual ~ValueSelector();

        void setActiveOption(const unsigned& index);

      private:

        void createView(view::FontShPtr font);

        void buildIndicesTableFromOptions();

      private:

        unsigned m_selectedOption;
        std::vector<std::string> m_options;
        std::unordered_map<std::string, unsigned> m_indices;

    };

    using ValueSelectorShPtr = std::shared_ptr<ValueSelector>;
  }
}

#endif // VALUESELECTOR_H
