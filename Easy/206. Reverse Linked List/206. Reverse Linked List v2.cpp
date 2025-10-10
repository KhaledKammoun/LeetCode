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

    ListNode* rec(ListNode* head, ListNode* prev) {
        if (head == nullptr) {
            return nullptr;
        }else if (head->next == nullptr) {
            head->next = prev ;
            return head ;
        }
        ListNode* result = rec(head->next, head) ;
        head->next = prev ;
        return result ;
    }  
    ListNode* reverseList(ListNode* head) {
        return rec(head, nullptr) ;
    }
};
