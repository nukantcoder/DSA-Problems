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
   ListNode* merge(ListNode* left, ListNode* right) {
        
        ListNode*l1 = left;
        ListNode*l2 = right;
        ListNode*DummyNode = new ListNode(-1);
        ListNode*temp = DummyNode;

        while(l1 != NULL && l2 != NULL)
        {
            if(l1 -> val < l2 -> val)
            {
                temp -> next = l1;
                temp = l1;
                l1 = l1 -> next;
            }
            else
            {
                temp -> next = l2;
                temp = l2;
                l2 = l2 -> next;
            }
        }
        if(l1 == NULL)
        {
            temp -> next = l2;
        }
        else
        {
            temp -> next = l1;
        }
         return DummyNode -> next;
    }
ListNode*findmid(ListNode*head)
{
    ListNode*slow = head;
    ListNode*fast = head -> next;
    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
ListNode*mssort(ListNode* head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    ListNode*middle = findmid(head);
    ListNode*left = head;
    ListNode*right = middle -> next;
    middle -> next = NULL;

    left = mssort(left);
    right = mssort(right);

    return merge(left,right);
}
    ListNode* sortList(ListNode* head) {
        
     return mssort(head);
    }
};