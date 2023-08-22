#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int numsSize = nums.size();
        int index = 0;
        while (index < numsSize-1)
        {
            if(nums[index] == 0) return false;
            int priority = 0;
            int nextIndex = index;
            for(int i = index + 1; i <= min(nums[index] + index, numsSize-1); i++)
            {
                if(i == numsSize-1) return true;
                if(nums[i]+i >= priority)
                {
                    priority = nums[i]+i;
                    nextIndex = i;
                } 
            }
            index = nextIndex;
        }
        return true;
    }
};