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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode*temp=head;
        vector<int>smaller;
        vector<int>greater;
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                smaller.push_back(temp->val);
            }
            else
            {
                greater.push_back(temp->val);
            }
            
            temp= temp->next;
        }
        
       temp=head;
        
      for(auto it:smaller)
      {
          // if(temp==NULL)
          // {
          //     break;
          // }
          temp->val=it;
          temp=temp->next;
          
      }
        
         for(auto it:greater)
      {
          // if(temp==NULL)
          // {
          //     break;
          // }
          temp->val=it;
          temp=temp->next;
          
      }
        
        return head;
        
        
        
    
        
    }
};