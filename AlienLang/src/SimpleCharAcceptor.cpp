#include "SimpleCharAcceptor.h"

SimpleCharAcceptor::SimpleCharAcceptor(char c) {
    this->c = c;
}

bool
SimpleCharAcceptor::acceptChar(char c) {
    return this->c == c;
}

SimpleCharAcceptor::~SimpleCharAcceptor() {

}
