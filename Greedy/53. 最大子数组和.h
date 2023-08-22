#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//贪心算法
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int result = INT32_MIN;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if(sum > result) result = sum;
            
            if(sum < 0) sum = 0;
        }
        return result;
    }
};

//动态规划
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int dp = nums[0];
        int result = dp;
        for(int i = 1; i < nums.size(); i++)
        {
            dp = max(nums[i], dp + nums[i]);
            if(dp > result) result = dp;
        }
        return result;
    }
};

