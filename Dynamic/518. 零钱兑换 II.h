#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        //初始化
        vector<int> dp(amount+1,0);

        dp[0] = 1;
        //遍历

        for(int j = 0; j <= amount; j++)
        {
            for(int i = 0; i < coins.size(); i++)
            {
                if (j - coins[i] >= 0)
                    dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};