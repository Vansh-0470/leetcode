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
         struct cmp{
         bool operator()(ListNode * a , ListNode * b){
    return a->val>b->val;
   }
         };
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(auto it :lists){
            if(it){
                pq.push(it);
            }
        }
        ListNode  *dummy=new ListNode(INT_MIN);
        ListNode * pre=dummy;
        while(!pq.empty()){
   ListNode * top=pq.top();
   pq.pop();
   pre->next=top;
   pre=pre->next;
   if(top->next){
    pq.push(top->next);
   }
        }
        return dummy->next;
//         vector<int>values;
//      for(int i = 0; i < lists.size(); i++) {
//     ListNode* temp = lists[i];

//     while(temp != NULL) {
//         values.push_back(temp->val);
//         temp = temp->next;
//     }
// }

// sort(values.begin(),values.end());
// if(values.size()==0)return NULL;
//           ListNode * head=new ListNode(values[0]);
//           ListNode * temp=head;
//           for(int i =1;i<values.size();i++){
//            temp->next=new ListNode(values[i]);
//            temp=temp->next;
//           }
//           temp->next=NULL;
//           return head;
    }
};