#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums)
{
    if(nums.size() <= 1) return 0;

    int i = 0, jumps = 1;
    while(1)
    {
        if(i + nums[i] >= nums.size() - 1) break;
        int maxJump = 0, aux;
        for(int j = i + nums[i]; j > i; j--)
        {
            if(j + nums[j] > maxJump){ maxJump = j + nums[j]; aux = j;}
        }
        i = aux;
        jumps ++;
    }

    return jumps;
}

int main()
{
    vector<int> v = {10,9,8,7,6,5,4,3,2,1,1,0};
    int res = jump(v);
    cout << res << endl; 

    return 0;
}