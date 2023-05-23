#include <iostream>


struct Node{
    int value;
    Node* next;
};

class Stack {
private:
    Node *root;
public:
    Stack() : root(nullptr) {}

    void push(int value) {
        Node *newNode = new Node;
        newNode->value = value;
        newNode->next = root;
        root = newNode;
    }
    int pop (){
        if (isEmpty()){
            std::cout << "Error: Stack is empty." << std::endl;
            return -1;
        }

        int value = root->value;
        Node* temp = root;
        root = root->next;
        delete temp;
        return value;
    }
    int top(){
        if (isEmpty()){
            std::cout << "Error: Stack is empty." << std::endl;
            return -1;
        }
        return root->value;
    }
    bool isEmpty() const{
        return root == nullptr;
    }

    void printStack() const{
        Node* temp = root;
        std::cout << "Printing the stack: " << std::endl;
        if(temp){
            do {
                std::cout << " " << temp->value;
                temp = temp->next;
            } while (temp);
            std::cout << std::endl << std::endl;
        } else{
            std::cout << "Stack is empty. "<< std::endl << std::endl;
        }
    }
};
int main(){
    Stack stack;
    stack.push(10);
    stack.push(77);
    stack.push(99);

    stack.printStack();

    std::cout << "Top: " << stack.top() << std::endl;
    stack.pop();

    stack.printStack();

    return 0;
}