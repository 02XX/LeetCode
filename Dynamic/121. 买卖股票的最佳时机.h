#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//不知道咋写的
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int dp0 = 0, dp1 = 0;
//         int maxProfit = 0;
//         for(int i = 1; i < prices.size(); i++)
//         {
//             dp1 = max(dp0 + prices[i] - prices[i - 1], dp1);
//             maxProfit = max(maxProfit, dp1);
//             dp0=dp1;
//             dp1 = 0;
//         }
//         return maxProfit;
//     }
// };

// 版本一
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if (len == 0)
            return 0;
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < len; i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[len - 1][1];
    }
};
