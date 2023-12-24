#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int>& nums, int k)
{
    if(k == 0) return;

    int changes = 0, siz = nums.size(), i = 0, cpy = nums[0];

    int l = 1;
    for(; l <= siz; l++) if(!((l * k) % siz)) break;
    
    while(changes < siz)
    {
        changes++;
        if(l <= siz && !(changes % l))
        {
            int j = (i + k) % siz, aux;
            aux = nums[(j + 1) % siz];
            nums[j] = cpy;
            cpy = aux;
            j = (j + 1) % siz; 
            i = j;
        }
        else
        {
            int j = (i + k) % siz;
            int aux = nums[j];
            nums[j] = cpy;
            cpy = aux;
            i = j;
        }
    }
}


int main()
{
    vector<int> v = {1,2,3,4,5,6};
    rotate(v, 4);

    for(int n : v)
    {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}