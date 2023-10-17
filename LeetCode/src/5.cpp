#include <iostream>
#include <string>
#include <stdbool.h>

using namespace std;

string longestPalindrome(string s) 
{  
    if(s.size() <= 1){ return s; }
    
    int bigger = 1, bigR = 0, bigL = 0;

    int median; 
    if(s.size() % 2){ median = s.size()/2; }
    else median = s.size()/2 - 1;

    int growCounter = 1;
    for(int i = 0; i < s.size(); i++)
    {
        if(i <= median)
        {
            int count = 0, lptr = i, rptr = i;
            bool alternate = 1;
            while(count < growCounter)
            {
                if(alternate)
                {
                    rptr++;
                    alternate = ~alternate;  
                    if(s[rptr] == s[lptr])
                    {
                        if(rptr - lptr > bigger)
                        {
                            bigR = rptr; bigL = lptr;
                        }
                    }
                    else break;
                }
                else
                {
                    lptr--;
                    alternate = ~alternate;
                    if(s[rptr] == s[lptr])
                    {
                        if(rptr - lptr > bigger)
                        {
                            bigR = rptr; bigL = lptr;
                        }
                    }
                    else break;
                }

                if(growCounter == 1){ growCounter = 2; }
                else growCounter += 2;
            }
        }

        else
        {
            int count = 0, lptr = i, rptr = i;
            bool alternate = 0;
            while(count < growCounter)
            {
                if(alternate)
                {
                    rptr++;
                    alternate = ~alternate;  
                    if(s[rptr] == s[lptr])
                    {
                        if(rptr - lptr > bigger)
                        {
                            bigR = rptr; bigL = lptr;
                        }
                    }
                    else break;
                }
                else
                {
                    lptr--;
                    alternate = ~alternate;
                    if(s[rptr] == s[lptr])
                    {
                        if(rptr - lptr > bigger)
                        {
                            bigR = rptr; bigL = lptr;
                        }
                    }
                    else break;
                }

                if(growCounter == 2){ growCounter = 1; }
                else growCounter -= 2;
            }
        }     
    }

}

int main()
{   
    char buff[100];
    cin >> buff;
    string a(buff);
    string res = longestPalindrome(a);
    cout << res;
    return 0;
} 