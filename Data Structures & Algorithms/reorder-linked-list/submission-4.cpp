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
private:
    ListNode* getMiddlePtr(ListNode* head){
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* reversedList(ListNode* head){
        if(head==nullptr) return head;

        ListNode* prev=nullptr;
        ListNode* next=nullptr;
        ListNode* curr=head;

        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
        
    }

    void mergeList(ListNode* lst1, ListNode* lst2){
        if(lst1==nullptr||lst2==nullptr) return ;

        ListNode* l1=lst1;
        ListNode* l2=lst2;

        while(l1!=nullptr&&l2!=nullptr){
            ListNode* tmp1=l1->next;
            ListNode* tmp2=l2->next;

            l1->next=l2;
            l2->next=tmp1;

            l1=tmp1;
            l2=tmp2;
        }
    }
public:
    void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return ;

        ListNode* middleNode=getMiddlePtr(head);
        ListNode* l2=middleNode->next;
        l2=reversedList(l2);
        middleNode->next=nullptr;

        mergeList(head, l2);
    }
};
