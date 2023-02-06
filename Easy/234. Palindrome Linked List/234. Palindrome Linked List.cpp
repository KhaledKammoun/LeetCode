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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head ;
        ListNode* fast = head ;
        //find middle pointer using slow and fast pointers (slow)
        while (fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next ;
            slow = slow->next ;
        }
        //reverse seconde half
        ListNode* prev = nullptr ;
        while (slow!=nullptr){
            ListNode* tmp = slow->next ;
            slow->next = prev ;
            prev = slow ;
            slow = tmp ;
        }
        //check if le LinkedList is palindrome or not
        ListNode* left = head ;
        ListNode* right = prev;
        while (right!=nullptr){
            if (left->val!=right->val)
                return false ;
            left = left->next ;
            right = right->next ;
        }
        return true ;
    }
};