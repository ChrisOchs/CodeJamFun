#ifndef SIMPLECHARACCEPTOR_H
#define SIMPLECHARACCEPTOR_H

#include "CharAcceptor.h"

class SimpleCharAcceptor: public CharAcceptor
{
    public:
        SimpleCharAcceptor(char);

        bool acceptChar(char);

        virtual ~SimpleCharAcceptor();

    protected:

    private:
        char c;
};

#endif // SIMPLECHARACCEPTOR_H
