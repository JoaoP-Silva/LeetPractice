#include <iostream>
#include <string>
#include <stdbool.h>

using namespace std;

string longestPalindrome(string s) 
{ 
    int siz = s.size();

    if(siz == 1){ return s; }

    //Pointers for the result
    int resR = 0, resL = 0, biggerSubs = 1;
    for(int i = 0; i < siz; i++)
    {
        //Even substrings
        for(int l = i, r = i + 1; r < siz && l >= 0; l--, r++)
        {
            if(s[l] == s[r])
            {
                if(r - l + 1> biggerSubs)
                {
                    resR = r; resL = l;
                    biggerSubs = r - l + 1;
                }
            }
            else break;
        }

        //Odd substrings 
        for(int l = i - 1, r = i + 1; r < siz && l >= 0; l--, r++)
        {
            if(s[l] == s[r])
            {
                if(r - l + 1> biggerSubs)
                {
                    resR = r; resL = l;
                    biggerSubs = r - l + 1;
                }
            }
            else break;
        }
    }

    string res(s, resL, biggerSubs);
    return res;

}

int main()
{   
    char buff[100] = "cbbd";
    string a(buff);
    string res = longestPalindrome(a);
    cout << res;
    return 0;
} 