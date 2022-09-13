#include <iostream>
#include <vector>


using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> from_r = nums;
    vector<int> sol(nums.size());
    for(int i = 1, j = nums.size()-2; i<nums.size(); i++, j--){
        nums[i] *= nums[i-1];
        from_r[j] *= from_r[j+1];
    }
    sol[0] = from_r[1]; sol[sol.size() - 1] = nums[nums.size() - 2];
    for(int i = 1; i< sol.size() -1; i++){
        sol[i] = nums[i - 1] * from_r[i + 1];
    }
    cout << "vetor calculado foi:\n";
    for(int i = 0; i < sol.size(); i++){
        cout << sol[i] << " ";
    }
    return sol;
}

int main(){
    vector<int> a(4);
    for(int i =0; i<4; i++){
        cin >> a[i];
    }
    productExceptSelf(a);
    return 0;
}