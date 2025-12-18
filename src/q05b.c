#include <stdio.h>

#define N 7

int main () {
    int a[N] = {6, 1, 5, 2, 8, 4, 9};
    int temp;

    // 初期配列表示
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    putchar('\n');

    // 配列をバブルソート
    for (int i = N - 1; i > 0; i--)
        for (int j = 0; j < i; j++) 
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

    // ソート後の表示
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    putchar('\n');

    return 0;
}