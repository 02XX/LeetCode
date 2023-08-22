#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

class Solution
{
    vector<string> path;
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        map<string,map<string,int>> mapping;
        for(auto& x : tickets)
        {
            mapping[x[0]][x[1]]++;
        }
        path.push_back("JFK");
        backTracking(tickets.size(),mapping);
        return path;
    }
    bool backTracking(int ticketSize, map<string, map<string, int>> &mapping)
    {
        if(path.size() == ticketSize + 1)
        {
            return true;
        }

        for(auto& plane : mapping[path.back()])
        {
            if(plane.second > 0)
            {
                path.push_back(plane.first);
                plane.second--;
                if(backTracking(ticketSize,mapping)) return true;
                plane.second++;
                path.pop_back();
            }
        }
        return false;
    }
};