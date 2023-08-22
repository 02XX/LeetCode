#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0, ten = 0, twenty = 0;
        int needFive = 0, needTen = 0, needTwenty = 0;
        for(int x : bills)
        {
            switch (x)
            {
            case 5:
                five++;
                break;
            case 10:
                if(five <= 0) return false;
                ten++;
                five--;
                break;
            case 20:
                if(five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }
                else if(five >= 3)
                {
                    five -= 3;
                }
                else return false;
                break;
            default:
                break;
            }
        }
        return true;
        
    }
};