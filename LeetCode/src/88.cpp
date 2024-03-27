#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    if(n == 0){ n = 0;}
    else if(m == 0)
    {
        for(int i = 0; i < n; i++)
        {
            nums1[i] = nums2[i];
        }
    }
    else
    {
        int size = m + n;
        int c1 = 0, c2 = 0;
    
        vector<int> aux(size);
    
        for(int i = 0; i < size; i++)
        {
            if(c1 >= m)     {aux[i] = nums2[c2]; c2++;}
            else if(c2 >= n){aux[i] = nums1[c1]; c1++;}

            else if(nums1[c1] <= nums2[c2])
            {
                aux[i] = nums1[c1]; 
                c1++;
            }
            else
            {
                aux[i] = nums2[c2];
                c2++;
            } 
        }
    
        for(int i = 0; i < size; i++)
        {
            nums1[i] = aux[i];
        }
    }
}

int main()
{
    vector<int> n1 = {2, 0};
    vector<int> n2 = {1};

    merge(n1, 1, n2, 1);
    for(int n : n1)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}