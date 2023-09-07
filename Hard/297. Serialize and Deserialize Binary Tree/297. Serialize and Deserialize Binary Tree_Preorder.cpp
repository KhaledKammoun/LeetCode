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
    vector<int> split(string s, char del ='#')
    {
        vector<int> numbers ;
        std::stringstream ss(s);
        std::string token;
    
        // Iterate through the stringstream and extract integers
        while (std::getline(ss, token, del)) {
            if (!token.empty()) {
                if (token == "n") {
                    numbers.push_back(1001); // Replace "n" with 1001
                } else {
                    int number;
                    std::istringstream(token) >> number;
                    numbers.push_back(number);
                }
            }
        }
        return numbers;
    }
    TreeNode* deserialize(string data) {
        vector<int>v ;
        v = split(data) ;
        if (v[0]==1001)
            return nullptr; 
        stack<TreeNode*>s ;
        TreeNode* root = new TreeNode(v[0]) ;
        s.push(root) ;
        int n = v.size() ;
        for (int i = 1 ; i<n ; i++){
            if (v[i]==1001 && (v[i+1]!=1001 || i+1>n)){
                while (!s.empty()){
                    TreeNode* node = (v[i]!=1001) ? new TreeNode(v[i]) : nullptr ;
                    s.top()->right = node ;
                    if (i<n && v[i]!=1001) // i<n && node != nullptr
                        s.push(node) ;
                    i++ ;
                    s.pop() ;
                }
            }
            
            else{
                TreeNode* node = (v[i]!=1001) ? new TreeNode(v[i]) : nullptr ;
                s.top()->left = node ;
            }
            TreeNode* node = (v[i]!=1001) ? new TreeNode(v[i]) : nullptr ;
            if (i<n && v[i]!=1001)
                s.push(node) ;
        }
        return root ;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));