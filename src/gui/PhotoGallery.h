#ifndef PHOTOGALLERY_H
#define PHOTOGALLERY_H

#include <memory>
#include <string>
#include <SDL/SDL.h>
#include "LinearLayout.h"
#include "GraphicContainer.h"
#include "PictureContainer.h"
#include "LabelContainer.h"

namespace ogame {
  namespace gui {

    class PhotoGallery: public view::GraphicContainer
    {
      public:

        PhotoGallery(const std::string& name,
                     const unsigned& picturesCount,
                     const view::LinearLayout::Direction& direction = view::LinearLayout::Direction::Horizontal);

        virtual ~PhotoGallery();

        void addImage(const std::string& image);

        void removeImage(const std::string& image);

        void clear();

      private:

        void createView();

        PictureContainerShPtr loadPicture(const std::string& image, const std::string& generatedName) const;

        const bool removeAndDestroy(const std::string& imageName);

        void removeLastAddedChild();

        const std::string generateNameFromImage(const std::string& imageName) const;

      private:

        unsigned m_picturesCount;
        std::unordered_map<std::string, int> m_indices;
        std::vector<PictureContainerShPtr> m_pictures;

        LabelContainerShPtr m_etc;

    };

    using PhotoGalleryShPtr = std::shared_ptr<PhotoGallery>;
  }
}

#include "PhotoGallery.hxx"

#endif // PHOTOGALLERY_H
