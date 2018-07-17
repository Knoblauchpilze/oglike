#ifndef STATE_LABEL_CONTAINER_H
#define STATE_LABEL_CONTAINER_H

#include <memory>
#include <vector>
#include <SDL/SDL.h>
#include "ActionProviderStateContainer.h"
#include "ColoredFont.h"

namespace ogame {
  namespace gui {

    class StateLabelContainer: public ActionProviderStateContainer
    {
      public:

        StateLabelContainer(const std::string& name,
                            const std::string& text,
                            const player::View& view,
                            player::DataModel* model,
                            view::ColoredFontShPtr font,
                            view::ColoredFontShPtr highlightFont,
                            const StateContainer::StateAssociation& colors = StateContainer::StateAssociation(),
                            const StateContainer::FailPolicy& policy = StateContainer::FailPolicy::Aggressive);

        virtual ~StateLabelContainer();

        const std::string getText() const noexcept;

        void setText(const std::string& text);

      protected:

        SDL_Surface* createContentPrivate() override;

        void clearContentPrivate(SDL_Surface* render) override;

        void onStateModified() override;

      private:

        void clearText();

        // We assume that the font is loaded before entering this method.
        void createText();

        SDL_Surface* createTextFromFont(const std::string& text, view::ColoredFontShPtr font);

      private:

        bool m_textChanged;
        std::string m_text;

        bool m_fontChanged;
        view::ColoredFontShPtr m_font;

        bool m_hFontChanged;
        view::ColoredFontShPtr m_hFont;

        bool m_highlightChanged;
        SDL_Surface* m_textSurface;

    };

    using StateLabelContainerShPtr = std::shared_ptr<StateLabelContainer>;
  }
}

#include "StateLabelContainer.hxx"

#endif // STATE_LABEL_CONTAINER_H
