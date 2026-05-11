/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
*   Modul               : 5 – Foundation of Algorithm
*   Hari dan Tanggal    : Senin, 11 Mei 2026
*   Nama (NIM)          : Ahmad Akhdan Tristan Salman (13224039)
*   Nama File           : soal2.c
*   Deskripsi           : Program untuk memeriksa graph dependensi tidak memiliki siklus
* 
*/

#include <stdio.h>
#include <string.h>

#define MAX 100

// Fungsi DFS untuk mendeteksi siklus
int cycleCheck(int v, int graf[MAX][MAX], int visited[], int stack[], int misi) {
    visited[v] = 1;
    stack[v] = 1;

    for (int i = 0; i < misi; i++) {
        if (graf[v][i]) {
            if (not visited[i] && cycleCheck(i, graf, visited, stack, misi)) {
                return 1;
            } else if (stack[i]) {
                return 1; 
            }
        }
    }

    stack[v] = 0;
    return 0;
}

// Fungsi untuk mengecek apakah graf memiliki siklus
int hasCycle(int graf[MAX][MAX], int misi) {
    int visited[MAX] = {0};
    int stack[MAX] = {0};

    for (int i = 0; i < misi; i++) {
        if (not visited[i]) {
            if (cycleCheck(i, graf, visited, stack, misi)) {
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
