#include <stdio.h>

// xが素数かどうかを判定
int isPrime (int x) {
    if (x == 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main () {
    int start=0, end=0;

    while (start >= end) {
        printf("start="); scanf("%d", &start);
        printf("end=");   scanf("%d", &end);
        if (start >= end)
            printf("startの値はendの値よりも小さくしてください。\n");
    }

    // 素数を大きい順に表示
    for (int i = end; i >= start; i--) {
        if (isPrime(i)) printf("%d\n", i);
    }

    return 0;
}