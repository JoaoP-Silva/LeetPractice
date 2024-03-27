#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) 
{
    if(prices.size() <= 1) return 0;

    int buyPtr = 0, sellPtr = 1, maxProfit = 0;

    for(; sellPtr < prices.size(); sellPtr++)
    {
        int profit = prices[sellPtr] - prices[buyPtr];
        if(profit < 0) buyPtr = sellPtr;
        else if(profit > maxProfit) maxProfit = profit;
    }

    return maxProfit;
}