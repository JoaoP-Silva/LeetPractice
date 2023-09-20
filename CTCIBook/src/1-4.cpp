#include <iostream>
#include <string>
#include <unordered_map>

bool palinPermut(std::string  s)
{
    std::unordered_map<char, int> charMap;
    for(char c : s)
    {
        if(charMap.find(c) == charMap.end()) charMap[c] = 1;
        else charMap[c] += 1;
    }

    bool oneOddFinded = false;
    for(auto item : charMap)
    {
        if(item.second % 2)
        {
            if(oneOddFinded) { return false; }
            else { oneOddFinded = true; }
        }
    }

    return true;
}


int main()
{
    std::string s;
    std::cin >> s;

    if(palinPermut(s)) std::cout << "is a permutation of a palindrome\n";
    else std::cout << "isn't a permutation of a palindrome\n";

    return 0;
}