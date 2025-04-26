#ifndef SORTING_STRING_H
#define SORTING_STRING_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// Bubble Sort String
/// Mengurutkan array string secara ascending menggunakan perbandingan berurutan.
void bubbleSortStr(char arr[][100], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            // Bandingkan string berurutan
            if (strcmp(arr[j], arr[j+1]) > 0) {
                // Tukar jika urutannya salah
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
}

/// Selection Sort String
/// Mengurutkan array string dengan mencari nilai terkecil, lalu menukar ke posisi yang tepat.
void selectionSortStr(char arr[][100], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        // Cari string terkecil di sisa array
        for (int j = i+1; j < n; j++) {
            if (strcmp(arr[j], arr[minIdx]) < 0)
                minIdx = j;
        }
        // Tukar string ke posisi i
        char temp[100];
        strcpy(temp, arr[minIdx]);
        strcpy(arr[minIdx], arr[i]);
        strcpy(arr[i], temp);
    }
}

/// Insertion Sort String
/// Mengurutkan array string dengan menyisipkan string ke posisi yang sesuai.
void insertionSortStr(char arr[][100], int n) {
    for (int i = 1; i < n; i++) {
        char key[100];
        strcpy(key, arr[i]);
        int j = i - 1;
        // Geser string yang lebih besar ke kanan
        while (j >= 0 && strcmp(arr[j], key) > 0) {
            strcpy(arr[j+1], arr[j]);
            j--;
        }
        strcpy(arr[j+1], key);
    }
}

/// Merge Function (untuk Merge Sort String)
/// Menggabungkan dua subarray string terurut menjadi satu.
void mergeStr(char arr[][100], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    // Alokasi array sementara di heap
    char (*L)[100] = malloc(n1 * 100);
    char (*R)[100] = malloc(n2 * 100);

    // Copy data ke array sementara
    for (int i = 0; i < n1; i++) strcpy(L[i], arr[l + i]);
    for (int j = 0; j < n2; j++) strcpy(R[j], arr[m + 1 + j]);

    int i = 0, j = 0, k = l;
    // Gabungkan string sesuai urutan
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0)
            strcpy(arr[k++], L[i++]);
        else
            strcpy(arr[k++], R[j++]);
    }
    // Salin sisa data jika masih ada
    while (i < n1) strcpy(arr[k++], L[i++]);
    while (j < n2) strcpy(arr[k++], R[j++]);

    // Bebaskan memori heap
    free(L);
    free(R);
}

/// Merge Sort String
/// Sorting array string menggunakan metode divide and conquer.
void mergeSortStr(char arr[][100], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortStr(arr, l, m);      // Urutkan bagian kiri
        mergeSortStr(arr, m+1, r);    // Urutkan bagian kanan
        mergeStr(arr, l, m, r);       // Gabungkan hasil
    }
}

/// Partition Function (untuk Quick Sort String)
/// Memposisikan pivot di tempat yang benar.
int partitionStr(char arr[][100], int low, int high) {
    char pivot[100];
    strcpy(pivot, arr[high]);
    int i = (low - 1);
    // Bandingkan setiap string dengan pivot
    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            char temp[100];
            strcpy(temp, arr[i]);
            strcpy(arr[i], arr[j]);
            strcpy(arr[j], temp);
        }
    }
    // Tukar pivot ke posisi yang tepat
    char temp[100];
    strcpy(temp, arr[i+1]);
    strcpy(arr[i+1], arr[high]);
    strcpy(arr[high], temp);
    return (i + 1);
}

/// Quick Sort String
/// Sorting array string menggunakan pivot dan rekursif.
void quickSortStr(char arr[][100], int low, int high) {
    if (low < high) {
        int pi = partitionStr(arr, low, high); // Posisi pivot
        quickSortStr(arr, low, pi-1);          // Urut kiri
        quickSortStr(arr, pi+1, high);         // Urut kanan
    }
}

/// Shell Sort String
/// Sorting string menggunakan jarak (gap) antar elemen.
void shellSortStr(char arr[][100], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp[100];
            strcpy(temp, arr[i]);
            int j;
            // Geser string yang lebih besar ke kanan
            for (j = i; j >= gap && strcmp(arr[j-gap], temp) > 0; j -= gap)
                strcpy(arr[j], arr[j-gap]);
            strcpy(arr[j], temp);
        }
    }
}

#endif
