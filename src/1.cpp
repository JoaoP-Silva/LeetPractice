#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int, int>> v;
    for(int i=0; i<nums.size(); i++){
        v.push_back(make_pair(nums[i], i));
    }
    sort(v.begin(), v.end());
    int i =0, j = v.size() - 1;
    while(i < j){
        int sum = v[i].first + v[j].first;
        if(sum == target){
            vector<int> sol(2, v[i].second); sol[1] = v[j].second;
            return sol;
        }
        else if(sum > target){ j-- ; }
        else{i ++;}
    }
    vector<int> sol(2, 0); return sol;
}

int main(){return 1;}