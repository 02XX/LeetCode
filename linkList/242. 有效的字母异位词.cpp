#include"head.h"
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> Map;
        for(char x : s)
        {
            if(Map.find(x) == Map.end()) Map[x] = 1;
            else Map[x]++;
        }
        for(char x : t)
        {
            if(Map.find(x) == Map.end()) Map[x] = 1;
            else Map[x]--;
        }
        for(auto x : Map)
        {
            if(x.second != 0) return false;
        }
        return true;

    }
};