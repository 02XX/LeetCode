#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n+1, INT32_MAX);

        dp[0] = 0;

        for(int i = 1; i*i <= n; i++)
        {
            for(int j = i*i; j <= n; j++)
            {
                dp[j] = min(dp[j-i*i] + 1, dp[j]);
            }
        }

        return dp[n];
    }
};