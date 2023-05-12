#include <iostream>
#include <vector>
#include <limits>

using namespace std; 

int maxSubArray(vector<int>& nums) {
    if(nums.empty()){return 0;}

    vector<int> sumArray;
    int sum = nums[0]; sumArray.push_back(nums[0]);
    int subArrayInitIdx = 0, subArrayEndIdx = 0, auxIdx, greatestSum = sumArray[0];

    for(int i = 1; i < nums.size(); i++){
        int newSum = sum + nums[i];
        if(newSum <= nums[i]){
            auxIdx = i;
            sum = nums[i];
            sumArray.push_back(nums[i]);
        }else{
            sum += nums[i];
            sumArray.push_back(sum);
        }
        if(greatestSum < sumArray[i]){ 
            greatestSum = sumArray[i];
            subArrayInitIdx = auxIdx; 
            subArrayEndIdx = i;
        }
    }
    cout << "Subarray init index = " << subArrayInitIdx << endl;
    cout << "Subarray end index = " << subArrayEndIdx << endl;
    return greatestSum;
}

int main(){
    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    for(auto i : v){
        cout << i << " ";
    }
    cout << endl;
    int s = maxSubArray(v);
    cout << "The max subarray it has the largest sum " << s << endl;
    return 0;
}