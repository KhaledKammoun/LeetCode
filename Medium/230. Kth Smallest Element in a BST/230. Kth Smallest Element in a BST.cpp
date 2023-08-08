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
    void findKth(TreeNode* root, int &k,int &kthVal){
        if (k<=0 || !root)
            return ;
        findKth(root->left,k,kthVal) ;
        k-- ;
        if (k==0){
            kthVal = root->val ; 
            return ;
        }
        findKth(root->right,k,kthVal) ;   
    }
    int kthSmallest(TreeNode* root, int &k) {
        int kthVal = -1 ;
        findKth(root, k, kthVal) ;
        return kthVal ;
    }
};