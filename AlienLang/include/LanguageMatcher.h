#ifndef LANGUAGEMATCHER_H
#define LANGUAGEMATCHER_H

#include <string>
#include <vector>

#include "CharAcceptor.h"

class LanguageMatcher {

    public:
        LanguageMatcher(std::string&);

        bool accept(std::string&);

        virtual ~LanguageMatcher();

    protected:

    private:
        std::vector<CharAcceptor*>* acceptors;


};

#endif // LANGUAGEMATCHER_H
