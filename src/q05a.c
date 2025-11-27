#include <stdio.h>
#include <math.h>

#define n 5

int main () {
    //a、xは問題では明記されていませんが、浮動小数点数に対応させています。
    double a[n] = {0}; 
    double x;
    double y = 0;

    // 係数の入力
    printf("keisuu:");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }

    // xの値を入力
    printf("x="); scanf("%lf", &x);

    // yの計算と出力
    for (int i = 0; i < n; i++) {
        y += a[i] * pow(x, i);
    }
    printf("y=%f\n", y);

    return 0;
}