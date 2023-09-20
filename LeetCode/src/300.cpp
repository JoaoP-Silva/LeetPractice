#include <vector>
#include <iostream>

using namespace std;
int lengthOfLIS(vector<int>& nums) {
    vector<int> v(nums.size(), 0);
    int lis = 1;
    v[nums.size() - 1] = 1;
    if(nums.size() == 1){return lis;}
    for(int i=nums.size()-2; i>=0; i--){
        //cout << "prev = " << prev << " prev_l = " << prev_l << endl;
        int max_s = 0;
        for(int j=i; j<v.size(); j++){
            if(nums[i] < nums[j]){
                if(v[j] > max_s){max_s = v[j];}
            }   
        }
        cout << "nums[i] = " << nums[i] << " v[i] = " << max_s + 1 << endl;
        v[i] = max_s + 1;
        if(lis < v[i]){lis = v[i];}
    }
    cout << "lis = " << lis << endl;
    return lis;
}

int main(){
    int myints[] = {10,9,2,5,3,7,101,18};
    vector<int> v(myints, myints + sizeof(myints) / sizeof(int) );
    lengthOfLIS(v);
    return 1;
}