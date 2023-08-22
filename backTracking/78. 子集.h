#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {

        backTracking(nums,0);
        return result;
    }
    void backTracking(vector<int> &nums, int startIndex)
    {
        result.push_back(path);
        if(path.size() == nums.size())
        {
            return;
        }
        for(int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backTracking(nums,i+1);
            path.pop_back();
        }
    }
};