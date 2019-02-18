#include "max_salary.h"

int is_better(int best_so_far, int current) {
	int a_length = log10(best_so_far) + 1;
	int b_length = log10(current) + 1;
	int a = best_so_far * pow(10, b_length) + current;
	int b = current * pow(10, a_length) + best_so_far;
	return b > a;
}

void max_salary_good(int *a, int size) {
	for(int i = 0; i < size; i++) {
		int max = a[i];
		int index = i;
		for(int j = i + 1; j < size; j++) {
			if (is_better(max, a[j])) {
				max = a[j];
				index = j;
			}
		}
		int b = a[i];
		a[i] = max;
		a[index] = b;
	}
	return;
}