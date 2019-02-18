CC = gcc
CFLAGS = -Wall -std=c99

all: stress_test

max_salary_naive.o: max_salary_naive.c max_salary.h 
	$(CC) $(CFLAGS) -c max_salary_naive.c

max_salary_good.o: max_salary_good.c max_salary.h
	$(CC) $(CFLAGS) -c max_salary_good.c
	
stress_test.o: stress_test.c max_salary.h
	$(CC) $(CFLAGS) -c stress_test.c
	
clean:
	rm *.o stress_test