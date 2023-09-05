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
    unordered_map<TreeNode*,int> m ;
    unordered_map<int,int> t  ;
    void serialize_preorder(TreeNode* root ,string &s){
        if(!root){
            return  ;
        }
        m[root] = t[root->val] ;
        s = s + "#" + to_string(root->val) + "," + to_string(t[root->val]);
        t[root->val]++ ;
        serialize_preorder(root->left, s) ;
        serialize_preorder(root->right, s) ;
        
    }
    void serialize_inorder(TreeNode* root ,string &s){
        if(!root){
            return  ;
        }
        serialize_inorder(root->left, s) ;
        s = s + "#" + to_string(root->val) + "," + to_string(m[root]);
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
    std::vector<std::pair<int, int>> split(const std::string& s, char del = '#') {
        std::vector<std::pair<int, int>> numbers;
        std::istringstream ss(s);
        std::string token;

        // Split the input string by '#' to get pairs
        while (std::getline(ss, token, '#')) {
            if (!token.empty()) {
                std::istringstream pair_ss(token);
                std::string pair_token;
                std::vector<int> pair_values;

                // Split each pair by ',' to get the values
                while (std::getline(pair_ss, pair_token, ',')) {
                    int number;
                    std::istringstream(pair_token) >> number;
                    pair_values.push_back(number);
                }

                if (pair_values.size() == 2) {
                    numbers.push_back(std::make_pair(pair_values[0], pair_values[1]));
                }
            }
        }

        return numbers;
    }
   
    TreeNode* BuildNewTree(vector<pair<int,int>> &preorder, vector<pair<int,int>> &inorder, int preStart, int preEnd, int inStart, int inEnd){
        if (preStart > preEnd || inStart > inEnd)
            return nullptr ;
        TreeNode* root = new TreeNode(preorder[preStart].first);
        int mid = inStart;
        while (inorder[mid].second != preorder[preStart].second || inorder[mid].first != preorder[preStart].first)
            mid++;

        int leftSubtreeSize = mid - inStart;

    root->left = BuildNewTree(preorder, inorder, preStart + 1, preStart + leftSubtreeSize, inStart, mid - 1);
    root->right = BuildNewTree(preorder, inorder, preStart + leftSubtreeSize + 1, preEnd, mid + 1, inEnd);
        return root ;
    }
    TreeNode* deserialize(string data) {
        /*Convert The data string to a preorder and inorder array*/
        vector<pair<int,int>>preorder,inorder ;
        size_t pos = data.find('&');
        preorder = split(data.substr(0, pos)) ;
        inorder = split(data.substr(pos+1)) ;
        int n = preorder.size() ;
        
        TreeNode* root = nullptr ;
        
        return BuildNewTree(preorder, inorder, 0, n-1, 0, n-1) ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));