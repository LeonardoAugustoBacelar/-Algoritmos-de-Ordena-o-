#include <stdio.h>

#define N 10

// Função para imprimir vetor
void imprime(int v[]) {
    for(int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Bubble Sort
int bubble_sort(int v[]) {
    int trocas = 0;
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < N-1-i; j++) {
            if(v[j] > v[j+1]) {
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
                trocas++;
            }
        }
    }
    return trocas;
}

// Insertion Sort
int insertion_sort(int v[]) {
    int trocas = 0;
    for(int i = 1; i < N; i++) {
        int chave = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > chave) {
            v[j+1] = v[j];
            j--;
            trocas++;
        }
        v[j+1] = chave;
    }
    return trocas;
}

// Selection Sort
int selection_sort(int v[]) {
    int trocas = 0;
    for(int i = 0; i < N-1; i++) {
        int min = i;
        for(int j = i+1; j < N; j++) {
            if(v[j] < v[min]) {
                min = j;
            }
        }
        if(min != i) {
            int tmp = v[i];
            v[i] = v[min];
            v[min] = tmp;
            trocas++;
        }
    }
    return trocas;
}

int main() {
    int alturas[N] = {172, 185, 160, 178, 190, 155, 167, 180, 175, 169};

    int v1[N], v2[N], v3[N];
    for(int i=0; i<N; i++) {
        v1[i] = v2[i] = v3[i] = alturas[i];
    }

    printf("Vetor original: ");
    imprime(alturas);

    int t1 = bubble_sort(v1);
    printf("\nBubble Sort: ");
    imprime(v1);
    printf("Trocas = %d\n", t1);

    int t2 = insertion_sort(v2);
    printf("\nInsertion Sort: ");
    imprime(v2);
    printf("Movimentos = %d\n", t2);

    int t3 = selection_sort(v3);
    printf("\nSelection Sort: ");
    imprime(v3);
    printf("Trocas = %d\n", t3);

    return 0;
}
