#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return 1;

    int replacePtr = 1, uniquePtr = 0;

    for(; replacePtr < nums.size() && nums[replacePtr] > nums[replacePtr - 1]; replacePtr++);
    if(replacePtr == nums.size()) return nums.size();
    
    uniquePtr = replacePtr + 1;
    for(; uniquePtr < nums.size() && nums[uniquePtr] == nums[uniquePtr - 1]; uniquePtr++);
    while(uniquePtr < nums.size())
    {
        nums[replacePtr] = nums[uniquePtr];

        int currNumber = nums[uniquePtr];
        for(; uniquePtr < nums.size() && nums[uniquePtr] == currNumber; uniquePtr++);

        do
        {
            replacePtr++;
            for(; replacePtr < nums.size() && nums[replacePtr] > nums[replacePtr - 1]; replacePtr++);
        } while(uniquePtr < replacePtr);
    }

    int counter = 1;
    for(int i = 0; i < nums.size() - 1 && nums[i] < nums[i + 1]; i++, counter++);
    return counter;
}


int main()
{
    vector<int> v = {0,0,1,1,1,2,2,3,3,4};
    int res = removeDuplicates(v);

    for(int num : v)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << res << endl;

    return 0;
}