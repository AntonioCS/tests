#include <stdio.h>
#include <stdlib.h>/* malloc, srand, rand */
#include <time.h> /* time */

void allocate(int **p) {
    printf("%d\n", &*p);
    *p = malloc(sizeof (int));
}

int main() {
    int *p = NULL;
    printf("%d\n", &p);
    allocate(&p);
    *p = 42;
    printf("%d\n", *p);
    free(p);
}

/*
int b = 20;

void ptest(int *);
void ptest2(int *);
void freepointer(int *);

void ptest(int *x) {
    ptest2(x);
    //printf("%d\n",*x);
}

void ptest2(int *x) {
    x = &b;
    printf("%d\n",*x);
 *x = 6;
}

void freepointer(int *n) {
    srand (time(NULL));
 *n = rand() % 10 + 1;
    //free(n);
    //n = NULL;
}

int main(int argc, char **argv) {
    int *n = malloc(sizeof(int));
 *n = 22;

    int a = 5;
    int *x;

    x = &a;

    ptest(x);
    printf("a -> %d\n",a);
    printf("n -> %d\n",*n);

    freepointer(n);
    printf("n -> %d\n",*n);
}
 */