#ifndef CHARACCEPTOR_H
#define CHARACCEPTOR_H

#include <set>

class CharAcceptor {

    public:
        virtual bool acceptChar(char) = 0;
        virtual ~CharAcceptor() {

        }

    protected:

    private:
};

#endif // CHARACCEPTOR_H
