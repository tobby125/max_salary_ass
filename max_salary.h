#ifndef MAX_SALARY_H
#define MAX_SALARY_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define SWAP(a,b) {int temp; temp=a; a=b; b=temp;}

void print_array(int *arr, int size);
void heap_permutation(int *a, int size, int n, int *max);
int is_better(int best_so_far, int current);
void max_salary_naive(int *a, int size, int *max);
void max_salary_good(int *a, int size);

#endif