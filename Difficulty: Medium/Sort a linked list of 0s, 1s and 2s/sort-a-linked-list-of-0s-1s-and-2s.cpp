/* Node is defined as
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
    Node* segregate(Node* head) {
        // code here
        unordered_map<int,int> mp;
        vector<int> vec;
        Node* temp = head;
        while(temp != NULL){
            if(mp[temp->data] == 0){
                vec.push_back(temp->data);
            }
            mp[temp->data]++;
            temp = temp->next;
        }
        temp = head;
        sort(vec.begin(),vec.end());
        for(auto it: vec){
            while(mp[it] != 0){
                temp->data = it;
                mp[it]--;
                temp = temp->next;
            }
        }
        return head;
    }
};