#include "Arrays.h"

int main() {
	int** mass;
	int row = 0, col = 0;
	SizeMatrix_row(&row);
	SizeMatrix_col(&col);
	mass = AllocateMemory(row, col);
	input_matrix(mass, row, col);
	print_matrix(mass, row, col);
	del_negot_column(mass, row, &col);
	print_matrix(mass, row, col);
	clearing_memory(mass, row);
	return 0;
}