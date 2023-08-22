#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &nums, int k)
    {
        for(int i = 0; i < k; i++)
        {
            //找到最小元素的下标
            int index = 0;
            int minNum = nums[index];
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] < minNum)
                {
                    minNum = nums[i];
                    index = i;
                }
            }
            nums[index] = -nums[index];
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        return sum;
    }
    
};