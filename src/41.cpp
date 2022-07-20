#include<vector>
#include<iostream>

using namespace std;
int firstMissingPositive(vector<int>& nums) {
    int bound = nums.size(); if(!bound)return 1;
    for(int i=0; i<nums.size(); i++){
        if(nums[i]<=0){nums[i] = INT_MAX;}
    }
    for(int i=0; i<bound; i++){
        int number = abs(nums[i]);
        int index = number - 1;
        if(index < bound){
            if(nums[index] > 0)nums[index] = nums[index] * -1;
        }
    }
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] >= 0){
            cout << i + 1 << endl;
            return i + 1;
        }
    }
    return bound+1;
}

int main(){return 1;}
