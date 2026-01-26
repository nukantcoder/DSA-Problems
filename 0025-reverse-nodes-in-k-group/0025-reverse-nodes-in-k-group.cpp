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
ListNode*reverse(ListNode*temp)
{
    ListNode*temp1 = temp;
    ListNode*prev = NULL;
    while(temp1 != NULL)
    {
        ListNode*next = temp1 -> next;
        temp1 -> next = prev;
        prev = temp1;
        temp1 = next;
    }
    return prev;
}
ListNode*findKNode(ListNode* temp, int k)
{
    ListNode*K = temp;
    int count = 1;
    while(K != NULL)
    {
        if(count == k)
        {
            return K;
        }
        else
        {
            count++;
            K = K -> next;
        }
    }
    return NULL;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode*temp = head;
        ListNode*prev = NULL;
        int grp = 0;
        while(temp != NULL)
        {
            ListNode*Kth = findKNode(temp,k); 
            if(temp == head)
            {
                head = Kth;
            }
            if(Kth == NULL)
            {
               if(prev != NULL)
               {
                 prev -> next = temp;
               }
               break;
            }
            ListNode*next = Kth -> next;
            Kth -> next = NULL;
            ListNode*rev = reverse(temp);
            
            grp++;
            if(grp == 1)
            {
                prev = temp;
                temp = next;
            }
            else
            {
                prev -> next = Kth;
                prev = temp;
                temp = next;
            }
        }
        return head;
    }
    
};