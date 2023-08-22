#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;
    vector<bool> used;

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        used.resize(nums.size());
        sort(nums.begin(),nums.end());
        backTracking(nums, 0, used);
        return result;
    }
    void backTracking(vector<int> &nums, int startIndex,vector<bool>& used)
    {
        result.push_back(path);
        if (path.size() == nums.size())
        {
            return;
        }
        for (int i = startIndex; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            path.push_back(nums[i]);
            used[i] = true;
            backTracking(nums, i + 1,used);
            used[i] = false;
            path.pop_back();
        }
    }
};