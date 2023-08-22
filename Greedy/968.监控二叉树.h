#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



 struct TreeNode {
    int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution
{
    int result;
public:
    int minCameraCover(TreeNode *root)
    {
        
    }
    int traval(TreeNode* node)
    {
        /**
         * 0 无覆盖
         * 1 有摄象头
         * 2 有覆盖
         */
        if (!node) return 2;
        int left = traval(node->left);
        int right = traval(node->right);
        if(left == 0 || right == 0)
        {
            result++;
            return 1;
        }
        if(left == 2 || right == 2) return 0;
        if(left == 1 || right == 1) return 2;
    }
    
};