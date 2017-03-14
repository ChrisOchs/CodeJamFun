#include <iostream>

#include "LanguageMatcher.h"

// This could be done in a few lines with RegEx but it was fun to 
// create my own extremely simple RegEx-like pattern matcher
int main() {

    std::vector<std::string> testStrs;

    testStrs.push_back("abc");
    testStrs.push_back("bca");
    testStrs.push_back("dac");
    testStrs.push_back("dbc");
    testStrs.push_back("cba");

    std::vector<std::string> patterns;

    patterns.push_back("(ab)(bc)(ca)");
    patterns.push_back("abc");
    patterns.push_back("(abc)(abc)(abc)");
    patterns.push_back("(zyx)bc");

    for(std::vector<std::string>::iterator iter = patterns.begin(); iter != patterns.end(); iter++) {
        LanguageMatcher matcher(*iter);

        int matched = 0;

        for(std::vector<std::string>::iterator strIter = testStrs.begin(); strIter != testStrs.end(); strIter++) {
            if(matcher.accept(*strIter)) {
                matched++;
            }
        }

        std::cout<<*iter<<": "<<matched<<std::endl;
    }

    return 0;
}
