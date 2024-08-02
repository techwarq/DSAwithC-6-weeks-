 //We need to insert the value 5 before the head of the given Linked List.

 #include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

void insertAtBeginnning(Node*& head, int newData){
    Node* newNode = new Node(newData);

    newNode->next = head;

    head = newNode;
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

    // Insert a new node at the beginning
    int newData;
    cout << "Enter the data for the new node to be inserted at the beginning: ";
    cin >> newData;
    insertAtBeginnning(head, newData);

    // Print the linked list
    current = head;
    cout << "Linked list: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Free the allocated memory
    current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    return 0;
}