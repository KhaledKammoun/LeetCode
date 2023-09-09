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
        ostringstream out;
        serialize_(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize_(in);
    }

private:
    // Serialize the tree using preorder traversal
    void serialize_(TreeNode* root, ostringstream& out) {
        if (!root) {
            out << "# ";
            return;
        }

        out << to_string(root->val) << ' ';
        serialize_(root->left, out);
        serialize_(root->right, out);
    }

    // Deserialize the tree using a stringstream
    TreeNode* deserialize_(istringstream& in) {
        string token;
        in >> token;

        if (token == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserialize_(in);
        root->right = deserialize_(in);

        return root;
    }
};