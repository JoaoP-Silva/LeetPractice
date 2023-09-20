#include <iostream>
#include <unordered_set>
#include <string>
#include <algorithm>

//Return True of False whether the string contains unique characters or not. Uses a, unordered_set for it.
bool uniqueCharacters_set(std::string s)
{
    std::unordered_set<char> charSet;
    for(char c : s)
    {
        if(charSet.find(c) == charSet.end()) {charSet.insert(c);}
        else return false;
    }

    return true;
}

//Return True of False whether the string contains unique characters or not without using extra data structures.
bool uniqueCharacters(std::string s)
{
    std::sort(s.begin(), s.end());
    for(int i = 1; i < s.size() - 1; i++)
    {
        if(s[i] == s[i - 1] || s[i] == s[i + 1]) {return false;}
    }
    return true;
}

int main()
{
    std::string input;
    std::cin >> input;

    if(uniqueCharacters(input)) std::cout << "True\n"; 
    else std::cout << "False\n";

    if(uniqueCharacters_set(input)) std::cout << "True\n"; 
    else std::cout << "False\n";

    return 0;
}