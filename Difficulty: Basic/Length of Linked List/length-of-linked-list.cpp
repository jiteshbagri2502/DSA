/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        Node* temp = head;
        int count = 1;
        while(temp->next != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
};