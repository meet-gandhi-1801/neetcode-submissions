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

class Codec {
public:



    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int k = q.size();
            while(k--)
            {
                TreeNode* t = q.front();
                q.pop();
                if(t == nullptr) 
                {ans += "*," ;continue;}
                ans += to_string(t->val) + ",";
                if(t->left) q.push(t->left);
                else q.push(nullptr);
                if(t->right) q.push(t->right);
                else q.push(nullptr);
            }
            
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;
        int index = 0;
        queue<TreeNode*> q;
        string num = "";
        while(data[index] != ',') num += data[index++];
        TreeNode* root = new TreeNode(stoi(num));
        TreeNode* ans = root;
        index++;
        q.push(root);
        while(index < data.size() && !q.empty())
        {
            TreeNode* t = q.front();
            q.pop();
            num = "";
            if(data[index] == '*') index+=2;
            else
            {
                while(data[index] != ',') num += data[index++];
                t->left = new TreeNode(stoi(num));
                q.push(t->left);
                index++;            
            }
            num = "";
            if(data[index] == '*') index+=2;
            else
            {
                while(data[index] != ',') num += data[index++];
                t->right = new TreeNode(stoi(num));
                q.push(t->right);
                index++;            
            }
        }
        return ans;
    }
};
