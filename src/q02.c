#include <stdio.h>

int main () {
    int i, j, k;
    double ans;

    printf("i="); scanf("%d", &i);
    printf("j="); scanf("%d", &j);
    printf("k="); scanf("%d", &k);

    ans = (double)(i + j) * k / 20 + j;

    printf("ans=%f\n", ans);
}