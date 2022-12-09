#pragma once
void size_k(int* k);
void SizeMatrix_row(int* row);
int** memory_TS(int row, int cnt);
void  input_matrix(int** a, int row, int cnt);
void print_fir(int** a, int row);
void del_col_after_k(int** a, int *row, int k);
void proverka_input();
//void clearing_memory(int** a, int row, int k);
void print_mtr(int** a, int row,int k);
void clearing_memory(int** mass, int row);