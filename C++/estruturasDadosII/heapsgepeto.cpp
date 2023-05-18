#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void siftUp(struct Node* root) {
    if (root->left != NULL && root->left->data > root->data) {

        int temp = root->data;
        root->data = root->left->data;
        root->left->data = temp;
        siftUp(root->left);
    }

    if (root->right != NULL && root->right->data > root->data) {

        int temp = root->data;
        root->data = root->right->data;
        root->right->data = temp;
        siftUp(root->right);
    }
}


struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {

        return createNode(value);
    }

    if (value > root->data) {

        root->data = value;
        siftUp(root);
    } else {

        if (root->left == NULL) {
            root->left = createNode(value);
        } else if (root->right == NULL) {
            root->right = createNode(value);
        } else {

            if (root->left->left == NULL || root->left->right == NULL) {
                insert(root->left, value);
            } else {
                insert(root->right, value);
            }
        }
    }

    return root;
}

void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    // Inserindo elementos na Max Heap
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 35);
    root = insert(root, 15);

    // Imprimindo a Max Heap em pré-ordem
    printf("Max Heap em pre-ordem: ");
    preOrder(root);
    printf("\n");

    return 0;
}

***********************

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Estrutura da fila de prioridades
typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

// Função para criar uma fila de prioridades vazia
PriorityQueue* createPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    pq->size = 0;
    return pq;
}

// Função para trocar dois elementos na fila de prioridades
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para inserir um elemento na fila de prioridades
void enqueue(PriorityQueue* pq, int value) {
    if (pq->size == MAX_SIZE) {
        printf("A fila de prioridades está cheia.\n");
        return;
    }

    // Insere o novo elemento na última posição da fila
    pq->data[pq->size] = value;

    // Restaura a propriedade de heap subindo o novo elemento
    int childIndex = pq->size;
    int parentIndex = (childIndex - 1) / 2;

    while (childIndex > 0 && pq->data[childIndex] > pq->data[parentIndex]) {
        swap(&pq->data[childIndex], &pq->data[parentIndex]);
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }

    pq->size++;
}

// Função para remover o elemento de maior prioridade da fila
void dequeue(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("A fila de prioridades está vazia.\n");
        return;
    }

    // Substitui o elemento de maior prioridade pelo último elemento da fila
    pq->data[0] = pq->data[pq->size - 1];
    pq->size--;

    // Restaura a propriedade de heap descendo o elemento substituto
    int parentIndex = 0;
    int maxChildIndex;

    while (1) {
        int leftChildIndex = parentIndex * 2 + 1;
        int rightChildIndex = parentIndex * 2 + 2;

        // Verifica se o nó atual é um nó folha
        if (leftChildIndex >= pq->size)
            break;

        // Encontra o filho com o maior valor
        if (rightChildIndex >= pq->size || pq->data[leftChildIndex] > pq->data[rightChildIndex])
            maxChildIndex = leftChildIndex;
        else
            maxChildIndex = rightChildIndex;

        // Compara o valor do filho com o valor do nó atual
        if (pq->data[maxChildIndex] > pq->data[parentIndex]) {
            swap(&pq->data[maxChildIndex], &pq->data[parentIndex]);
            parentIndex = maxChildIndex;
        } else {
            break;
        }
    }
}

// Função para exibir o elemento de maior prioridade da fila
void peek(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("A fila de prioridades está vazia.\n");
        return;
    }

    printf("Elemento de maior prioridade: %d\n", pq->data[0]);
}

int main() {
    PriorityQueue* pq = createPriorityQueue();
    int choice, value;

    do {
        printf("1. Inserir um elemento\n
