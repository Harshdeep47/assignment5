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
    cout<<"your list is"<<endl;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void countAndDelete(int key) {
    int count = 0;
    while(head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* curr = head;
    while(curr != NULL && curr->next != NULL) {
        if(curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else curr = curr->next;
    }
    cout << "Count: " << count << endl;
    display();
}

int main() {
    int n, val, key;
    cout<<"enter the size of list"<<endl;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> val;
        insertEnd(val);
    }
    cout<<"enter the key"<<endl;
    cin >> key;
    countAndDelete(key);
    return 0;
}

