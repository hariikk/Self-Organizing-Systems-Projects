#include <stdio.h>
#include <stdlib.h> 
#include <math.h>   
#include <time.h>   

int main() {
    long long n = 1000000000;

    // Start timer
    clock_t start_time = clock();

    char *isPrime = (char*)calloc(n + 1, sizeof(char));

    if (isPrime == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;
    }

    isPrime[0] = 1;
    isPrime[1] = 1;

    for (long long p = 2; p * p <= n; p++) {
        if (isPrime[p] == 0) {
            for (long long i = p * p; i <= n; i += p) {
                isPrime[i] = 1;
            }
        }
    }

    long long largestPrime = 0;
    for (long long i = n - 1; i >= 2; i--) {
        if (isPrime[i] == 0) {
            largestPrime = i;
            break; 
        }
    }

    clock_t end_time = clock();
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Highest prime number below %lld is: %lld\n", n, largestPrime);
    printf("C execution time: %.4f seconds\n", time_spent);

    // Free the allocated memory
    free(isPrime);

    return 0;
}   