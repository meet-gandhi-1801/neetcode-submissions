class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        TreeNode* curr = root;

        while(curr)
        {
            if(!curr->left)
            {
                count++;
                if(count == k) return curr->val;
                curr = curr->right;
            }
            else
            {
                TreeNode* prev = curr->left;

                while(prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }

                if(!prev->right)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = nullptr;
                    count++;
                    if(count == k) return curr->val;
                    curr = curr->right;
                }
            }
        }
        return -1;
    }
};