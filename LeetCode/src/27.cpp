#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    if(nums.size() == 0) return 0;
    if(nums.size() == 1)
    {
        if(nums[0] != val){return 1;}
        else return 0;
    }
    int replacePtr = nums.size() - 1, valPtr = 0, valCounter = 0;
    while(valPtr < nums.size())
    {
        for(; valPtr < nums.size() && nums[valPtr] != val; valPtr++, valCounter++);
        for(; replacePtr >= 0 && nums[replacePtr] == val; replacePtr--);

        if(replacePtr == -1 || valPtr >= nums.size()) break;

        nums[valPtr] = nums[replacePtr];
        replacePtr--; valPtr++;
    }
    return valCounter;
}

int main()
{
    vector<int> v = {3,3};
    int val = 5;

    int res = removeElement(v, val);
    for(int num : v)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << res << '\n';
    return 0;
}