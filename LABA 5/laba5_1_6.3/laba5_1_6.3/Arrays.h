#pragma once
void size_array(int* n);
int* memory(int n);
void scanf_array(int n, int* b);
void add_square_after_number(int n, int* b);
void print_array(int n, int* b);









//
void SizeMatrix_row(int* row);
void SizeMatrix_col(int* col);
void size_k(int* k);
int** AllocateMemory(int row, int col);
void input_matrix(int** mas, int row, int col);
void del_column(int** a, int row, int* col, int k);
void del_negot_column(int** a, int row, int* col);
void print_matrix(int** a, int row, int col);
void clearing_memory(int** a, int row);



//
void size_k(int* k);
int **memory_TS(int row, int cnt);
void realloc_memory(int a, int row, int cnt);
void del_col_after_k(int a, int row, int cnt, int k);
void print_mtr(int a, int row, int k);