#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    newNode->next = head;
    head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    cout << "Linked list: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteTail(Node* head ){
    if (head == nullptr){
        cout << "List is empty" << endl;
        return;
    }

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr ){
        temp = temp->next;

    }
    delete temp->next;
    temp->next = nullptr;
}

void deleteAtPostion(int position, Node* head){
    if (head == nullptr){
        cout << "List is empy" << endl;
        return;

    }

    if(position == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
     Node* temp = head;
        for (int i = 0; temp != nullptr && i < position - 1; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range." << endl;
            return;
        }

        Node* next = temp->next->next;
        delete temp->next;
        temp->next = next;
    };


void freeList(Node*& head) {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
}

int main() {
    int n, choice, position;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of elements should be greater than 0." << endl;
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < n; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    printList(head);

    cout << "Enter 1 to delete tail, 2 to delete at position: ";
    cin >> choice;

    if (choice == 1){
        deleteTail(head);
    }

    else if (choice == 2){
        cout << "Enter the position to delete: ";
        cin >> position;
        deleteAtPostion(position, head);

    }
    else {
        cout << "Invalid choice" << endl;
    }

    cout << "Updated List: ";
    printList(head);

    
    

    return 0;
}
