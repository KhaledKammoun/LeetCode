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
    void notgoodNodes(TreeNode* root, int &good,  int max_val,bool test) {
        if (!root)
            return;
        else if (root->val>=max_val){
            good++ ;
            max_val = max(max_val, root->val) ;
        }
        notgoodNodes(root->left, good, max_val,test);
        notgoodNodes(root->right, good, max_val, test);
    }

    int goodNodes(TreeNode* root) {
        if (!root)
            return 0;
        int good = 0 ;
        notgoodNodes(root, good ,root->val, true);
        return good;
    }
};
