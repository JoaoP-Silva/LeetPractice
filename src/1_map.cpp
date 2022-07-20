#include <unordered_map>
#include <stdlib.h>
#include <vector>
#include <iostream>


using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int>s;
    for(int i=0; i<nums.size(); i++){
        int comp = target - nums[i];
        auto it = s.find(comp);
        if(it != s.end()){
            vector<int> x(2, i); x[1] = it->second; 
            return x;
        }
        s.insert(make_pair(nums[i],i));
    }
    vector<int> x(2, 0); return x;
}

int main(){return 1;}
