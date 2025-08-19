#include <stdio.h>

#define N 12

// Função para imprimir vetor
void imprime(int v[]) {
    for(int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Bubble Sort (ordem decrescente)
int bubble_sort(int v[]) {
    int trocas = 0;
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < N-1-i; j++) {
            if(v[j] < v[j+1]) { // troca se o próximo for maior
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
                trocas++;
            }
        }
    }
    return trocas;
}

// Insertion Sort (ordem decrescente)
int insertion_sort(int v[]) {
    int movimentos = 0;
    for(int i = 1; i < N; i++) {
        int chave = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] < chave) {
            v[j+1] = v[j];
            j--;
            movimentos++;
        }
        v[j+1] = chave;
    }
    return movimentos;
}

// Selection Sort (ordem decrescente)
int selection_sort(int v[]) {
    int trocas = 0;
    for(int i = 0; i < N-1; i++) {
        int max = i;
        for(int j = i+1; j < N; j++) {
            if(v[j] > v[max]) {
                max = j;
            }
        }
        if(max != i) {
            int tmp = v[i];
            v[i] = v[max];
            v[max] = tmp;
            trocas++;
        }
    }
    return trocas;
}

int main() {
    // Lista de pontuações dos jogadores
    int pontos[N] = {87, 95, 70, 100, 65, 90, 78, 85, 92, 60, 73, 80};

    int v1[N], v2[N], v3[N];
    for(int i=0; i<N; i++) {
        v1[i] = v2[i] = v3[i] = pontos[i];
    }

    printf("Pontuações originais: ");
    imprime(pontos);

    int t1 = bubble_sort(v1);
    printf("\nBubble Sort (decrescente): ");
    imprime(v1);
    printf("Trocas = %d\n", t1);
    printf("Maior pontuação = %d (posição 1 no ranking)\n", v1[0]);

    int t2 = insertion_sort(v2);
    printf("\nInsertion Sort (decrescente): ");
    imprime(v2);
    printf("Movimentos = %d\n", t2);
    printf("Maior pontuação = %d (posição 1 no ranking)\n", v2[0]);

    int t3 = selection_sort(v3);
    printf("\nSelection Sort (decrescente): ");
    imprime(v3);
    printf("Trocas = %d\n", t3);
    printf("Maior pontuação = %d (posição 1 no ranking)\n", v3[0]);

    return 0;
}

