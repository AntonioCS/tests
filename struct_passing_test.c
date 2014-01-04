#include <stdio.h>

struct teste2 {
    int w;
    int h;

};

struct teste {
    int x;
    int y;

    struct teste2 n;
};

void fnteste(struct teste2 *n) {
    n->h = 50;
}

void fnteste2(struct teste2 *n) {
    n->w = 210;
}

int main(int argc, char **argv) {

    struct teste x;

    x.x = 5;
    x.y = 6;

    x.n.h = 12;
    x.n.w = 20;

    printf("x -> %d\n", x.x);
    printf("y -> %d\n", x.y);
    printf("w -> %d\n", x.n.w);
    printf("h -> %d\n\n", x.n.h);

    fnteste(&(x.n));

    printf("x -> %d\n", x.x);
    printf("y -> %d\n", x.y);
    printf("w -> %d\n", x.n.w);
    printf("h -> %d\n\n", x.n.h);

    struct teste *p = &x;

    printf("x -> %d\n", p->x);
    printf("y -> %d\n", p->y);
    printf("w -> %d\n", p->n.w);
    printf("h -> %d\n", p->n.h);

    fnteste2(&(p->n));

    printf("x -> %d\n", p->x);
    printf("y -> %d\n", p->y);
    printf("w -> %d\n", p->n.w);
    printf("h -> %d\n", p->n.h);
}
