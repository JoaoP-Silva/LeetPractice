#include <iostream>
#include <string>
#include <unordered_map>

bool isPermutation(std::string a, std::string b)
{
    std::unordered_map<char, int> charMap_a, charMap_b;

    for(char c : a)
    {
        if(charMap_a.find(c) == charMap_a.end()) charMap_a.insert(std::make_pair(c, 0));
        else charMap_a[c] += 1;
    }

    for(char c : b)
    {
        if(charMap_b.find(c) == charMap_b.end()) charMap_b.insert(std::make_pair(c, 0));
        else charMap_b[c] += 1;
    }

    for(auto it : charMap_a)
    {
        char key = it.first;
        int val = it.second;

        auto finded = charMap_b.find(key);
        if( finded == charMap_b.end() || finded->second != val) return false;
    }
    
    return true;
}