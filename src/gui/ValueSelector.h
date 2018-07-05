#ifndef VALUESELECTOR_H
#define VALUESELECTOR_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "GraphicContainer.h"

namespace ogame {
  namespace gui {

    class ValueSelector: public view::GraphicContainer
    {
      public:

        ValueSelector(const SDL_Color& textColor,
                      const std::string& font,
                      const std::string& name,
                      const std::vector<std::string>& options = std::vector<std::string>(),
                      const int& fontSize = 25);

        virtual ~ValueSelector();

        void setActiveOption(const unsigned& index);

      private:

        void createView(const SDL_Color& textColor,
                        const std::string& font,
                        const int& fontSize);

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
