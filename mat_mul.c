// CPP Program to multiply two matrix using pthreads 
#include <stdio.h>
#include<stdlib.h> 
#include<pthread.h>
#include<unistd.h>

//using namespace std; 

// maximum size of matrix 
#define MAX 100 

// maximum number of threads 
#define MAX_THREAD 100

int matA[MAX][MAX]; 
int matB[MAX][MAX]; 
int matC[MAX][MAX]; 
int step_i = 0; 

void* multi(void* arg) 
{ 
	sleep(100);
	int core = step_i++; 

	// Each thread computes 1/4th of matrix multiplication 
	for (int i = core * MAX / 100; i < (core + 1) * MAX / 100; i++) 
		for (int j = 0; j < MAX; j++) 
			for (int k = 0; k < MAX; k++) 
				matC[i][j] += matA[i][k] * matB[k][j]; 
} 

// Driver Code 
int main() 
{ 
	// Generating random values in matA and matB 
	for (int i = 0; i < MAX; i++) { 
		for (int j = 0; j < MAX; j++) { 
			matA[i][j] = rand() % 10; 
			matB[i][j] = rand() % 10; 
		} 
	} 

	// Displaying matA 
	
	printf("\nMatrix A\n"); 
	for (int i = 0; i < MAX; i++) { 
		for (int j = 0; j < MAX; j++) 
			printf("%d\t",matA[i][j]); 
	printf("\n");
	} 

	
	printf("\nMatrix B\n");
		
	for (int i = 0; i < MAX; i++) { 
		for (int j = 0; j < MAX; j++) 
			printf("%d\t",matB[i][j]); 
	printf("\n"); 
	} 

	// declaring four threads 
	pthread_t threads[MAX_THREAD]; 

	// Creating four threads, each evaluating its own part 
	for (int i = 0; i < MAX_THREAD; i++) { 
		int* p; 
		pthread_create(&threads[i], NULL, multi, (void*)(p)); 
	} 

	// joining and waiting for all threads to complete 
	for (int i = 0; i < MAX_THREAD; i++) 
		pthread_join(threads[i], NULL);	 

	// Displaying the result matrix 
	printf("\nMultiplication of A and B\n");
	for (int i = 0; i < MAX; i++) { 
		for (int j = 0; j < MAX; j++) 
			printf("%d\t",matC[i][j]); 
	printf("\n");
	} 
	return 0; 
} 

