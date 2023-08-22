#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1,0)));
        for(int i = 1; i <= k; i++)
        {
            dp[0][1][i] = -prices[0];
        }
        for(int i = 1; i < prices.size(); i++)
        {
            for(int j = 1; j <= k; j++)
            {
                dp[i][0][j] = max(dp[i - 1][0][j], dp[i - 1][1][j] + prices[i]);
                dp[i][1][j] = max(dp[i - 1][1][j], dp[i - 1][0][j - 1] - prices[i]);
            }
        }
        return dp[int(prices.size())-1][0][k];
    }
};

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {

        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int i = 1; i <= k; i++)
        {
            dp[0][1][i] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i][0][j] = max(dp[i - 1][0][j], dp[i - 1][1][j] + prices[i]);
                dp[i][1][j] = max(dp[i - 1][1][j], dp[i - 1][0][j - 1] - prices[i]);
            }
        }
        return dp[int(prices.size()) - 1][0][k];
    }
};