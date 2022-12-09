#include <malloc.h>
#include "Arrays.h"
int main() {
    int* mass;
    int  size_ar = 0;
    size_array(&size_ar);
    mass = memory(size_ar);
    scanf_array(size_ar, mass);
    add_square_after_number(size_ar, mass);
    print_array(size_ar, mass);
    free(mass);
    return 0;
}