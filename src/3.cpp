#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) 
{   
    if(s.size() == 0){ return 0; }

    int i = 0, longest = -1;
    while(i < s.size())
    {
    unordered_map<char, int> c; int count = 0;
        auto it = c.find(s[i]);
        while(it == c.end() && i <  s.size())
        {
            c.insert(make_pair(s[i], i));
            count++;
            i++;
            it = c.find(s[i]);
        }
        if(it != c.end()){ i = it->second + 1; }
        if(count > longest){ longest = count; }
    }

    return longest;
}


int main()
{
    string a = "abcabcbb";

    int v = lengthOfLongestSubstring(a);
    cout << "The length of the longest substring is: " << v << "\n";

    return 0;
}