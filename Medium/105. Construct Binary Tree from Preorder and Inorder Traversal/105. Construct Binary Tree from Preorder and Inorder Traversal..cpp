class Solution {
public:
    vector<int> subVector(vector<int>v, int start, int end){
        vector<int> newVec ;
        for (int i = start ; i<end ; i++)
            newVec.push_back(v[i]) ;
        return newVec ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size() || !inorder.size())
            return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);
        
        int mid = 0;
        for (mid = 0; mid < inorder.size(); mid++) {
            if (inorder[mid] == preorder[0])
                break;
        }
        
        root->left = buildTree(
            subVector(preorder,1, mid + 1),
            subVector(inorder, 0,mid)
        );
        
        root->right = buildTree(
            subVector(preorder, mid + 1,preorder.size()),
            subVector(inorder,mid,inorder.size())
        );
        
        return root;
    }
};
