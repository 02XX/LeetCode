#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> path;
        vector<vector<int>> result;
        vector<bool> used(candidates.size(),false);
        sort(candidates.begin(), candidates.end()); // 排序以便于剪枝操作
        backTracking(candidates, 0, target, 0, path, result,used);
        return result;
    }
    void backTracking(vector<int> &candidates, int sum, int target, int startIndex, vector<int> &path, vector<vector<int>> &result, vector<bool>& used)
    {
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size(); i++)
        {
            if (i > 0 && candidates[i] == candidates[i-1] && used[i-1] == false) continue;
            if (sum + candidates[i] > target)
                continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backTracking(candidates, sum, target, i + 1, path, result,used);
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }
};