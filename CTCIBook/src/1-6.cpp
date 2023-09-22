#include <iostream>
#include <string>

std::string* stringComprehension(std::string s)
{
    int count = 0;
    std::string* comprehended = new std::string; 

    char lastChar;
    if(!s.empty()) lastChar = s[0];
    comprehended->push_back(s[0]);

    for(char c : s)
    {
        if(c == lastChar) count++;
        else
        {
            comprehended->append(std::to_string(count));
            comprehended->push_back(c);
            count = 1;
        }
        lastChar = c;
    }
    comprehended->append(std::to_string(count));

    if(comprehended->size() >= s.size()) comprehended = &s;
    return comprehended;
}


int main()
{
    std::string s, *res;
    std::cin >> s;

    res = stringComprehension(s);
    std::cout << "The comprehended string is " << *res << std::endl;
}