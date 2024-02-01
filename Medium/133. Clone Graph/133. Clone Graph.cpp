/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return node ;
        stack<Node*> s ;
        unordered_map<Node*, Node*> m ;
        bool visited[101] = {false} ;
        Node* root = new Node(node->val) ;
        s.push(node) ;
        m[node] = root ;
        visited[node->val] = true ;
        while (!s.empty()){
            Node* var = s.top() ;
            s.pop() ;
            for (Node* node_var : var->neighbors){
                
                if (!visited[node_var->val]){
                    Node* node_var_new = new Node(node_var->val) ;
                    m[node_var] = node_var_new ;
                    s.push(node_var) ;
                    visited[node_var->val] = true ;
                }
                
                m[var]->neighbors.push_back(m[node_var]) ;
            }
        }
        return root ;
    }
};