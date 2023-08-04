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
    void notgoodNodes(TreeNode* root, int &len, int &notgood, int &max_val) {
        if (!root)
            return;
        
        if (root->left && max_val > root->left->val)
            notgood++;
        if (root->right && max_val > root->right->val)
            notgood++;
        len++; 
        max_val = max(max_val, root->val) ;
        notgoodNodes(root->left, len, notgood, max_val);
        notgoodNodes(root->right, len, notgood, max_val);
    }

    int goodNodes(TreeNode* root) {
        if (!root)
            return 0;

        int len = 0, notgood = 0;
        notgoodNodes(root, len, notgood,root->val);
        return len - notgood;
    }
};
