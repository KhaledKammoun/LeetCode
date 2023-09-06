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
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> q;
        q.push(root) ;
        bool allNullPtr = false ;
        while(!allNullPtr){
            allNullPtr = true ;
            int n = q.size() ;
            for (int i = 0 ; i<n ; i++){
                if (q.front()){
                    s+= "#" + to_string(q.front()->val) ;
                    q.push(q.front()->left) ;
                    q.push(q.front()->right) ;
                    if (q.front()->right || q.front()->left)
                        allNullPtr = false ;
                }
                else{
                    s+= "#n" ;
                }
                q.pop() ;
            }
            
        }
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
        queue<TreeNode*>q ;
        TreeNode* root = new TreeNode(v[0]) ;
        q.push(root) ;
        for (int i = 1 ; i<v.size()-1 ; i+=2){
            TreeNode* node = (v[i]!=1001) ? new TreeNode(v[i]) : nullptr ;
            q.front()->left = node ;
            if (node!=nullptr)
                q.push(node) ;
            node = (v[i+1]!=1001) ? new TreeNode(v[i+1]) : nullptr ;
            q.front()->right = node ;
            if (node!=nullptr)
                q.push(node) ;
            q.pop() ;
        }
        return root ;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));