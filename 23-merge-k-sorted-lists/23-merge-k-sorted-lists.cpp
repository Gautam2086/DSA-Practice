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
        vector<int> v;
        int n= lists.size();
        
        for(int i=0; i<n; i++) 
        {
            ListNode* head= lists[i];
            while(head) {
                v.push_back(head->val);
                head= head->next;
            }
        }
        sort(v.begin(), v.end());
        
        ListNode*  temp= new ListNode(0);
        ListNode* head2= temp;
        
        for(int i=0; i<v.size(); i++) {
            temp->next= new ListNode(v[i]);
            temp= temp->next;
        }
        return head2->next;
    }
};