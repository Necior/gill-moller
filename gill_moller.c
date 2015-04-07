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

int main(int argc, char **argv) {
    if(argc < 2 || !strcmp(argv[1], "--help")) {
        printf("Usage: %s NUM\n", argv[0]);
        return 1;
    }
    double a = 1.0/3.0, result;
    clock_t tic, toc;
    printf("n,Gill-Moller (time),Gill-Moller (result),Naive (time),Naive (result)\n");
    for(int i = 0; i <= atoi(argv[1]); ++i) {
        printf("%d,", i);
        long n = 3 * pow(10, i);

        tic = clock();
        result = gill_moller(n, a);
        toc = clock();
        printf("%f,%f,", (double)(toc - tic) / CLOCKS_PER_SEC, result);

        tic = clock();
        result = naive(n, a);
        toc = clock();
        printf("%f,%f\n", (double)(toc - tic) / CLOCKS_PER_SEC, result);
    }

    return 0;
}
