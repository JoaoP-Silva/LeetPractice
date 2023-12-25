#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) 
{
    if(prices.size() <= 1) return 0;

    int l = 0, r = 1, maxProfit = 0, acc = 0;

    for(; r < prices.size(); r++, l++)
    {
        int currProfit = prices[r] - prices[l];
        if(currProfit > 0) acc += currProfit;
        else{ maxProfit += acc; acc = 0; }
    }

    return maxProfit;
}