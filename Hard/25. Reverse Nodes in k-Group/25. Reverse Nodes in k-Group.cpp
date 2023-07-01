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
    ListNode* reverseLinkedList(ListNode* first, ListNode* last) {
        ListNode* prev = nullptr ;
        ListNode* curr = first ;
        while (curr != last){
            ListNode* next = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = next ;
        }
        last->next = prev ;
        return last ;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k<=1)
            return head ;
        int n=0 ;
        ListNode* node = head ;
        while (node){
            n++ ;
            node = node->next ;
        }
        int x = 1 ;
        ListNode* dummy = new ListNode(0,head) ;
        ListNode* prev = dummy ;
        ListNode* first_node = head ;
        ListNode* last_node = head ;
        while (last_node && x<=k*(n/k)){
            if(x%k==0){
                ListNode* next_node = last_node->next ;
                ListNode* result = reverseLinkedList(first_node, last_node) ;
                last_node = first_node ;
                last_node->next = next_node ;
                first_node = next_node ;
                prev->next = result ;
                prev = last_node ;
            }

            last_node = last_node->next;
            x++ ;
        }
        return dummy->next  ;
    }   
};