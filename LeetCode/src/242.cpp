#include <string>
#include <map>
#include <iostream>

using namespace std;

bool isAnagram(string s, string t) {
    map<char, int> s_s;
    if(s.size() != t.size()){return false;}
    for(int i = 0; i<s.size(); i++){
        auto it = s_s.find(s[i]);
        if(it == s_s.end()){s_s.insert(make_pair(s[i], 1));}
        else{it->second += 1;}
    }
    for(int i = 0; i < t.size(); i++){
        auto it = s_s.find(t[i]);
        if(it == s_s.end() || it->second == 0){
            cout << "first = " << it->first << " second = " << it->second << endl;
            return false;
            }
        else{it->second -= 1;}
    }
    return true;
}


int main(){
    string a("anagram"), b("nagaram");
    cout << "result = " <<isAnagram( a, b) << endl;
    return 1;
}