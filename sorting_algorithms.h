#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>

/// Bubble Sort
/// Mengurutkan array integer secara ascending dengan metode perbandingan berurutan.
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            // Tukar jika urutan salah
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/// Selection Sort
/// Mengurutkan array integer dengan mencari nilai terkecil lalu dipindahkan ke depan.
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        // Cari index elemen terkecil
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        // Tukar nilai terkecil ke posisi i
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

/// Insertion Sort
/// Mengurutkan array integer dengan menyisipkan elemen ke posisi yang tepat.
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Geser elemen yang lebih besar ke kanan
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

/// Merge Function (untuk Merge Sort)
/// Menggabungkan dua subarray terurut menjadi satu array.
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Alokasi array sementara ke heap
    int *L = (int*) malloc(n1 * sizeof(int));
    int *R = (int*) malloc(n2 * sizeof(int));

    // Copy data ke array sementara
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // Proses penggabungan array
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    // Bebaskan memori heap
    free(L);
    free(R);
}

/// Merge Sort
/// Sorting array integer dengan metode Divide & Conquer.
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);      // Urutkan bagian kiri
        mergeSort(arr, m+1, r);    // Urutkan bagian kanan
        merge(arr, l, m, r);       // Gabungkan hasil
    }
}

/// Partition (untuk Quick Sort)
/// Memposisikan pivot di tempat yang benar, elemen kecil di kiri, besar di kanan.
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    // Bandingkan setiap elemen dengan pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
    }
    // Pindahkan pivot ke posisi yang tepat
    int temp = arr[i+1]; arr[i+1] = arr[high]; arr[high] = temp;
    return (i + 1);
}

/// Quick Sort
/// Sorting array integer menggunakan metode pivot dan rekursif.
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Posisi pivot
        quickSort(arr, low, pi-1);          // Urut kiri
        quickSort(arr, pi+1, high);         // Urut kanan
    }
}

/// Shell Sort
/// Sorting menggunakan jarak (gap) antar elemen.
void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            // Geser elemen yang lebih besar
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap)
                arr[j] = arr[j-gap];
            arr[j] = temp;
        }
    }
}

#endif
