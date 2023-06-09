class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        for (int i = 0 ; i<=n ; i++){
            fast = fast->next ;
        }
        while (fast != nullptr){
            slow = slow->next ;
            fast = fast->next ;
        }
        ListNode* temp = slow->next ;
        slow->next = slow->next->next ;
        head = dummy->next ;
        delete temp ;
        delete dummy ;
        return head ;
    }
};