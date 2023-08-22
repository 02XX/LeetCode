#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    vector<int> path;
    vector<vector<int>> result;


public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backTracking(nums, 0);
        return result;
    }
    void backTracking(vector<int> &nums, int startIndex)
    {

        if (path.size() > 1)
            result.push_back(path);
        if (startIndex  == nums.size())
        {
            return;
        }
        
        unordered_set<int> s;
        for (int i = startIndex; i < nums.size(); i++)
        {
            if(s.find(nums[i]) != s.end()) continue;
            if (path.size() > 0 && path.back() > nums[i])
                continue;
            path.push_back(nums[i]);
            s.insert(nums[i]);
            backTracking(nums, i + 1);
            path.pop_back();
        }
    }
};


int main(int argc, char const *argv[])
{
    Solution a;
    vector<int> b {4, 4, 3, 2,1};
    a.findSubsequences(b);
    return 0;
}
