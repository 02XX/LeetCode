#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        map<char, int> maxPostion;
        vector<int> result;
        for (int i = 0; i < s.size(); i++)
        {
            maxPostion[s[i]] = i;
        }
        int endPostion = 0;
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            endPostion = max(endPostion, maxPostion[s[i]]);
            if (i == endPostion)
            {
                result.push_back(endPostion - start + 1);
                start = i + 1;
                endPostion = 0;
            }
        }
        return result;
    }
};