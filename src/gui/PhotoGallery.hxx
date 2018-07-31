#ifndef PHOTOGALLERY_HXX
#define PHOTOGALLERY_HXX

#include "PhotoGallery.h"
#include "ComponentFactory.h"

namespace ogame {
  namespace gui {

    inline
    const bool PhotoGallery::removeAndDestroy(const std::string& imageName) {
      std::unordered_map<std::string, int>::const_iterator image = m_indices.find(imageName);
      if (image != m_indices.cend()) {
        const int index = image->second;
        m_pictures.erase(m_pictures.begin() + image->second);
        m_indices.erase(image);
        return (index <= m_picturesCount) && (m_pictures.size() + 1 <= m_picturesCount);
      }
      return false;
    }

    inline
    void PhotoGallery::removeLastAddedChild() {
      // Search for the maximum index child.
      int maxIndex = -1;
      std::string childToRemove;

      for (std::unordered_map<std::string, int>::const_iterator image = m_indices.cbegin() ;
           image != m_indices.cend() ;
           ++image)
      {
        if (image->second > maxIndex) {
          maxIndex = image->second,
          childToRemove = image->first;
        }
      }

      if (maxIndex >= 0) {
        removeAndDestroy(childToRemove);
        removeChild(childToRemove);
      }
    }

    inline
    const std::string PhotoGallery::generateNameFromImage(const std::string& imageName) const {
      unsigned indexImage = 0u;
      const std::string childNamedImage = imageName + std::string("_child_");
      std::string generated = childNamedImage + std::to_string(indexImage);
      std::unordered_map<std::string, int>::const_iterator existing = m_indices.find(generated);
      while (existing != m_indices.cend()) {
        ++indexImage;
        generated = childNamedImage + std::to_string(indexImage);
        existing = m_indices.find(generated);
      }
      return generated;
    }

  }
}

#endif // PHOTOGALLERY_HXX
