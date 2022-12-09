#include "lab_6.h"
#include "time.h"
#include <stdlib.h>
int main() {
	int** mass;
	int row = 0, col = 0;
	srand(time(NULL));
	sizeMatrix_row(&row);
	sizeMatrix_col(&col);
	mass = allocateMemory(row, col);
	input_matrix(mass, row, col);
	print_matrix(mass, row, col);
	shell_sort(mass, row, col);
	print_matrix(mass, row, col);
	clearing_memory(mass, row);
	return 0;
}