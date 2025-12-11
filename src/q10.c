#include <stdio.h>
#include <stdlib.h>

// n!を計算する関数を
int factorial (int n) {
    if (n == 1) return 1;
    return factorial(n - 1) * n;
}

// nCrを計算する関数
int choose (int n, int r) {
    if (n < r) exit(1);
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main () {
    int n, r;

    // n、rを入力
    printf("n=");
    scanf("%d", &n);
    printf("r=");
    scanf("%d", &r);

    // 結果を表示
    printf("ans=%d\n", choose(n, r));

    return 0;
}