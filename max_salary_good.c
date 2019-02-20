#include "max_salary.h"

int length(int n) {
	int num = n;
	int len = 1;
	while(num >= 10) {
		num /= 10;
		len += 1;	
	}
	return len;
}

int is_better(int best_so_far, int current) {
	int a_length = length(best_so_far);
	int b_length = length(current);
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