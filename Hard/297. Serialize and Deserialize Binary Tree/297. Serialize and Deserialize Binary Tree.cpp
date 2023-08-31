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
    void serialize_(TreeNode* root, int &len,string &s){
        if(!root){
            return  ;
        }
        len++ ;
        s = s + "#" + to_string(root->val) ;
        serialize_(root->left,len,s) ;
        serialize_(root->right,len,s) ;
        
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "" ;
        
        int l = 0,r = 0 ;
        string s_left = "", s_right = "" ;
        serialize_(root->left, l, s_left) ;
        serialize_(root->right, r, s_right) ;
        return "#" + to_string(l) + "#" + to_string(r) + "#" + to_string(root->val) + s_left + s_right ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));