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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode*t1 = l1;
        ListNode*t2 = l2;
        ListNode*dnode = new ListNode(-1);
        ListNode*temp = dnode;
        
        int sum;
        int carry = 0;
        while(t1 != NULL && t2 != NULL)
        {
        sum = carry;
           sum = sum + t1 -> val + t2 -> val;
           ListNode*current = new ListNode(sum % 10);
           carry = sum / 10;

           temp -> next = current;
           temp = current;

           t1 = t1 -> next;
           t2 = t2 -> next;
        }

        while(t1 != NULL)
        {
            sum = carry;
            sum = sum + t1 -> val;
            ListNode*current = new ListNode(sum % 10);
           carry = sum / 10;

           temp -> next = current;
           temp = current;
           t1 = t1 -> next;

        }
        while(t2 != NULL)
        {
            sum = carry;
            sum = sum + t2 -> val;
            ListNode*current = new ListNode(sum % 10);
           carry = sum / 10;

           temp -> next = current;
           temp = current;
           t2 = t2 -> next;
        }

        if(carry != 0)
        {
            ListNode*lastnode = new ListNode(carry);
            temp -> next = lastnode;
        }

        return dnode -> next;

    }
};