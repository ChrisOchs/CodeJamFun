#ifndef MULTIPLECHARACCEPTOR_H
#define MULTIPLECHARACCEPTOR_H

#include <set>

#include "CharAcceptor.h"

class MultipleCharAcceptor: public CharAcceptor
{
    public:
        MultipleCharAcceptor(std::set<char>&);

        bool acceptChar(char c);

        virtual ~MultipleCharAcceptor();

    protected:

    private:
        std::set<char> allowedChars;
};

#endif // MULTIPLECHARACCEPTOR_H
