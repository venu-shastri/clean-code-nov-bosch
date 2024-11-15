//============================================================================
// Name        : cleancode.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <sstream>
#include <cassert>

using namespace std;

function<bool(const string&)> startswithPredicateGenerator(char letter){

    function<bool(const straing&)> startsWith= [letter](const string& item)->bool { 
                 for (char ch : item) {
                    if (ch == letter) {
                        return true;
                    }
                }
            return false;
    };
}

std::vector<std::string> findStrings(const std::vector<std::string>& strings,
		const std::function<bool(const std::string&)>& condition)
{
    std::vector<std::string> result;
    for (const std::string& str : strings) {
        if (condition(str)) {
            result.push_back(str);
        }
    }
    return result;
}

std::string FormattedString(const std::vector<std::string>& vec) {
    std::ostringstream oss;
    for (const std::string& str : vec) {
        oss << str << "\n";
    }
    return oss.str();
}

int main()
{
    std::vector<std::string> strings = {"apple", "banana", "cherry", "date", "elderberry"};

    char letter = 'a';
    // Create a std::function that checks for the specific letter
    std::function<bool(const std::string&)> letterCondition = startswithPredicateGenerator(letter);
    // Find strings that contain the specified letter
    std::vector<std::string> foundStrings = findStrings(strings, letterCondition);
    std::cout << "Strings containing the letter '" << letter << "':" << std::endl;
    std::cout << FormattedString(foundStrings);
    return 0;
}

