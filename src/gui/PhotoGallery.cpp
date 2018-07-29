
#include "PhotoGallery.h"
#include "GuiException.h"
#include "ComponentFactory.h"
#include "FontFactory.h"

namespace ogame {
  namespace gui {

    PhotoGallery::PhotoGallery(const std::string& name,
                               const unsigned& picturesCount,
                               const view::LinearLayout::Direction& direction):
      view::GraphicContainer(name,
                             view::utils::Area(),
                             view::EventListener::Interaction::NoInteraction,
                             true,
                             view::EventListener::Sensitivity::Local,
                             std::make_shared<view::LinearLayout>(
                               direction,
                               0.0f,
                               0.0f
                             )),
      m_picturesCount(picturesCount),
      m_indices(),
      m_pictures(),
      m_etc(nullptr)
    {
      createView();
    }

    PhotoGallery::~PhotoGallery() {}

    void PhotoGallery::addImage(const std::string& image) {
      lock();

      const std::string& generatedImageName = generateNameFromImage(image);

      const bool exist = removeAndDestroy(generatedImageName);
      if (exist) {
        removeChild(generatedImageName);
      }

      PictureContainerShPtr picture = loadPicture(image, generatedImageName);
      if (picture == nullptr) {
        unlock();
        throw GuiException(std::string("Could not load picture ") + image + " in container " + getName());
      }

      const int imageIndex = m_pictures.size();
      m_indices[generatedImageName] = imageIndex;
      m_pictures.push_back(picture);

      if (imageIndex < m_picturesCount) {
        addChild(picture);
        makeDeepDirty();
      }
      else if (imageIndex == m_picturesCount) {
        removeLastAddedChild();
        addChild(m_etc);
        makeDeepDirty();
      }

      unlock();
    }

    void PhotoGallery::removeImage(const std::string& image) {
      lock();

      const std::string& generatedImageName = generateNameFromImage(image);

      const bool exist = removeAndDestroy(generatedImageName);
      if (exist) {
        removeChild(generatedImageName);
        makeDeepDirty();
      }

      unlock();
    }

    void PhotoGallery::clear() {
      lock();
      for (std::vector<PictureContainerShPtr>::const_iterator picture = m_pictures.cbegin() ;
           picture != m_pictures.cend() ;
           ++picture)
      {
        removeChild(*picture);
      }
      m_indices.clear();
      m_pictures.clear();

      removeChild(m_etc);

      makeDeepDirty();
      unlock();
    }

    void PhotoGallery::createView() {
      m_etc = ComponentFactory::createLabelPanel(
        std::string("etc_label"),
        std::string("..."),
        view::FontFactory::getInstance().createColoredFont(
          std::string("data/fonts/tahomabd.ttf"),
          255, 255, 255, SDL_ALPHA_OPAQUE,
          8
        )
      );

      if (m_etc == nullptr) {
        throw GuiException(std::string("Could not allocate memory to create photo gallery ") + getName());
      }
    }

    PictureContainerShPtr PhotoGallery::loadPicture(const std::string& image, const std::string& generatedName) const {
      return ComponentFactory::createPicturePanel(
        generatedName,
        image
      );
    }

  }
}
