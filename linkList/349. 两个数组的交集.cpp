#include"head.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mapping1,mapping2;
        vector<int> result;
        for(int x : nums1)
        {
            mapping1[x]++;
        }
        for(int x : nums2)
        {
            mapping2[x]++;
        }
        for(auto x : mapping1)
        {
            if(mapping2.find(x.first) != mapping2.end()) result.push_back(x.first);
        }
        return result;
    }
};