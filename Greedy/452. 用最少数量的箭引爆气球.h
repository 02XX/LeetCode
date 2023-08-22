#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int bow = 0;
        sort(points.begin(), points.end(), [](vector<int> & a, vector<int>& b){
            return a[1] < b[1];
        });
        int left = points[0][1];
        bow++;
        for(auto & point : points)
        {
            if(point[0] > left)
            {
                left = point[1];
                bow++;
            }
        }
        return bow;
    }
};