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
    void notgoodNodes(TreeNode* root, int &good,  int max_val) {
        if (!root)
            return;
        else if (root->val>=max_val){
            good++ ;
            max_val = max(max_val, root->val) ;
        }
        notgoodNodes(root->left, good, max_val);
        notgoodNodes(root->right, good, max_val);
    }

    int goodNodes(TreeNode* root) {
        if (!root)
            return 0;
        int good = 0 ;
        notgoodNodes(root, good ,root->val);
        return good;
    }
};
/*Second_Method*/

class Solution {
public:
    int notgoodNodes(TreeNode* root,  int max_val) {
        if (!root)
            return 0 ;
        max_val = max(max_val, root->val) ;
        return ((root->val>=max_val) ? 1 : 0) + notgoodNodes(root->left, max_val) + notgoodNodes(root->right, max_val);
    }

    int goodNodes(TreeNode* root) {
        if (!root)
            return 0;
        return notgoodNodes(root, root->val);
    }
};