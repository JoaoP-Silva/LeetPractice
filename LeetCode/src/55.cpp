#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) 
{
    if(nums.size() <= 1) return true;

    int currSize = 0; 
    for(int i = 0; i < nums.size() - 1; i++, currSize--)
    {
        if(nums[i] > currSize) currSize = nums[i];
        else if(currSize == 0) return false;
    }
    return true;
}