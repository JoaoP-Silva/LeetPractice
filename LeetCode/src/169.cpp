#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) 
{
    int counter = 0, res = nums[0];
    for(int n : nums)
    {
        if(res == n) counter++;
        else
        {
            if(counter == 0) {res = n; counter = 1;}
            else counter--;
        }
    }
    return res;
}