#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct VectorHasher {
    int operator()(const vector<int> &V) const {
        int hash = V.size();
        for(auto &i : V) {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<vector<int>, vector<string>, VectorHasher> result;
    for(int i=0; i<strs.size(); i++){
        vector<int> temp(26, 0);
        string t = strs[i];
        for(int j = 0; j<t.size(); j++){
            int index = (int)t[j] - 97;
            temp[index] = temp[index] + 1;
        }
        auto it = result.find(temp);
        if(it == result.end()){
            vector<string> s; s.push_back(t);
            result.insert(make_pair(temp, s));
        }
        else{it->second.push_back(t);}
    }
    vector<vector<string>> anagrams;
    for(auto it = result.begin(); it !=result.end(); it++){
            anagrams.push_back(it->second);
    }
    /**for(int i=0; i<anagrams.size(); i++){
        cout << "Grupo " << i << " de anagramas\n";
        for(int j=0; j<anagrams[i].size(); j++){
            string aux = anagrams[i][j];
            cout << aux << " ";
        }
        cout << endl;
    } **/
    return anagrams;
}

int main(){
    int a;
    vector<string> input;
    cin >> a;
    for(int i=0; i<a; i++){
        string aux;
        cin>>aux;
        input.push_back(aux);
    }
    groupAnagrams(input);
    return 0;
}