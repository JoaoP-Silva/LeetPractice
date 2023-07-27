#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) 
{   
    if(s.size() == 0){ return 0; }

    int i = 0, count = 0, longest = -1;
    int windowBack = -1;
    unordered_set<char> charSet;

    while(i < s.size())
    {
        if(charSet.find(s[i]) == charSet.end())
        {
            charSet.insert(s[i]);
            count++; i++;
        }
        else
        {
            if(count > longest){ longest = count; }
            do
            { 
                windowBack++; 
                charSet.erase(s[windowBack]);
            }while(s[windowBack] != s[i]);
            count = i - windowBack - 1;
        }
    }
    if(count > longest){ longest = count; }

    return longest;
}


int main()
{
    string a = "abcabcbb";

    int v = lengthOfLongestSubstring(a);
    cout << "The length of the longest substring is: " << v << "\n";

    return 0;
}