#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        //三维DP 状态压缩

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(string & str : strs)
        {
            int zeros = count(str.begin(),str.end(),'0');
            int ones = count(str.begin(), str.end(),'1');

            for(int i = m; i >= zeros; i--)
            {
                for(int j = n; j >= ones; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones] + 1);
                }
            }
        }
        return dp[m][n]; 
    }
};

