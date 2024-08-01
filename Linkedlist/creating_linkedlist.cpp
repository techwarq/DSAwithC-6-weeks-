#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;   // the data value
    Node* next; // the pointer to the next value

    // Constructor with both data and next node pointer
    Node(int data1, Node* next1) {
        data = data1;  // Initialize data with the provided value
        next = next1;  // Initialize next with the provided value
    }

    // Constructor with only data, next pointer is set to null
    Node(int data1) {
        data = data1;  // Initialize data with the provided value
        next = nullptr;  // Initialize next as null since it's the end of the list
    }
};

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
