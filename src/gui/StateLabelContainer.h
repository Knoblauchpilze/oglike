#ifndef STATE_LABEL_CONTAINER_H
#define STATE_LABEL_CONTAINER_H

#include <memory>
#include <vector>
#include <SDL/SDL.h>
#include "StateContainer.h"
#include "LabelContainer.h"
#include "GraphicContainer.h"
#include "ColoredFont.h"

namespace ogame {
  namespace gui {

    class StateLabelContainer: public view::GraphicContainer
    {
      public:

        using FontAssociation = std::map<StateContainer::State, view::ColoredFontShPtr>;

        StateLabelContainer(const std::string& name,
                            const std::string& text,
                            const FontAssociation& colors = FontAssociation(),
                            const LabelContainer::Alignment& alignment = LabelContainer::Alignment::Center,
                            const StateContainer::FailPolicy& policy = StateContainer::FailPolicy::Aggressive);

        virtual ~StateLabelContainer();

        void setText(const std::string& text);

        void setState(const StateContainer::State& state);

      protected:

        SDL_Surface* createContentPrivate() override;

        void clearContentPrivate(SDL_Surface* render) override;

      private:

        void clearText();

        // We assume that the font is loaded before entering this method.
        void createText();

        SDL_Surface* createTextFromFont(const std::string& text, view::ColoredFontShPtr font);

        SDL_Rect computeBlitPosition(const unsigned& displayWidth, const unsigned& displayHeight) const noexcept;

        view::ColoredFontShPtr getFontFromState() const;

      private:

        StateContainer::State m_state;
        StateContainer::FailPolicy m_policy;
        FontAssociation m_colors;
        LabelContainer::Alignment m_alignment;

        std::string m_text;
        bool m_textChanged;
        bool m_highlightChanged;
        SDL_Surface* m_textSurface;

    };

    using StateLabelContainerShPtr = std::shared_ptr<StateLabelContainer>;
  }
}

#include "StateLabelContainer.hxx"

#endif // STATE_LABEL_CONTAINER_H
