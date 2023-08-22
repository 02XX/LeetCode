#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;
    vector<bool> used;

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        used.resize(nums.size(),false);
        sort(nums.begin(), nums.end());
        backTracking(nums,used);
        return result;
    }
    void backTracking(vector<int> &nums, vector<bool> &used)
    {

        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            if (!used[i])
            {
                path.push_back(nums[i]);
                used[i] = true;
                backTracking(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};