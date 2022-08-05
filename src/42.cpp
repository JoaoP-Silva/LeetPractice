#include<vector>
#include<iostream>

using namespace std;

int trap(vector<int>& height) {
    int ptr_l = 0, ptr_r = height.size() - 1;
    int l_max = height[ptr_l], r_max = height[ptr_r], w_trapped = 0;
    if(height.size() == 0){return w_trapped;}
    
    while(ptr_l != ptr_r - 1){
        int t_height;
        if(l_max <= r_max){
            ptr_l ++;
            t_height = height[ptr_l];
            if(t_height > l_max){l_max = t_height;}
            w_trapped += l_max - t_height;
        }
        else{
            ptr_r --;
            t_height = height[ptr_r];
            if(t_height > r_max){r_max = t_height;}
            w_trapped += r_max - t_height;
        }
    }
    cout << w_trapped << endl;
    return w_trapped;
}

int main(){
    int ints[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> a (ints, ints + sizeof(ints) / sizeof(int) );
    trap(a);
    return 0;
}