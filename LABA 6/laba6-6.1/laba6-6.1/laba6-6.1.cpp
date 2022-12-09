#include "solomass.h"
#include <malloc.h>
#include <time.h>     
#include <stdio.h>
#include <stdlib.h>


int main() {	
	srand(time(NULL));
	int* mas;
	int size_arr = 0;
	size_array(&size_arr);
	mas = memory(size_arr);
	random(mas, size_arr);
	selection_sort_worst(mas, size_arr);
	//selection_sort(mas,size_arr);
	quick_s(mas, size_arr);
	free(mas);
	return 0;
}