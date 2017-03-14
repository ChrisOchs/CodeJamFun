#include <iostream>
#include <set>
#include <vector>

#include "MultipleCharAcceptor.h"
#include "SimpleCharAcceptor.h"
#include "LanguageMatcher.h"

void splitString(std::string&, std::string&, std::vector<std::string>&);

LanguageMatcher::LanguageMatcher(std::string& format) {

    std::vector<std::string> result;
    std::string delimiter = ")";

    splitString(format, delimiter, result);

    std::vector<CharAcceptor*>* acceptors = new std::vector<CharAcceptor*>;

    for(std::vector<std::string>::iterator iter = result.begin(); iter != result.end(); iter++) {
        std::string str = *iter;

        if(str[0] == '(') {
            std::set<char> allowedChars;

            for(size_t c = 1; c < str.size(); c++) {
                allowedChars.insert(str[c]);
            }

            MultipleCharAcceptor* acceptor = new MultipleCharAcceptor(allowedChars);
            acceptors->push_back(acceptor);

        } else {
            for(size_t c = 0; c < str.size(); c++) {
                SimpleCharAcceptor* acceptor = new SimpleCharAcceptor(str[c]);

                acceptors->push_back(acceptor);
            }
        }
    }

    this->acceptors = acceptors;
}

LanguageMatcher::~LanguageMatcher() {

    for(std::vector<CharAcceptor*>::iterator iter = this->acceptors->begin(); iter != this->acceptors->end(); iter++) {
        delete *iter;
    }

    delete this->acceptors;
}

bool
LanguageMatcher::accept(std::string& str) {
    if(str.size() != this->acceptors->size()) {
        return false;
    }

    for(size_t c = 0; c < str.size(); c++) {
        if( !(*this->acceptors)[c]->acceptChar(str[c])) {
            return false;
        }
    }

    return true;
}

void splitString(std::string& str, std::string& delimiter, std::vector<std::string>& result) {
    result.clear();

    std::string input = str;
    std::string split = delimiter;

    size_t tokenPos = 0;

    while((tokenPos = input.find(split)) != std::string::npos) {
        result.push_back(input.substr(0, tokenPos));

        input.erase(0, tokenPos + split.length());
    }

    if(input.size() > 0) {
        result.push_back(input);
    }
}
