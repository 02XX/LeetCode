#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int rob(TreeNode *root)
    {
        return robTravel(root)[0]; 
    }
    vector<int> robTravel(TreeNode *root)
    {
        if (!root) return {0,0};
        vector<int> left = robTravel(root->left);
        vector<int> right = robTravel(root->right);
        return {max(left[1]+right[1]+root->val,left[0]+right[0]), left[0]+right[0]};
    }
};