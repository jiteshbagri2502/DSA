/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // code here
        head = reverse(head);
        Node* curr = head;
        int carry = 1;
        Node* prev = nullptr;
        
        while(curr != nullptr){
            int sum = curr->data + carry;
            curr->data = sum%10;
            carry = sum/10;
            prev = curr;
            curr = curr->next;
            
            if(carry == 0)break;
        }
        
        if(carry > 0){
                prev->next = new Node(carry);
        }
        
        
        
        return reverse(head);
        
        
        
        
        
        
        
        
        
    }
};