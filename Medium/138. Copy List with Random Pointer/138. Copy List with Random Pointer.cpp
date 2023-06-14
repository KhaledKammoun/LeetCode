/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> nodeMap;
        Node*x = head ;
        while (x!=nullptr){
            Node* new_Node = new Node(0) ;
            new_Node->val = x->val ;
            nodeMap[x] = new_Node ;
            x = x->next ;
        }
        x = head ;
        while (x!=nullptr){
            Node* copy_node = nodeMap[x] ;
            copy_node->random = nodeMap[x->random] ;
            copy_node->next = nodeMap[x->next] ;
            x = x->next ; 
        }
        return nodeMap[head] ;
    }
};