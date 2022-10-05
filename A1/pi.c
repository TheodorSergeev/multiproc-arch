/*
============================================================================
Filename    : pi.c
Author      : Fedor Sergeev
SCIPER      : 323636
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

double calculate_pi(int num_threads, int samples);

int main(int argc, const char *argv[]) {
    int num_threads, num_samples;
    double pi;

    if (argc != 3) {
		printf("Invalid input! Usage: ./pi <num_threads> <num_samples> \n");
		return 1;
	} else {
        num_threads = atoi(argv[1]);
        num_samples = atoi(argv[2]);
	}

    set_clock();
    pi = calculate_pi(num_threads, num_samples);

    printf("- Using %d threads: pi = %.15g computed in %.4gs.\n", num_threads, pi, elapsed_time());

    return 0;
}


double calculate_pi(int num_threads, int samples) {
    /* Your code goes here */

    double pi = 0.0;

    int integral_hits = 0.0;

    double x = 0.0;
    double y = 0.0;

    #pragma omp parallel private(x, y) shared(integral_hits) num_threads(num_threads)
    {
        rand_gen gen = init_rand();
        int thr_hits = 0.0;

        for(int i = 0; i < samples; i += num_threads) {
            x = next_rand(gen);
            y = next_rand(gen);

            if(x * x + y * y <= 1.0) 
                thr_hits += 1;
        }

        //#pragma atomic
        integral_hits += thr_hits;

        free_rand(gen);
    }

    pi = 4.0 * (double) integral_hits / samples;
    return pi;
}
