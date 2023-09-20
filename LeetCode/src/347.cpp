#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> result;
    unordered_map<int, int> counter;
    for(int i =0; i<nums.size(); i++){
        auto it = counter.find(nums[i]);
        if (it == counter.end()){counter.insert(make_pair(nums[i], 1));}
        else{ it->second++ ;}
    }
    unordered_map <int, vector<int>> sol;
    for(int i=0; i<nums.size(); i++){
        vector<int> temp; sol.insert(make_pair(i+1, temp));
    }
    for(auto it = counter.begin(); it!=counter.end(); it++){
        sol[it->second].push_back(it->first);
    }
    int k_c = 0;
    for(int i = nums.size(); i>0; i--){
        if(!sol[i].empty()){
            for(int j = 0; j<sol[i].size(); j++){
                result.push_back(sol[i][j]);
                k_c++;
            }
            if(k_c == k) break;
        }
    }
    cout << "os k primeiros numeros sao \n";
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    return result;
}

int main(){
    vector<int> a(6);
    for(int i=0; i<6; i++){
        cin >> a[i];
    }
    cout << "Digite k\n";
    int k; cin >> k;
    topKFrequent(a, k);
}