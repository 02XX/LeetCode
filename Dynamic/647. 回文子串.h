#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int result = 0;
        for(int i = int(s.size())-1; i >= 0; i--)
        {
            for(int j = i; j < s.size(); j++)
            {
                if(s[i] == s[j] && (j - i <= 1 || dp[i+1][j-1]))
                {
                    result++;
                    dp[i][j] = true;
                }
            }
        }
        
        return result;
    }
};