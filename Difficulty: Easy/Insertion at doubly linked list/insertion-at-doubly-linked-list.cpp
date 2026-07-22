/*
class Node {
	public:
	int data;
	Node* next;
	Node* prev;
	
	Node(int x) {
		data = x;
		next = prev = nullptr;
	}
};
*/

class Solution {
	public:
	Node *insertAtPos(Node *head, int p, int x) {
		// code here
		Node* node = new Node(x);
		Node* temp = head;
		while (p) {
			temp = temp->next;
			p--;
		}
		if(temp->next == NULL){
		    temp->next = node;
		    node->prev = temp;
		    node->next = NULL;
		}
		else {
			node->prev = temp;
			node->next = temp->next;
			temp->next->prev = node;
			temp->next = node;
		}
		
		return head;
	}
};
