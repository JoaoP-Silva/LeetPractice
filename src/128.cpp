#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;
    unordered_set<int> s;
    for(int i=0; i<nums.size(); i++){
        s.insert(nums[i]);
    }
    int longest = 1;
    while(s.size()){
        int seq = 1, t = *s.begin(), aux = t;
        s.erase(t);
        while(s.find(aux - 1) != s.end()){
            seq++;
            aux = aux -1;
            s.erase(aux);
        }
        aux = t;
        while(s.find(aux + 1) != s.end()){
            seq++;
            aux = aux + 1;
            s.erase(aux);
        }
        if(seq > longest) longest = seq;
    }
    cout<<"A maior sequencia encontrada foi de " << longest << " numeros\n";
    return longest;
}

int main(){
    vector<int> a(5);
    cout << "Digite 5 numeros\n";
    for(int i =0; i<5; i++){cin>>a[i];}
    longestConsecutive(a);
    return 0;
}