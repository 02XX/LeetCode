#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        for(int &stone : stones)
        {
            sum += stone;
        }
        int bag = sum / 2;
        vector<int> dp(bag+1,0);

        for(int i = 0; i < stones.size(); i++)
        {
            for(int j = bag; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j-stones[i]] + stones[i]);
            }
        }
        return abs(sum-dp[bag]*2);
    }
};