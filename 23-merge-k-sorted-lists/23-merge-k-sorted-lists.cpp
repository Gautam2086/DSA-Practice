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

// Brute force way: make vector and sort it
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> v;
        int n= lists.size();
        
        for(int i=0; i<n; i++) {
            ListNode* head= lists[i];
            
            while(head != NULL) {
                v.push_back(head->val);
                head= head->next;
            }
        }
        
        sort(v.begin(), v.end());
        
        ListNode* h= new ListNode(0);
        ListNode* tail= h;
        
        for(int i=0; i<v.size(); i++) {
            tail->next= new ListNode(v[i]);
            tail= tail->next;
        }
        
        return h->next;
    }
};