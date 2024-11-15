#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool startsWithB(const string& str) {

    return ( str.at(0) == 'B');
}

bool startsWithC(const string& str) {

    return ( str.at(0) == 'C');
}

bool startsWithR(const string& str) {

    return ( str.at(0) == 'R');
}

bool endsWithB(const string& str) {

    return ( str.at(str.length()-1) == 'B');
}

vector<string> fliterString(vector<string> names, bool (*predicate) (const string& str)) 
{
    vector<string> result_list;
    for (auto name: names){
        // Compare the first char of the names with the given alphabet
        if(predicate(name)) {
            
                result_list.push_back(name);
            
        }
    }
    return result_list;
}

int main()
{
    vector<string> names = {"Bosch", "Bengalore", "One", "Line", "Forward"};
    
    vector<string> result_list = fliterString(names, &startsWithB);
    
    for (auto name: result_list)
    {
        cout << name << endl;
    }

    return 0;
}
