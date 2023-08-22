#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int numSize = nums.size();
    
        int index = 0;
        int minStep = 0;

        while(index < numSize-1)
        {
            if (nums[index] + index >= numSize-1)
            {
                minStep++;
                break;
            }
            // 找到最远覆盖范围
            int cover = 0;
            int coverIndex = index;
            for(int i = index+1; i <= nums[index]+index; i++)
            {
                if(nums[i]+i >= cover)
                {
                    cover = nums[i] + i;
                    coverIndex = i;
                }
            }

            index = coverIndex;
            minStep++;
        }
        return minStep;
    }
};