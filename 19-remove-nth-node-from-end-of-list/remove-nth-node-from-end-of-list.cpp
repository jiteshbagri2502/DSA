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
        ListNode* temp = head;
        for(int i = 0; i < n; i++){
            temp = temp->next;
        }
        if(!temp){
            return head->next;
        }
        ListNode* temp1 = head;
        while(temp->next != NULL){
            temp1 = temp1->next;
            temp = temp->next;
        }
        temp1->next = temp1->next->next;
        return head;
    }
};