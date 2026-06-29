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
    pair<bool,int> solve(TreeNode* root)
    {
        if(!root) return {true,0};
        pair<bool,int> left,right,ans;
        left = solve(root->left);
        right = solve(root->right);
        ans.second = 1 + max(left.second,right.second);
        ans.first = left.first && right.first && (abs(left.second - right.second) <2);
        return ans;
    }
    bool isBalanced(TreeNode* root) {

        return solve(root).first;
        
        
    }
};
