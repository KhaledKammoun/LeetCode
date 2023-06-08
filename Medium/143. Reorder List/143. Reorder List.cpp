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
        if (head==nullptr || head->next == nullptr)
            return head ;
        ListNode* x = reverseList(head->next) ;
        
        head->next->next = head ;
        head->next = nullptr ;
        return x ;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        ListNode* slow = head ;
        ListNode* fast = head ;
        while (fast->next && fast->next->next){
            slow = slow->next ;
            fast = fast->next->next ;
        }
        ListNode* List1 = head ;
        ListNode* List2 = slow->next ;
        slow->next = nullptr ;
        //revese List2
        List2 = reverseList(List2) ;
        ListNode* dummy = new ListNode();
        ListNode* x = dummy;
        while (List1 || List2){
            
            if (List1){
                x->next = List1 ;
                List1 = List1->next ;
                x = x->next ;
            }
            if (List2){
                x->next = List2 ;
                List2 = List2->next ;
                x = x->next ;
            }
        }
        head = dummy->next ;
        delete dummy ;
    }
};