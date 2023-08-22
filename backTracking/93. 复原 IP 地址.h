#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> path;
        vector<string> result;
        backTracking(s,0,path,result);
        return result;
    }
    bool biggerThan255(string s)
    {
        if(s.size() > 3) return true;
        else if(s.size() < 3) return false;
        else if(s > "255") return true;
        else return false;
    }
    bool isPreHas0(string s)
    {

        if (s.size() == 1 && s [0] == '0')
            return false;
        if (s.size() > 1 && s [0] == '0')
            return true;
        return false;
    }
    void backTracking(string s,int startIndex, vector<string>& path, vector<string>& result)
    {
        if(path.size() == 3)
        {
            if (s.substr(startIndex, s.size()).size() == 0 || isPreHas0(s.substr(startIndex, s.size())) || biggerThan255(s.substr(startIndex, s.size())))
            {
                return;
            }
            else
            {
                string temp = "";
                for (string x : path)
                {
                    temp += x + ".";
                }
                temp += s.substr(startIndex,s.size());
                result.push_back(temp);
                return;
            }
        }

        for(int i = startIndex; i < s.size(); i++)
        {
            string cutStr = s.substr(startIndex, i - startIndex + 1);

            if(isPreHas0(cutStr) || biggerThan255(cutStr)) //剪枝
            {
                continue;
            }
            
            path.push_back(cutStr);
            backTracking(s,i+1,path,result);
            path.pop_back();

        }

    }
};