#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             {
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] > b[0]; });
        vector<vector<int>> temp = intervals;
        vector<vector<int>> result;
        result.push_back(intervals[int(intervals.size()) - 1]);
        int right = 0;
        for (int i = int(intervals.size()) - 2; i >= 0; i--)
        {
            if (intervals[i][0] <= result[right][1])
            {
                vector<int> tempMerge = {min(result[right][0], intervals[i][0]), max(result[right][1], intervals[i][1])};
                result.pop_back();
                result.push_back(tempMerge);
            }
            else
            {
                result.push_back(intervals[i]);
                right++;
            }
        }
        return result;
    }
};