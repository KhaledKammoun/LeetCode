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
        if (!head || !head->next) {
            return nullptr ;
        }

        ListNode* node = new ListNode(0) ;
        node->next = head ;


        ListNode* slow = node ; 
        ListNode* fast = node ;

        while (fast) {
            fast = fast->next ;

            if (n == -1 ) {
                slow = slow->next ;
            } else {
            n-- ;
            }
        }
        slow->next = slow->next->next ;
        return node->next ;
    }
};
