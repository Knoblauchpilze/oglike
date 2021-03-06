#ifndef ACTIONPROVIDERLABELSTATECONTAINER_H
#define ACTIONPROVIDERLABELSTATECONTAINER_H

#include <memory>
#include <vector>
#include <SDL/SDL.h>
#include "ActionProviderStateContainer.h"
#include "ColoredFont.h"

namespace ogame {
  namespace gui {

    class ActionProviderLabelStateContainer: public ActionProviderStateContainer
    {
      public:

        ActionProviderLabelStateContainer(const std::string& name,
                                          const std::string& text,
                                          const player::View& view,
                                          player::GeneralDataModel* model,
                                          view::ColoredFontShPtr font,
                                          view::ColoredFontShPtr highlightFont,
                                          const StateContainer::StateAssociation& colors = StateContainer::StateAssociation(),
                                          const StateContainer::FailPolicy& policy = StateContainer::FailPolicy::Aggressive);

        virtual ~ActionProviderLabelStateContainer();

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

    using ActionProviderLabelStateContainerShPtr = std::shared_ptr<ActionProviderLabelStateContainer>;
  }
}

#include "ActionProviderLabelStateContainer.hxx"

#endif // ACTIONPROVIDERLABELSTATECONTAINER_H
