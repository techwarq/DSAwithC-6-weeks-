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

void printLL(Node* head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }

    
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;


}

int main() {
    // Sample array and value for insertion
    int arr[] = {12, 8, 5, 7};
    int val = 100;

    // Creating a linked list with initial elements from the array
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);

    // Inserting a new node at the head of the linked list
    head = insertHead(head, val);

    // Printing the linked list
    printLL(head);

    return 0;
}