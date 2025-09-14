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

void display() {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverse() {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    cout<<"reversed list:"<<endl;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    int n, val;
    cout<<"enter the size of the list"<<endl;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> val;
        insertEnd(val);
    }
    reverse();
    display();
    return 0;
}
