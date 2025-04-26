#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sorting_algorithms.h"
#include "sorting_string.h"

#define MAX_DATA 2000000
#define MAX_WORD_LEN 100

/// Membaca data angka dari file ke dalam array
void readNumbers(const char *filename, int arr[], int count) {
    FILE *fp = fopen(filename, "r");
    if (!fp) { perror("Gagal buka file angka"); exit(EXIT_FAILURE); }
    for (int i = 0; i < count; i++) fscanf(fp, "%d", &arr[i]);
    fclose(fp);
}

/// Membaca data string dari file ke dalam array 2D string
void readWords(const char *filename, char arr[][MAX_WORD_LEN], int count) {
    FILE *fp = fopen(filename, "r");
    if (!fp) { perror("Gagal buka file kata"); exit(EXIT_FAILURE); }
    for (int i = 0; i < count; i++) fscanf(fp, "%s", arr[i]);
    fclose(fp);
}

/// Menyalin isi array angka ke array lain
void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

/// Menyalin isi array string ke array string lain
void copyArrayStr(char src[][MAX_WORD_LEN], char dest[][MAX_WORD_LEN], int n) {
    for (int i = 0; i < n; i++) strcpy(dest[i], src[i]);
}

int main() {
    int jumlah_data = 10000;  // Jumlah data yang diuji

    // Alokasi memori untuk array angka
    int *data = (int*) malloc(jumlah_data * sizeof(int));
    int *copy = (int*) malloc(jumlah_data * sizeof(int));

    double total_memory = (jumlah_data * sizeof(int) * 2) / 1024.0;
    clock_t start, end;
    double waktu;

    // Baca data angka dari file
    readNumbers("data_angka.txt", data, jumlah_data);

    // Tabel hasil sorting angka
    printf("\nSedang menguji %d data angka...\n\n", jumlah_data);
    printf("+----------------+-------------+---------------+\n");
    printf("|     Algoritma  |   Waktu (s) |   Memori (KB) |\n");
    printf("+----------------+-------------+---------------+\n");

    // Bubble Sort
    copyArray(data, copy, jumlah_data);
    start = clock();
    bubbleSort(copy, jumlah_data);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("| Bubble Sort    |   %9.3f |   %9.1f |\n", waktu, total_memory);

    // Selection Sort
    copyArray(data, copy, jumlah_data);
    start = clock();
    selectionSort(copy, jumlah_data);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("| Selection Sort |   %9.3f |   %9.1f |\n", waktu, total_memory);

    // Insertion Sort
    copyArray(data, copy, jumlah_data);
    start = clock();
    insertionSort(copy, jumlah_data);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("| Insertion Sort |   %9.3f |   %9.1f |\n", waktu, total_memory);

    // Merge Sort
    copyArray(data, copy, jumlah_data);
    start = clock();
    mergeSort(copy, 0, jumlah_data-1);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("| Merge Sort     |   %9.3f |   %9.1f |\n", waktu, total_memory);

    // Quick Sort
    copyArray(data, copy, jumlah_data);
    start = clock();
    quickSort(copy, 0, jumlah_data-1);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("| Quick Sort     |   %9.3f |   %9.1f |\n", waktu, total_memory);

    // Shell Sort
    copyArray(data, copy, jumlah_data);
    start = clock();
    shellSort(copy, jumlah_data);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("| Shell Sort     |   %9.3f |   %9.1f |\n", waktu, total_memory);

    printf("+----------------+-------------+---------------+\n");

    // Bebaskan memori array angka
    free(data);
    free(copy);

    // Alokasi memori untuk array string
    char (*words)[MAX_WORD_LEN] = malloc(jumlah_data * MAX_WORD_LEN);
    char (*copyWords)[MAX_WORD_LEN] = malloc(jumlah_data * MAX_WORD_LEN);
    double total_memory_str = (jumlah_data * MAX_WORD_LEN * 2) / 1024.0;

    // Baca data string dari file
    readWords("data_kata.txt", words, jumlah_data);

    // Tabel hasil sorting string
    printf("\nSedang menguji %d data kata...\n\n", jumlah_data);
    printf("+----------------+-------------+---------------+\n");
    printf("|     Algoritma  |   Waktu (s) |   Memori (KB) |\n");
    printf("+----------------+-------------+---------------+\n");

    // Bubble Sort String
    copyArrayStr(words, copyWords, jumlah_data);
    start = clock();
    bubbleSortStr(copyWords, jumlah_data);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("| Bubble Sort    |   %9.3f |   %9.1f |\n", waktu, total_memory_str);

    // Selection Sort String
    copyArrayStr(words, copyWords, jumlah_data);
    start = clock();
    selectionSortStr(copyWords, jumlah_data);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("| Selection Sort |   %9.3f |   %9.1f |\n", waktu, total_memory_str);

    // Insertion Sort String
    copyArrayStr(words, copyWords, jumlah_data);
    start = clock();
    insertionSortStr(copyWords, jumlah_data);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("| Insertion Sort |   %9.3f |   %9.1f |\n", waktu, total_memory_str);

    // Merge Sort String
    copyArrayStr(words, copyWords, jumlah_data);
    start = clock();
    mergeSortStr(copyWords, 0, jumlah_data-1);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("| Merge Sort     |   %9.3f |   %9.1f |\n", waktu, total_memory_str);

    // Quick Sort String
    copyArrayStr(words, copyWords, jumlah_data);
    start = clock();
    quickSortStr(copyWords, 0, jumlah_data-1);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("| Quick Sort     |   %9.3f |   %9.1f |\n", waktu, total_memory_str);

    // Shell Sort String
    copyArrayStr(words, copyWords, jumlah_data);
    start = clock();
    shellSortStr(copyWords, jumlah_data);
    end = clock();
    waktu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("| Shell Sort     |   %9.3f |   %9.1f |\n", waktu, total_memory_str);

    printf("+----------------+-------------+---------------+\n");

    // Bebaskan memori array string
    free(words);
    free(copyWords);

    return 0;
}
