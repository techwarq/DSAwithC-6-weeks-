#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor with only data, next pointer is set to null
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node(newData);
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void insertInMiddle(Node*& head, int newData, int position) {
    Node* newNode = new Node(newData);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void freeList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

int main() {
    int n;
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

    // Insert a new node at the beginning
    int newData;
    cout << "Enter the data for the new node to be inserted at the beginning: ";
    cin >> newData;
    insertAtBeginning(head, newData);
    printList(head);

    // Insert a new node at the end
    cout << "Enter the data for the new node to be inserted at the end: ";
    cin >> newData;
    insertAtEnd(head, newData);
    printList(head);

    // Insert a new node in the middle
    int position;
    cout << "Enter the position to insert the new node in the middle: ";
    cin >> position;
    cout << "Enter the data for the new node to be inserted in the middle: ";
    cin >> newData;
    insertInMiddle(head, newData, position);
    printList(head);

    // Free the allocated memory
    freeList(head);

    return 0;
}
