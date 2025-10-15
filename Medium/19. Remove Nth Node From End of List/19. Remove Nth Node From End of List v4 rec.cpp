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

    int rec(ListNode* node, int n) {
        if (!node) {
            return 0 ;
        }
        int index = rec(node->next, n) ;

        if (index == n ) {
            node->next = node->next->next ;
        }
        return index + 1 ;

    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) {
            return nullptr ;
        }

        ListNode* node = new ListNode(0) ;
        node->next = head ; 
       int result =  rec(node, n) ;

        return node->next ;
    }
};
