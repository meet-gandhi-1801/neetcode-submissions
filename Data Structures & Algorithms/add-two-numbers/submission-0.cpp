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
        ListNode* dummy = new ListNode(-1);
        ListNode* t = dummy;
        int sum = 0,carry=0;
        while(l1 || l2)
        {
            sum =  0;
            if(l1) sum += l1->val;
            if(l2) sum += l2->val;
            sum +=carry;
            if(sum > 9) 
            {
                carry = sum / 10;
                sum -= carry*10;
            }
            else carry = 0;
ListNode* tempi = new ListNode(sum);            t->next = tempi;
            t = tempi;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry) 
        {
            ListNode* tempi = new ListNode(carry);
            t->next = tempi;
        }
        return dummy->next;
        
    }
};
