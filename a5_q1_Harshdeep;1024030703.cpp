#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(int val) {
    cout<<"enter the number"<<endl;
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    cout<<"insertion succesfull"<<endl;
}

void insertAtEnd(int val) {
    cout<<"enter the number"<<endl;
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
    cout<<"insertion succesfull"<<endl;
}

void insertAfter(int key, int val) {
    cout<<"enter the number"<<endl;
    Node* temp = head;
    while(temp != NULL && temp->data != key) temp = temp->next;
    if(temp == NULL) return;
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
    cout<<"insertion succesfull"<<endl;
}

void insertBefore(int key, int val) {
    cout<<"enter the number"<<endl;
    if(head == NULL) return;
    if(head->data == key) {
        insertAtBeginning(val);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL && temp->next->data != key) temp = temp->next;
    if(temp->next == NULL) return;
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
    cout<<"insertion succesfull"<<endl;
}

void deleteBeginning() {
    if(head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
    cout<<"deletion succesfull"<<endl;
}

void deleteEnd() {
    if(head == NULL) return;
    if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != NULL) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
    cout<<"deletion succesfull"<<endl;
}

void deleteSpecific(int key) {
    if(head == NULL) return;
    if(head->data == key) {
        deleteBeginning();
        return;
    }
    Node* temp = head;
    while(temp->next != NULL && temp->next->data != key) temp = temp->next;
    if(temp->next == NULL) return;
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    cout<<"deletion succesfull"<<endl;
}

void search(int key) {
    Node* temp = head;
    int pos = 1;
    while(temp != NULL) {
        if(temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not found" << endl;
}

void display() {
    Node* temp = head;
    while(temp != NULL) {
        cout<<"your list is"<<endl;
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, val, key;
    while(true) {
        cout << "1.Insert at Beginning\n2.Insert at End\n3.Insert Before\n4.Insert After\n5.Delete Beginning\n6.Delete End\n7.Delete Specific\n8.Search\n9.Display\n10.Exit\n";
        cin >> choice;
        switch(choice) {
            case 1: cin >> val; insertAtBeginning(val); break;
            case 2: cin >> val; insertAtEnd(val); break;
            case 3: cin >> key >> val; insertBefore(key,val); break;
            case 4: cin >> key >> val; insertAfter(key,val); break;
            case 5: deleteBeginning(); break;
            case 6: deleteEnd(); break;
            case 7: cin >> key; deleteSpecific(key); break;
            case 8: cin >> key; search(key); break;
            case 9: display(); break;
            case 10: return 0;
        }
    }
}



