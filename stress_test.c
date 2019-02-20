#include "max_salary.h"
#include "max_salary_naive.c"
#include "max_salary_good.c"

int main() {
	srand(time(NULL));
	int v = 1;
	while(v == 1) {
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
		int len = 0;
		for(int i = 0; i < size; i++) {
			len += length(a[i]);
		}
		int a_num[len];
		int b_num[len];
		int y = 0;
		int z = 0;
		for(int i = 0; i < size; i++) {
			int a_length = length(a[i]);
			int b_length = length(max[i]);
			for(int j = a_length; j > 0; j--) {
				int x = pow(10, j);
				a_num[y] = (a[i] % x) / pow(10, j - 1);
				y++;
			}
			for(int j = b_length; j > 0; j--) {
				int x = pow(10, j);
				b_num[z] = (max[i] % x) / pow(10, j - 1);
				z++;
			}
		}
		for(int i = 0; i < len; i++) {
			if (a_num[i] != b_num[i]) {
				printf("Doesn't match");
				v = 0;
			}
		}
	}
	return 0;
}