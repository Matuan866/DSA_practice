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
    void reorderList(ListNode* head) {
        ListNode* slowptr=head;
        ListNode* fastptr=head;

        while(fastptr!=nullptr&&fastptr->next!=nullptr){
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
        }
        ListNode* second_half=slowptr->next;
        slowptr->next=nullptr;
        ListNode* prev_second_half=nullptr;
        ListNode* next_second_half=nullptr;
        while(second_half!=nullptr){
            next_second_half=second_half->next;
            second_half->next=prev_second_half;
            prev_second_half=second_half;
            second_half=next_second_half;
        }

        ListNode* first_half=head;
        second_half=prev_second_half;
        
        while(first_half!=nullptr&&second_half!=nullptr){
            ListNode* tmp1=first_half->next;
            ListNode* tmp2=second_half->next;

            first_half->next=second_half;
            second_half->next=tmp1;

            first_half=tmp1;
            second_half=tmp2;
        }
    }
};
