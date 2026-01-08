#include <stdio.h>

// 複素数を表す構造体を定義
typedef struct 
{
    int real;
    int imaginary;
} complex;

// 複素数を出力する関数
void printComplex (complex x) {
    if (x.imaginary >= 0) {
        printf("%d+%di\n", x.real, x.imaginary);
    } else {
        printf("%d%di\n", x.real, x.imaginary);
    }
}

// x+y
complex add (complex x, complex y) {
    return (complex){
        x.real + y.real,
        x.imaginary + y.imaginary
    };
}

// x-y
complex diff (complex x, complex y) {
    return (complex){
        x.real - y.real,
        x.imaginary - y.imaginary
    };
}

// x*y
complex multi (complex x, complex y) {
    return (complex){
        x.real*y.real - x.imaginary*y.imaginary,
        x.real*y.imaginary + x.imaginary*y.real
    };
}

int main () {
    int a, b, c, d;

    // 4つの整数を入力
    printf("a="); scanf("%d", &a);
    printf("b="); scanf("%d", &b);
    printf("c="); scanf("%d", &c);
    printf("d="); scanf("%d", &d);

    // 2つの複素数x,yを作成
    complex x = {a, b};
    complex y = {c, d};

    // 計算結果を出力
    printf("wa:");   printComplex(add(x, y));
    printf("sa:");   printComplex(diff(x, y));
    printf("seki:"); printComplex(multi(x, y));

    return 0;
}