#include<iostream>
#include<vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> path;
        vector<vector<int>> result;
        backTracking(n,k,1,path,result);
        return result;
    }
    int sumPath(vector<int> path)
    {
        int sum = 0;
        for(int x : path)
        {
            sum += x;
        }
        return sum;
    }
    void backTracking(int n, int k, int startIndex, vector<int>& path, vector<vector<int>>& result)
    {
        if(sumPath(path) == n && path.size() == k)
        {
            result.push_back(path);
            return;
        }
        if(path.size() > k || sumPath(path) > n)
            return;
        
        for(int i = startIndex; i <= 9; i++)
        {
            if(i > n -sumPath(path) || path.size() > k) //剪枝
                continue;
            path.push_back(i);
            backTracking(n,k,i+1,path,result);
            path.pop_back();
        }
    }
};