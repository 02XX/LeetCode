#include"head.h"
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> result;
        backTracking(n,k,1,path,result);
        return result;
    }
    void backTracking(int n, int k, int startIndex, vector<int>& path, vector<vector<int>>& result)
    {
        if(path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for(int i = startIndex; i <= n-(k-path.size()) + 1; i++) //剪枝
        {
            path.push_back(i);
            backTracking(n,k,i+1,path,result);
            path.pop_back();
        }
    }
};
