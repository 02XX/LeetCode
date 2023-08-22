#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> result;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        computerPalindrome(s,dp);
        backTracking(s,0,path,result,dp);
        cout << result.size();
        return result;
    }

    void computerPalindrome(string s, vector<vector<bool>> &dp)
    {

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (i == j || i - j == 1)
                    dp[i][j] = true;
            }
        }
        for (int i = s.size() - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < s.size(); j++)
            {
                if (dp[i + 1][j - 1] && s[i] == s[j])
                    dp[i][j] = true;
            }
        }
    }

    void backTracking(string s, int startIndex ,vector<string>& path, vector<vector<string>>& result,vector<vector<bool>>& dp)
    {
        if(startIndex >= s.size())
        {
            result.push_back(path);
            return;
        }
            
        
        for(int i = startIndex; i < s.size(); i++)
        {
            string cutStr = s.substr(startIndex,i - startIndex + 1);
            if(dp[startIndex][i])
            {
                path.push_back(cutStr);
            }
            else
                continue;
            backTracking(s,i + 1,path,result,dp);
            path.pop_back();
        }
    }
};


int main(int argc, char const *argv[])
{
    Solution a;
    string s = "abbab";
    a.partition(s);
    return 0;
}
