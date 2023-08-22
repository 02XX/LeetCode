#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int j = 2; j <= n; j++)
        {
            // for(int i = 1; i <= 2; i++)
            // {
            //     if(j >= i)
            //     {
            //         dp[j] += dp[j-i];
            //     }
            // }
            dp[j] += dp[j-1] + dp[j-2];
        }
        return dp[n];
    }
};