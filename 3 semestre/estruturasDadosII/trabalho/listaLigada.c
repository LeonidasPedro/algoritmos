#include <iostream>

struct Node {
    int data;
    struct Node* next;

};

void printLinkedList(Node* head){
    struct Node* current = head;
    while (current != nullptr){
        std::cout << current.data << "";
        current = current->next;
    }
    std::cout << "\n";
}
