/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() :  val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s ;
        TreeNode* current = root ;
        while (current || !s.empty()){
            while (current){
                s.push(current) ;
                current = current->left ;
            }
            current = s.top() ;
            s.pop() ;
            if (--k==0)
                return current->val ;
            current = current->right ;
        }
        return -1 ;
    }
};