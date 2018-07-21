#ifndef RESEARCH_H
#define RESEARCH_H

#include <string>

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

  }
}

#include "Research.hxx"

#endif // RESEARCH_H
