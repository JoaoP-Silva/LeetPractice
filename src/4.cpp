#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    if(nums1.size() > nums2.size()){ return findMedianSortedArrays(nums2, nums1); }
    //Checking if one or both of the vectors are empty
    vector<int> vecPtr, other;
    if(nums1.size() == 0 && nums2.size() == 0){ return NULL; }
    if(nums1.size() == 0 || nums2.size() == 0)
    {   
        if(nums1.size() == 0){ vecPtr = nums2; other = nums1; }
        else { vecPtr = nums1; other = nums2; }
        int i = vecPtr.size() / 2;
        if(vecPtr.size() % 2 == 0){ return( float(vecPtr[i - 1] + vecPtr[i]) / 2); } 
        else{ return vecPtr[i]; }
    }
    
    int midArr1, minArr1 = 0, maxArr1 = nums1.size();
    int midArr2;
    
    int partitionSiz = (nums1.size() + nums2.size()) / 2;
    midArr1 = nums1.size() / 2;
    midArr2 = (nums1.size() + nums2.size() + 1) / 2 - midArr1;

    bool ok = 0;

    do
    {
        if(midArr1 > 0 && midArr2 < nums2.size())
        {
            if(nums1[midArr1 - 1] > nums2[midArr2])
            {  
                maxArr1 = midArr1 - 1;
                midArr1 = (minArr1 + maxArr1 + 1) / 2;
                (nums1.size() + nums2.size() + 1) / 2 - midArr1;
            }
            else { ok = 1; }
        }
        else { ok = 1; }

        if( midArr2 > 0 && midArr1 < nums1.size() && ok)
        {
            if(nums2[midArr2 - 1] > nums1[midArr1])
            {
                ok = 0;

                minArr1 = midArr1 + 1;
                midArr1 = (minArr1 + maxArr1 + 1) / 2;
                midArr2 = (nums1.size() + nums2.size() + 1) / 2 - midArr1;
            }
        }

    }while(!ok);

    float median;

    if((nums1.size() + nums2.size()) % 2 == 0)
    {
        int lMostArr1, lMostArr2;
        if(midArr1 == 0){ lMostArr1 = INT_MIN; }
        else { lMostArr1 = nums1[midArr1 - 1]; }
        if(midArr2 == 0){ lMostArr2 = INT_MIN; }
        else { lMostArr2 = nums2[midArr2 - 1]; }

        int rMostArr1, rMostArr2;
        if(midArr1 == nums1.size()){ rMostArr1 = INT_MAX; }
        else { rMostArr1 = nums1[midArr1]; }
        if(midArr2 == nums2.size()){ rMostArr2 = INT_MAX; }
        else { rMostArr2 = nums2[midArr2]; }

        int lPart = max(lMostArr1, lMostArr2);
        int rPart = min(rMostArr1, rMostArr2);
        median = (float(lPart + rPart) / 2);
    }
    else 
    {
        int lMostArr1, lMostArr2;
        if(midArr1 == 0){ lMostArr1 = INT_MIN; }
        else { lMostArr1 = nums1[midArr1 - 1]; }
        if(midArr2 == 0){ lMostArr2 = INT_MIN; }
        else { lMostArr2 = nums2[midArr2 - 1]; }

        median = max(lMostArr1, lMostArr2);
    }

    return median;
}   

int main()
{
    vector<int> a = {3};
    vector<int> b = {-2, -1};

    float f = findMedianSortedArrays(a, b);
    cout << "A resposta e: " << f << endl;
    return 0;
}