class Solution {
public:
    TreeNode* BuildNewTree(vector<int> &preorder, vector<int> &inorder, int preStart, int preEnd, int inStart, int inEnd){
        if (preStart > preEnd || inStart > inEnd)
            return nullptr ;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int mid = inStart;
            while (inorder[mid] != preorder[preStart])
                mid++;

        int leftSubtreeSize = mid - inStart;

    root->left = BuildNewTree(preorder, inorder, preStart + 1, preStart + leftSubtreeSize, inStart, mid - 1);
    root->right = BuildNewTree(preorder, inorder, preStart + leftSubtreeSize + 1, preEnd, mid + 1, inEnd);
        return root ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size() ;
        return BuildNewTree(preorder, inorder, 0,n-1, 0, n-1) ;
    }
};