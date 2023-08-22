#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string num = to_string(n);
        string result;
        char beforeNum = '0';
        for(int i = 0; i < num.size(); i++)
        {
            for(int j = '9'; j >= beforeNum; j--)
            {
                string generateLast = string(int(num.size())-i,j);
                if(num >= result + generateLast)
                {
                    result.push_back(j);
                    beforeNum = j;
                    break;
                }
            }
        }
        int resultNum = 0;
        for(int i = 0; i < result.size(); i++)
        {
            resultNum += (result[i]-'0')*pow(10,int(result.size())-i-1);
        }
        return resultNum;
    }
};