#include <iostream>
#include <string>

bool oneAway(std::string a, std::string b)
{
    bool madeOneModification = false;

    int diff = abs(a.size() - b.size());
    if(diff > 1) return false;

    //Computes the case when the strings have the same size
    else if(diff == 0)
    {
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] != b[i])
            {
                if(madeOneModification) return false;
                else madeOneModification = true;
            }
        }
    }

    //Computes the case when the difference in string sizes its exactly one
    else
    {
        std::string *bigger, *smaller;
        if(a.size() >= b.size())
        {
            bigger = &a; smaller = &b;
        }
        else
        {
            bigger = &b; smaller = &a;
        }

        for(int i = 0; i < smaller->size(); i++)
        {
            if(bigger[i] != smaller[i])
            {
                if(bigger[i + 1] == smaller[i])
                {
                    if(madeOneModification) return false;
                    else madeOneModification = true;
                }
            }
        }
    }

    return true;
}


int main()
{
    std::string a, b;
    std::cin >> a;
    std::cin >> b;

    if(oneAway(a,b)) std::cout << "The strings are one modification away.\n";
    else std::cout << "The strings are more than one modification away.\n";

    return 0;
}