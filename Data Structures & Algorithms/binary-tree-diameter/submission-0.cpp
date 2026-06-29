/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    pair<int,int> solve(TreeNode* root)
    {
        if(!root) return {0,0};

        pair<int,int> ans,left,right;
        left = solve(root->left);
        right = solve(root->right);
        ans.second = 1 + max(left.second,right.second);
        ans.first = max(left.first,max(right.first,left.second + right.second));
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return solve(root).first;
    }
};
