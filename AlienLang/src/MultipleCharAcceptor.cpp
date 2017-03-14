#include "MultipleCharAcceptor.h"

MultipleCharAcceptor::MultipleCharAcceptor(std::set<char>& allowedChars) {
    this->allowedChars = allowedChars;
}

bool
MultipleCharAcceptor::acceptChar(char c) {
    return (this->allowedChars.find(c) != this->allowedChars.end());
}

MultipleCharAcceptor::~MultipleCharAcceptor() {

}
