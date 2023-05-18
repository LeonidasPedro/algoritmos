#include <stdio.h>


#define MAX_SIZE 100 //tamanho maximo do heap

void swap(int* a, int* b) { //troca
    int temp = *a; //temp 
    *a = *b; //a recebe b
    *b = temp; //b recebe temp
}
void siftUp(int heap[], int index) { //subida
    int parent = (index - 1) / 2;// o pai recebe o indice - 1 / 2 pois o heap é uma arvore binaria e o pai é sempre o indice - 1 / 2
    
    while (index > 0 && heap[index] > heap[parent]) { //enquanto o indice for maior que 0 e o heap no indice for maior que o heap no pai
        swap(&heap[index], &heap[parent]); //troca
        index = parent; //indice recebe pai
        parent = (index - 1) / 2; //pai recebe indice - 1 / 2
    }   
}
void inserir(int heap[], int* heapSize, int valor) { //inserir
    heap[*heapSize] = valor; //heap no tamanho do heap recebe valor
    *heapSize = *heapSize + 1; // tamanho do heap recebe tamanho do heap + 1
    siftUp(heap, *heapSize - 1); //subida
}
void siftDown(int heap[], int heapSize, int index) { //descida
    int left = 2 * index + 1; //esquerda recebe 2 * indice + 1
    int right = 2 * index + 2; //direita recebe 2 * indice + 2
    int largest = index; //maior recebe indice
    
    if (left < heapSize && heap[left] > heap[largest]) { //se a esquerda for menor que o tamanho do heap e o heap na esquerda for maior que o heap no maior
        largest = left; //maior recebe esquerda
    }
    
    if (right < heapSize && heap[right] > heap[largest]) { //se a direita for menor que o tamanho do heap e o heap na direita for maior que o heap no maior
        largest = right; //maior recebe direita
    }
    
    if (largest != index) { //se o maior for diferente do indice
        swap(&heap[index], &heap[largest]); //troca
        siftDown(heap, heapSize, largest); //descida
    }
}
void imprimirHeap(int heap[], int heapSize) { //imprimir heap
  printf("Heap: ");
  
  for (int i = 0; i < heapSize; i++) { //enquanto i for menor que o tamanho do heap
      printf(" %d ", heap[i]); //imprime o heap no indice i
  }
}
int main()
{
    int heap[MAX_SIZE]; //heap
    int heapSize = 0; //tamanho do heap
    inserir(heap, &heapSize, 7); 
    inserir(heap, &heapSize, 5); 
    inserir(heap, &heapSize, 10);
    inserir(heap, &heapSize, 30);
    inserir(heap, &heapSize, 20);
    imprimirHeap(heap, heapSize); 

    return 0;
}
