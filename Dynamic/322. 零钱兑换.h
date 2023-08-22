#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        // 初始化
        vector<int> dp(amount + 1, INT32_MAX);

        dp[0] = 0;
        // 遍历

        for(int i = 0; i < coins.size(); i++)
        {
            for(int j = coins[i]; j <= amount; j++)
            {
                if(dp[j-coins[i]] != INT32_MAX)
                    dp[j] = min(dp[j-coins[i]] + 1, dp[j]);
            }
        }

        return dp[amount] == INT32_MAX ? -1 : dp[amount];
    }
};

