#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hIndex(vector<int>& citations) 
{
    sort(citations.begin(), citations.end());
    int n = citations.size();

    // Couting array
    vector<int> counting(citations.size() + 1, 0);
    // Computing the counting value for each citations number
    for(int paper : citations)
    {
        if(paper == 0) continue;
        else if(paper >= n) counting[n] += 1;
        else counting[paper] += 1;
    }
    // Reverse acumulative sum
    for(int i = counting.size() - 2; i > 0; i--) counting[i] += counting[i + 1];

    for(int i = n; i > 0; i--)
    {
        if(counting[i] >= i) return i;
    }
    return 0;
}

int main()
{
    vector<int> citations = {1};
    cout << hIndex(citations) << endl;
    return 0;
}