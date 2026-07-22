/* Structure of doubly linked list node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* curr = head;
        Node* last = NULL;
        while(curr != NULL){
            last = curr->prev;
            curr->prev = curr->next;
            curr->next = last;
            curr = curr->prev;
        }
        return head = last->prev;
    }
};