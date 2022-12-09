#include "array_S.h"
#include <malloc.h>

int main() {
	int row = 0;
	int k = 0;
	int cnt = 1;
	SizeMatrix_row(&row);
	size_k(&k);
	int** mass = memory_TS(row, cnt);
	input_matrix(mass, row, cnt);
	print_fir(mass, row);
	del_col_after_k(mass, &row,k);
	print_mtr(mass, row,k);
	clearing_memory(mass,row);
	return 0;
}