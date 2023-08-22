#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "usefulFunction.h"
using namespace std;


// class Solution
// {
// public:
//     bool canPartition(vector<int> &nums)
//     {
//         //01背包
//         //二维DP
//         //背包 num/2
//         //重量 数值
//         //价值 同重量
//         //物品 num
//         int nSize = nums.size();
        
//         int sum = 0;
//         for(int x : nums)
//         {
//             sum += x;
//         }
//         if (sum % 2 != 0)
//             return false;
//         int bag = sum / 2;
//         vector<vector<int>> dp(nSize, vector<int>(bag + 1));

//         //初始化
//         for(int row = 0; row < nSize; row++)
//         {
//             dp[row][0] = 0;
//         }
//         for(int col = 0; col <= bag; col++)
//         {
//             if(col >= nums[0])
//                 dp[0][col] = nums[0];
//             else
//                 dp[0][col] = 0;
//         }
//         for(int i = 1; i < nSize; i++)
//         {
//             for(int j = 1; j <= bag; j++)
//             {
//                 if(j < nums[i])
//                     dp[i][j] = dp[i - 1][j];
//                 else
//                     dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]] + nums[i]);
//             }
//         }

//         return dp[nSize-1][bag] == bag;
//     }
// };

// class Solution
// {
// public:
//     bool canPartition(vector<int> &nums)
//     {
//         // 01背包
//         // 二维DP + 状态压缩
//         // 背包 num/2
//         // 重量 数值
//         // 价值 同重量
//         // 物品 num
//         int nSize = nums.size();
//         int sum = 0;
//         for (int x : nums)
//         {
//             sum += x;
//         }
//         if (sum % 2 != 0)
//             return false;
//         int bag = sum / 2;
//         //初始化
//         vector<int> dp(bag+1,0);
//         for(int i = 0; i < nSize; i++)
//         {
//             for(int j = bag; j >= nums[i]; j--)
//             {
//                 dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]);
//             }
//         }
//         return dp[bag] == bag;
//     }
// };

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        // 01背包
        // 二维DP + 状态压缩
        // 背包 num/2
        // 重量 数值
        // 价值 同重量
        // 物品 num
        int nSize = nums.size();
        int sum = 0;
        for (int x : nums)
        {
            sum += x;
        }
        if (sum % 2 != 0)
            return false;
        int bag = sum / 2;
        // 初始化
        vector<bool> dp(bag + 1, false);
        dp[0] = true;
        for (int i = 0; i < nSize; i++)
        {
            for (int j = bag; j >= nums[i]; j--)
            {
                dp[j] = dp[j-nums[i]] || dp[j];
            }
        }
        return dp[bag];
    }
};