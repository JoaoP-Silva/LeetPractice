#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1, m_area = 0;
    while(i<j){
        int area = min(height[i], height[j]) * (j - i);
        if(area > m_area){m_area = area;}
        if(height[i] <= height[j]) {i++;}
        else {j--;}
    }
    cout << "m_area calculado foi " << m_area << endl;
    return m_area;
}

int main(){
    vector<int> a(9);
    for(int i = 0; i<9; i++){
        cin >> a[i];
    }
    maxArea(a);
    return 0;
}