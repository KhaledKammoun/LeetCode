class Solution {
public:
    vector<int> subVector(const vector<int>& v, int s, int e) {
        vector<int> newV;
        if (s >= e || v.empty())
            return newV;
        for (int i = s; i < e; i++)
            newV.push_back(v[i]);
        return newV;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);
        int mid = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[0]) {
                mid = i;
                break;
            }
        }

        vector<int> subVect = subVector(preorder, 1, mid + 1);
        vector<int> subVect1 = subVector(inorder, 0, mid);
        root->left = buildTree(subVect, subVect1);

        subVect = subVector(preorder, mid + 1, preorder.size());
        subVect1 = subVector(inorder, mid + 1, inorder.size());
        root->right = buildTree(subVect, subVect1);

        return root;
    }
};
