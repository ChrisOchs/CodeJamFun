#include <algorithm>
#include <iostream>
#include <vector>

#include "ReverseWords.h"

void reverseWords(std::string& str) {

    std::string delimiter = " ";

    std::vector<std::string> result;

    splitString(str, delimiter, result);

    std::reverse(result.begin(), result.end());

    for(std::vector<std::string>::iterator it = result.begin(); it != result.end(); it++) {
        std::cout<<*it;

        if(it != result.end()) {
            std::cout<<" ";
        }
    }
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

    if(result.size() > 0) {
        result.push_back(input);
    }
}
