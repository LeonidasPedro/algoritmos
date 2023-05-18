#include <iostream>

using namespace std;

// Definicao da estrutura do no
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Funcao para criar um novo no
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Funcao para inserir um novo no na arvore
void insertNode(Node*& root, int data) {
    if (root == nullptr) {
        root = createNode(data);
    }
    else if (data < root->data) {
        insertNode(root->left, data);
    }
    else {
        insertNode(root->right, data);
    }
}

// Funcao para imprimir a arvore no formato desejado
void printTree(Node* root) {
    if (root != nullptr) {
        cout << root->data << endl;
        if (root->left != nullptr || root->right != nullptr) {
            if (root->left != nullptr) {
                cout << root->left->data << " ";
            }
            else {
                cout << "- ";
            }
            if (root->right != nullptr) {
                cout << root->right->data << endl;
            }
            else {
                cout << "-\n";
            }
            printTree(root->left);
            printTree(root->right);
        }
    }
}

// Funcao para buscar um valor especifico na arvore
Node* searchNode(Node* root, int data) {
    if (root == nullptr || root->data == data) {
        return root;
    }
    else if (data < root->data) {
        return searchNode(root->left, data);
    }
    else {
        return searchNode(root->right, data);
    }
}

// Funcao para imprimir a arvore em pre-ordem
void printPreOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// Funcao para imprimir a arvore em ordem
void printInOrder(Node* root) {
    if (root != nullptr) {
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
}

// Funcao para imprimir a arvore em pos-ordem
void printPostOrder(Node* root) {
    if (root != nullptr) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->data << " ";
    }
}

// Funcao para calcular a altura da arvore
int treeHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// Funcao para calcular o numero de nos na arvore
int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
}
