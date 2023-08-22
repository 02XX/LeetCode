#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> path;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end()); // 排序以便于剪枝操作
        backTracking(candidates,0,target,0,path,result);
        return result;
    }
    void backTracking(vector<int> &candidates, int sum,int target, int startIndex, vector<int>& path, vector<vector<int>>& result)
    {
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i < candidates.size(); i++)
        {
            if(sum + candidates[i] > target) continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backTracking(candidates,sum,target,i,path,result);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};