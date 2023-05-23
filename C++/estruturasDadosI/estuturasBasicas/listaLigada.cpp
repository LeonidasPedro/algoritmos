#include <iostream>

struct Node{
    int data;
    Node* next;
};

void printList(Node* head){
    Node* current = head;
    while(current){
        std::cout << current->data << " ";
        current = current-> next;
    }
    std::cout << std::endl;
}

void insertAtBegining(Node*& head, int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

int main(){
    Node* head = nullptr;

    insertAtBegining(head, 5);
    insertAtBegining(head, 10);
    insertAtBegining(head, 15);

    std::cout << "Lista ligada: ";
    printList(head);
    return 0;
}