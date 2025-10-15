/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int listLength = 0 ;

        ListNode* node_var = head ; 
        while (node_var) {
            node_var = node_var->next ;
            listLength++ ;
        }

        if (listLength <= 1) {
            return nullptr ;
        }

        ListNode* node = new ListNode(5);
        node->next = head ; 
        int index = listLength - n ;
     
        node_var = node ; 
        while (index > 0) {
            node_var = node_var->next ;
            index-- ;
        }

        node_var->next = node_var->next->next ;
        return node->next ;
        
    }
};
