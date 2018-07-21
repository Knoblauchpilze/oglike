#ifndef RESEARCH_H
#define RESEARCH_H

#include <string>
#include <memory>

namespace ogame {
  namespace core {

    class Research
    {
      public:

        Research(const std::string& name);

        virtual ~Research();

        const std::string& getName() const;

      protected:

      private:

        std::string m_name;
    };

    using ResearchShPtr = std::shared_ptr<Research>;

  }
}

#include "Research.hxx"

#endif // RESEARCH_H
