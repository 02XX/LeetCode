#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> & a, vector<int>b){
            return a[0] < b[0];
        });
        vector<int> pre = intervals[0];
        int remove = 0;
        for (int i = 1; i < intervals.size();i++)
        {
            if (intervals[i][0] < pre[1])
            {
                if (intervals[i][1] < pre[1])
                {
                    pre = intervals[i];
                }
                remove++;
            }
            else
            {
                pre = intervals[i];
            }
        }
        return remove;
    }
};