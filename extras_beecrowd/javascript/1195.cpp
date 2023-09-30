#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class No {
public:
    int data;
    No *esquerda, *direita;
    No(int data) { 
        this->data = data;
        esquerda = direita = NULL;
    }
};

class Arvore {
public:
    No *raiz;
    Arvore() {
        raiz = NULL;
    }
};

No* AchaPai(No* r, int v) { 
    if (r == NULL)
        return NULL;
    else if (v <= r->data) { 
        if (r->esquerda == NULL)
            return r;
        else
            return AchaPai(r->esquerda, v); 
    } else {
        if (r->direita == NULL) 
            return r;
        else
            return AchaPai(r->direita, v);
    }
}

void ImprimeArvore(No* r, int tipo) {
    if (r != NULL) {
        if (tipo == 1) {
            cout << " " << r->data;
            ImprimeArvore(r->esquerda, tipo);
            ImprimeArvore(r->direita, tipo);
        } else if (tipo == 2) {
            ImprimeArvore(r->esquerda, tipo);
            cout << " " << r->data;
            ImprimeArvore(r->direita, tipo);
        } else if (tipo == 3) {
            ImprimeArvore(r->esquerda, tipo);
            ImprimeArvore(r->direita, tipo);
            cout << " " << r->data;
        }
    }
}

int altura(No* raiz) { 
    if (raiz == NULL)
        return 0;
    return max(altura(raiz->esquerda), altura(raiz->direita)) + 1;
}

int getcol(int h) { 
    if (h == 1) 
        return 1;
    return getcol(h - 1) + getcol(h - 1) + 1; 
}

void imprimirNo(int** M, No* raiz, int col, int linha, int altura) {
    if (raiz == NULL)
        return;
    M[linha][col] = raiz->data;
    imprimirNo(M, raiz->esquerda, col - pow(2, altura - 2), linha + 1, altura - 1);
    imprimirNo(M, raiz->direita, col + pow(2, altura - 2), linha + 1, altura - 1);
}

void imprimirArvore(Arvore arvore) {
    int h = altura(arvore.raiz);
    int col = getcol(h);
    int** M = new int*[h];
    for (int i = 0; i < h; i++) {
        M[i] = new int[col];
    }

    imprimirNo(M, arvore.raiz, col / 2, 0, h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < col; j++) {
            if (M[i][j] == 0)
                cout << " " << " ";
            else
                cout << M[i][j] << " ";
        }

        cout << endl;
    }
}
int main() {
    Arvore arvore;// declaracao da arvore
    No* pai;
    No* aux;
    int Tam, Ncasos, c, d, noh; // variaveis auxiliares

    arvore.raiz = NULL;
    cin >> Ncasos;

    for (c = 1; c <= Ncasos; c++) {
        arvore.raiz = NULL;
        cin >> Tam;
        for (d = 0; d < Tam; d++) {
            cin >> noh;

            aux = new No(noh);
            aux->esquerda = NULL;
            aux->direita = NULL;

            pai = AchaPai(arvore.raiz, noh);
            if (pai == NULL)
                arvore.raiz = aux;
            else if (noh <= pai->data)
                pai->esquerda = aux;
            else
                pai->direita = aux;
        }

        cout << "Case " << c << ":" << endl;

        cout << "Pre.:";
        ImprimeArvore(arvore.raiz, 1);
        cout << endl;

        cout << "In..:";
        ImprimeArvore(arvore.raiz, 2);
        cout << endl;

        cout << "Post:";
        ImprimeArvore(arvore.raiz, 3);
        cout << endl << endl;
    }

    return 0;
}
