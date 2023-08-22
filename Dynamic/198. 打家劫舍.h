#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int dp[n]; // dp[i]表示小偷到i间房（没有选择偷or不偷）时所能获得最大金额
        dp[0] = nums[0];
        dp[1] = max(nums[1],nums[0]);

        for(int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(n);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return max(dp[n-1], dp[n-2]+nums[n-1]);
    }   
};
