#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size()+1,false);
        dp[0] = true;

        for(int j = 1; j <= s.size(); j++)
        {
            for(string word : wordDict)
            {
                string subStr = "";
                if (j - int(word.size()) >= 0)
                    subStr = s.substr(j - int(word.size()), word.size());
                if(subStr == word)
                {
                    dp[j] = dp[j - int(word.size())] || dp[j];
                }
            }
        }
        return dp[int(s.size())];
    }
};