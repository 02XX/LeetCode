#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//贪心算法
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int result = 1;
        int preDiff = 0;
        int nextDiff;

        for(int i = 0; i + 1 < nums.size(); i++)
        {
            nextDiff = nums[i+1] - nums[i];
            if((preDiff >= 0 && nextDiff < 0) || (preDiff <= 0 && nextDiff > 0))
            {
                result++;
                preDiff = nextDiff;
            }
        }
        return result;
        
    }
};

//动态规划
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        int up = 1, down = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] > nums[i - 1])
            {
                up = down + 1;
            }
            else if(nums[i] < nums[i - 1])
            {
                down = up + 1;
            }
        }
        
        return max(down,up);
    }
};