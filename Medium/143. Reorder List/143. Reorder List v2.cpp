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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* result = reverseList(head->next) ;
        head->next->next = head ;
        head->next = nullptr ;
        return result ;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2 ;
        if (!list2) return list1 ;

        ListNode* head = list1  ;
        
        ListNode* curr1 = head ;
        ListNode* curr2 = list2 ;
        while (curr1 && curr2) {
            ListNode* next1 = curr1->next ;
            ListNode* next2 = curr2->next ;

            curr1->next = curr2 ;
            if (next1 == nullptr) {
                break ;
            }
            curr2->next = next1 ;

            curr1 = next1 ;
            curr2 = next2 ;
        }
        return head ;
      
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return ;
        }

        // Find middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;

        slow->next = nullptr;

        // Reverse the second list (head2)
        head2 = reverseList(head2) ;

        // Merge head with head2
        head = mergeTwoLists(head, head2) ;

    }
};
