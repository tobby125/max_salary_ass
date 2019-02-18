#include "max_salary.h"
#include "max_salary_naive.c"
#include "max_salary_good.c"

int main() {
	while(1) {
		int size = (rand() % 5) + 2;
		int a[size];
		int b[size];
		for(int i = 0; i < size; i++) {
			int digits = (rand() % 4) + 1;
			int num = 1;
			for(int i = 0; i < digits; i++) {
				num += (rand() % 10) * pow(10, i);
			}
			a[i] = num;
			b[i] = num;
		}
		int max[size];
		max_salary_good(a, size);
		max_salary_naive(b, size, max);
		print_array(a, size);
		print_array(max, size);
		for(int i = 0; i < size; i++) {
			if (a[i] != max[i]) {
				printf("Doesn't match");
				break;
			}
		}
	}
	return 0;
}