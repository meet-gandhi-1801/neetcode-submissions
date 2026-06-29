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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        if(lists.size() == 0) return nullptr;
        if(lists.size() == 1 && lists[0] == nullptr) return nullptr;
        while(1)
        {   int mini = 1e9;
            int index = 0;
            int sizi = 0;
            for(int i = 0;i<lists.size();i++)
            {
                if(!lists[i]) sizi++;
                else if(lists[i]->val < mini)
                {
                    mini = lists[i]->val;
                    index = i;
                }
            }
            if(sizi == lists.size()) break;
            temp->next = new ListNode(mini);
            temp = temp->next;

            lists[index] = lists[index]->next;
        }
        return dummy->next;
        
    }
};
