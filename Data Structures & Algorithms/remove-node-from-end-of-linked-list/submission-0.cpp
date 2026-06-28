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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* t = head;
        if(!head) return nullptr;
        while(t)
        {
            size++;
            t = t->next;
        }
        t = head;
        if(size < n) return nullptr;
        int target = size - n;
        ListNode* prev = nullptr;
           if(target == 0)
        {
            head = head->next;
            delete t;
            return head;
        }

        for(int i = 0;i<target;i++)
        {
            prev = t;
            t = t->next;
        }

        prev->next = t->next;
        delete t;
        return head;

    }
};
