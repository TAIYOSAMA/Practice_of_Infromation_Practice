#include <stdio.h>
#include <math.h>

int main () {
    // for文を使う
    int ans1 = 1;
    for (int i = 0; i < 5; i++)
        ans1 *= 3;
    printf("%d\n", ans1);

    // ライブラリ関数を使う
    int ans2 = pow(3, 5);
    printf("%d\n", ans2);
}