#pragma once
void sizeMatrix_row(int* row);
void sizeMatrix_col(int* col);
int** allocateMemory(int row, int col);
void proverka_input(int** mass, int i, int j);
void input_matrix(int** mas, int row, int col);
void print_matrix(int** a, int row, int col);
void shellSort_sum(int** a, int row, int col);
void clearing_memory(int** a, int row);
void shell_sort(int** a, int row, int col);
