#include <stdio.h>

#define MAX 100

// Fungsi DFS untuk mendeteksi siklus
int dfsCycleCheck(int v, int graf[MAX][MAX], int visited[], int recStack[], int misi) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < misi; i++) {
        if (graf[v][i]) {
            if (!visited[i] && dfsCycleCheck(i, graf, visited, recStack, misi)) {
                return 1;
            } else if (recStack[i]) {
                return 1; 
            }
        }
    }

    recStack[v] = 0;
    return 0;
}

// Fungsi untuk mengecek apakah graf memiliki siklus
int hasCycle(int graf[MAX][MAX], int misi) {
    int visited[MAX] = {0};
    int recStack[MAX] = {0};

    for (int i = 0; i < misi; i++) {
        if (!visited[i]) {
            if (dfsCycleCheck(i, graf, visited, recStack, misi)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int misi, pasangan;
    int graf[MAX][MAX] = {0};

    scanf("%d", &misi);

    scanf("%d", &pasangan);

    for (int i = 0; i < pasangan; i++) {
        int sumber, tujuan;
        scanf("%d %d", &sumber, &tujuan);
        graf[sumber][tujuan] = 1;
    }

    if (hasCycle(graf, misi)) {
        printf("TIDAK BISA\n");
    } else {
        printf("BISA\n");
    }

    return 0;
}
