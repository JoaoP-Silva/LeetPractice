#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
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

    //Checking special cases when one of both vectors are singular
    if(nums1.size() == 1 && nums2.size() == 1)
    {
        return(float(nums1[0] + nums2[0]) / 2);
    }
    if( nums1.size() == 1 || nums2.size() == 1)
    {
        //Generalizes the name of the unique vector as "other", while the vector with more than one element is
        // referenced by the "vecPtr".
        if(nums1.size() == 1){ vecPtr = nums2; other = nums1; }
        else { vecPtr = nums1; other = nums2; }
        int i = vecPtr.size() / 2;  

        if(vecPtr.size() % 2 == 1)
        {
            if( vecPtr[i - 1] < other[0] )
            {
                if(vecPtr[i] < other[0]){ return float(vecPtr[i - 1] + vecPtr[i]) / 2; }
                else{ return float(vecPtr[i - 1] + other[0]) / 2; }
            }
        }
        else
        {
            if(vecPtr[i - 1] < other[0])
            {
                if(vecPtr[i] > other[0]){ return other[0]; }
                else{ return vecPtr[i]; }
            }
            else{ return vecPtr[i - 1]; }
        }
    }
    
    int midArr1, minArr1 = 0, maxArr1 = nums1.size() - 1;
    int midArr2;
    
    int partitionSiz = (nums1.size() + nums2.size()) / 2;
    midArr1 = nums1.size() / 2;
    midArr2 = partitionSiz - midArr1;

    bool ok = 0;

    do
    {
        if(midArr1 > 0 && midArr2 < nums2.size())
        {
            if(nums1[midArr1 - 1] > nums2[midArr2])
            {  
                maxArr1 = midArr1 - 1;
                midArr1 = (minArr1 + maxArr1 + 1) / 2;
                midArr2 = partitionSiz - midArr1;
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
                midArr2 = partitionSiz - midArr1;
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
        else { lMostArr2 = nums1[midArr2 - 1]; }

        median = max(lMostArr1, lMostArr2);
    }

    return median;
}   

int main()
{
    vector<int> a = {1, 2};
    vector<int> b = {1, 2, 3};

    float f = findMedianSortedArrays(a, b);
    cout << "A resposta e: " << f << endl;
    return 0;
}