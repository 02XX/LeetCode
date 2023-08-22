#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int index = 0;
        int sum = 0;
        int total = 0;
        for(int i = 0; i < gas.size(); i++)
        {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];

            if(sum < 0)
            {
                index = i+1;
                sum = 0;
            }
        }

        if(total < 0) return -1;
        else return index;
    }
};
