#include <stdio.h>

#define MAX_N 10 //正方行列の最大サイズを指定

int main () {
    int N;
    int A[MAX_N][MAX_N];
    int isSymmetric = 1;

    // Nを入力
    printf("N: "); scanf("%d", &N);

    // 行列の入力
    printf("enter matrix:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    // 転置行列の出力
    printf("transposed matrix:\n");
    for (int i = 0; i < N; i++) {
        printf("  ");
        for (int j = 0; j < N; j++)
            printf("%d ", A[j][i]);
        putchar('\n');
    }

    // 対称行列かどうか判定
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (A[i][j] != A[j][i]) {
                isSymmetric = 0;
                break;
            }
    printf("This matrix is "); // 判定結果を表示
    if (!isSymmetric) printf("not ");
    printf("symmetric\n");

    return 0;
}