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
        Node* head_copy = new Node(0) ;
        Node* head_copy_var = head_copy ;
        Node*x = head ;
        while (x!=nullptr){
            Node* new_Node = new Node(0) ;
            new_Node->val = x->val ;
            new_Node->next = nullptr ;
            new_Node->random = nullptr ;
            head_copy_var->next = new_Node ;
            nodeMap[x] = new_Node ;
            x = x->next ;
            head_copy_var = head_copy_var->next ;
        }
        head_copy = head_copy->next ;
        head_copy_var = head_copy ;
        x = head ;
        while (x!=nullptr){
            head_copy_var->random = nodeMap[x->random] ;
            head_copy_var = head_copy_var->next ;
            x = x->next ; 
        }
        return head_copy ;
    }
};