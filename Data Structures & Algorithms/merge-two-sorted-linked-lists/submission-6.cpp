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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* Dummy=new ListNode(0);
        ListNode* tail=Dummy;
        while(list1!=nullptr&&list2!=nullptr){
            int val1=list1->val;
            int val2=list2->val;
            if(val1<val2){
                tail->next=list1;
                list1=list1->next;
            }
            else{
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;
        }
        if(list1!=nullptr) tail->next=list1;
        if(list2!=nullptr) tail->next=list2;
        
        ListNode* res=Dummy->next;
        delete Dummy;
        return res;
        
    }
};
