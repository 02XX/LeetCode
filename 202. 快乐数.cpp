#include"head.h"

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> mark;
        if(n == 1) return true;
        mark.insert(n);
        string num = to_string(n);
        while(num != "1")
        {
            int temp = 0;
            for(char x : num)
            {
                temp += (x-'0')*(x-'0');
            }
            if(mark.find(temp) != mark.end()) return false;
            else mark.insert(temp);
            num = to_string(temp);
        }
        return true;
    }
};