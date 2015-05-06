#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double gill_moller(long n, double a) {
    double u = 0, p = 0, v, s = 0;
    for(long i = 0; i < n; ++i) {
        v = a;
        s = u + v;
        p = u - s + v + p;
        u = s;
    }
    return s+p;
}

double naive(long n, double a) {
    double result = 0;
    for(long i = 0; i < n; ++i)
        result += a;
    return result;
}

void print_csv_header(void) {
    printf("n,Gill-Moller (time),Gill-Moller (result),Naive (time),Naive (result)\n");
}

void print_csv_row(clock_t tic, clock_t toc, double result) {
    printf("%f,%f,", (double)(toc - tic) / CLOCKS_PER_SEC, result);
}

void measure_function(double (*f)(long, double), long n) {
    double a = 1.0/3.0, result;
    clock_t tic, toc;

    tic = clock();
    result = (*f)(n, a);
    toc = clock();
    print_csv_row(tic, toc, result);
}

int main(int argc, char **argv) {
    if(argc < 2 || !strcmp(argv[1], "--help")) {
        printf("Usage: %s NUM\n", argv[0]);
        return 1;
    }

    print_csv_header();

    for(int i = 0; i <= atoi(argv[1]); ++i) {
        printf("%d,", i);
        long n = 3 * pow(10, i);

        measure_function(gill_moller, n);
        measure_function(naive, n);

        printf("\n");
    }

    return 0;
}
