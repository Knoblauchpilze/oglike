#ifndef ELEMENTDESCRIPTIONPANEL_HXX
#define ELEMENTDESCRIPTIONPANEL_HXX

#include "ElementDescriptionPanel.h"
#include "PictureContainer.h"
#include "UpgradeInfo.h"
#include "UpgradeResourceInfo.h"

namespace ogame {
  namespace gui {

    inline
    void ElementDescriptionPanel::setImagePath(const std::string& path) {
      lock();

      PictureContainer* image = getChild<PictureContainer*>(std::string("image_panel"));
      if (checkChild(image, std::string("Element description image panel"))) {
        image->setImagePath(path);
      }

      unlock();
    }

    template <typename Element>
    inline
    void ElementDescriptionPanel::populateInformationFromElement(const Element& element,
                                                                 const core::Planet& planet,
                                                                 const core::Account& account)
    {
      lock();

      // Update each panel using the dedicated handler.
      UpgradeInfo* upgradeInfo = getChild<UpgradeInfo*>(std::string("upgrade_info"));
      if (checkChild(upgradeInfo, std::string("Element description upgrade info"))) {
        upgradeInfo->populateInformationFromElement(element, planet, account);
      }

      UpgradeResourceInfo* neededResources = getChild<UpgradeResourceInfo*>(std::string("need_resources"));
      if (checkChild(neededResources, std::string("Element description upgrade resource info"))) {
        neededResources->populateInformationFromElement(element, planet);
      }

      unlock();
    }

  }
}

#endif // ELEMENTDESCRIPTIONPANEL_HXX