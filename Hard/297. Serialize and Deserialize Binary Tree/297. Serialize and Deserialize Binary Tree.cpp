/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serialize_preorder(TreeNode* root ,string &s){
        if(!root){
            return  ;
        }
        s = s + "#" + to_string(root->val) ;
        serialize_preorder(root->left, s) ;
        serialize_preorder(root->right, s) ;
        
    }
    void serialize_inorder(TreeNode* root ,string &s){
        if(!root){
            return  ;
        }
        serialize_inorder(root->left, s) ;
        s = s + "#" + to_string(root->val) ;
        serialize_inorder(root->right, s) ;
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "" ;
        string preorder  = "" ;
        string inorder = "" ;
        serialize_preorder(root,preorder) ;
        serialize_inorder(root,inorder) ;
        return preorder + "&" + inorder ;
    }
    vector<int> split(string s, char del ='#')
    {
        vector<int> numbers ;
        std::stringstream ss(s);
        std::string token;
    
        // Iterate through the stringstream and extract integers
        while (std::getline(ss, token, del)) {
            if (!token.empty()) {
                int number;
                std::istringstream(token) >> number;
                numbers.push_back(number);
            }
        }
        return numbers ;
    }
   
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
    TreeNode* deserialize(string data) {
        /*Convert The data string to a preorder and inorder array*/
        vector<int>preorder,inorder ;
        size_t pos = data.find('&');
        preorder = split(data.substr(0, pos)) ;
        inorder = split(data.substr(pos+1)) ;
        TreeNode* root = nullptr ;
        int n = preorder.size() ;
        return BuildNewTree(preorder, inorder, 0, n-1, 0, n-1) ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));