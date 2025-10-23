#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void findMiddle() {
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow != NULL){
	 cout <<"middle of list is:"<< slow->data << endl;
   }
}

int main() {
    int n, val;
    cout<<"enter the size of list"<<endl;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> val;
        insertEnd(val);
    }
	findMiddle();
    return 0;
}

