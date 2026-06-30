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
        if(!root) return{INT_MIN,INT_MIN};
        pair<int,int> ans,l,r;
        l = solve(root->left);
        r = solve(root->right);
        ans.first = max(l.first,max(r.first,root->val + max(0,l.second) + max(0,r.second)));
        ans.second = root->val + max(0,max(l.second,r.second));
        return ans;

    }
    int maxPathSum(TreeNode* root) {
        return solve(root).first;
    }
};
