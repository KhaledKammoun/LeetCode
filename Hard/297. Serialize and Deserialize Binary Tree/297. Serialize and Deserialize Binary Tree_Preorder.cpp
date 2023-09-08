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
            s = s + "#n" ;
            return  ;
        }
        s = s + "#" + to_string(root->val) ;
        serialize_preorder(root->left, s) ;
        serialize_preorder(root->right, s) ;
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "" ;
        serialize_preorder(root,s) ;
        return s ;
    }
    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
        std::string token;
        getline(ss, token, '#');
        getline(ss, token, '#');
        if (token=="n")
            return nullptr; 
        int number;
        std::istringstream(token) >> number;
        stack<TreeNode*>s ;
        TreeNode* root = new TreeNode(number) ;
        s.push(root) ;
        string prev = token ;
        while (std::getline(ss, token, '#')) {
            TreeNode* node ;
            if (token!="n"){
                std::istringstream(token) >> number;
                node = new TreeNode(number) ;
            }
            else{
                node = nullptr ;
            }
            if (prev=="n"){
                s.top()->right = node ;
                s.pop() ;
            }
            else
                s.top()->left = node ;
            if (node)
                s.push(node) ;
            prev = token ;
        }
        return root ;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));