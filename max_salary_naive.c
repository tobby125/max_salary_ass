#include "max_salary.h"

void print_array(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

// Generating permutation using Heap Algorithm 
void heap_permutation(int *a, int size, int n, int *max) 
{ 
    // if size becomes 1 then do something with the obtained permutation   
    if (size == 1) {
		int length = 0;
		for(int i = 0; i < n; i++) {
			length += log10(a[i]) + 1;
		}
		int a_num[length];
		int max_num[length];
		int y = 0;
		int z = 0;
		for(int i = 0; i < n; i++) {
			int a_length = log10(a[i]) + 1;
			int max_length = log10(max[i]) + 1;
			for(int j = a_length; j > 0; j--) {
				int x = pow(10, j);
				a_num[y] = (a[i] % x) / pow(10, j - 1);
				y++;
			}
			for(int j = max_length; j > 0; j--) {
				int x = pow(10, j);
				max_num[z] = (max[i] % x) / pow(10, j - 1);
				z++;
			}
		}
		for(int i = 0; i < length; i++) {
			if (a_num[i] != max_num[i]) {
				if (a_num[i] > max_num[i]) {
					for(int j = 0; j < n; j++) {
						max[j] = a[j];
					}
				}
				break;
			}
		}
        return;
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heap_permutation(a, size-1, n, max); 
  
        // if size is odd, swap first and last element 
        if (size%2==1) {
            SWAP(a[0], a[size-1]); 
		}
        // If size is even, swap ith and last element 
        else{
            SWAP(a[i], a[size-1]);
		}			
    } 
} 
  
void max_salary_naive(int *a, int size, int *max) {
	for(int i = 0; i < size; i++) {
		max[i] = a[i];
	}
    heap_permutation(a, size, size, max);
    return;
}