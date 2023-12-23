#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if(nums.size() >= 0 && nums.size() <= 2) return nums.size();

    int uniquePtr = 0, replacePtr = 2;

    for(; replacePtr < nums.size() && nums[replacePtr] > nums[replacePtr - 2]; replacePtr++);
    if(replacePtr == nums.size() || replacePtr == nums.size() - 1) return replacePtr;  

    for(uniquePtr = replacePtr; uniquePtr < nums.size() && nums[uniquePtr] <= nums[replacePtr]; uniquePtr++);
    if(uniquePtr == nums.size()) return replacePtr;
    
    int flag = 0;
    while(replacePtr < nums.size() && uniquePtr < nums.size())
    {
        int currReplace = replacePtr, currUnique = uniquePtr;
        while(currReplace <= currUnique && uniquePtr < nums.size())
        {
            nums[currReplace] = nums[uniquePtr];
            if(uniquePtr == nums.size() - 1)nums[uniquePtr] = INT_MIN;
            if(uniquePtr < nums.size() - 1 && nums[uniquePtr] == nums[uniquePtr + 1]) uniquePtr++;
            else for(; uniquePtr < nums.size() && nums[uniquePtr] <= nums[replacePtr]; uniquePtr++);
            currReplace++;
        }
        for(; replacePtr < nums.size() && nums[replacePtr] > nums[replacePtr - 2]; replacePtr++);
    }

    flag = 0;
    int counter = 1, prev = nums[0];
    for(int i = 1; i < nums.size(); i++)
    {  
        if(nums[i] == prev && !flag){ flag = 1; counter++; }
        else if(nums[i] == prev && flag || nums[i] < prev) return counter;
        else{ prev = nums[i]; counter++; flag = 0;}
    }
    return counter;
}


int main()
{
    vector<int> v = {0,0,0,0,0,1,2,2,3,3,4,4};
    int res = removeDuplicates(v);

    for(int num : v)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << res << endl;

    return 0;
}