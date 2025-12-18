#include <stdio.h>

#define N 100

// 配列の要素数（-1終端）
int length(const int X[]) {
    int i = 0;
    while (X[i] != -1) i++;
    return i;
}



// 配列に要素を入力するための関数
void inputArray (int X[], int n, char *label) {
    printf("%s", label);

    int x;
    int i = 0;
    while (i < n - 1) {
        scanf("%d", &x);

        if (x == -1) break;
        if (x <= 0) continue;

        X[i++] = x;
    }
    X[i] = -1;
}

// 要素を表示
void printArray (const int X[]) {
    printf("{");
    for (int i = 0; X[i] != -1; i++) {
        if (i > 0) printf(",");
        printf("%d", X[i]);
    }
    printf("}\n");
}



// 昇順にソート
void sort (int X[]) {
    int len = length(X);
    int temp;

    for (int i = len - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (X[j] > X[j + 1]) {
                temp = X[j];
                X[j] = X[j + 1];
                X[j + 1] = temp;
            }
        }
    }
}

// 昇順ソート済み配列に対して、隣接する重複要素を削除
void unique (int X[]) {
    int len = length(X);
    int j = 0;

    for (int i = 1; i < len; i++) {
        if (X[j] != X[i]) {
            X[++j] = X[i];
        }
    }
    X[j + 1] = -1;
}

// 配列を表示用に整形
void formatArray(int X[]) {
    sort(X);
    unique(X);
}



// 共通部分集合を計算
void calcCommon (int X[], const int A[], const int B[]) {
    int k = 0;
    for (int i = 0; A[i] != -1; i++) {
        for (int j = 0; B[j] != -1; j++) {
            if (A[i] == B[j]) {
                X[k++] = A[i];
                break;
            }
        }
    }

    X[k] = -1;

    formatArray(X);
}

// 和集合を計算
void calcUnion (int X[], const int A[], const int B[]) {
    int k = 0;
    for (int i = 0; A[i] != -1; i++) {
        X[k++] = A[i];
    }
    for (int i = 0; B[i] != -1; i++) {
        X[k++] = B[i];
    }

    X[k] = -1;

    formatArray(X);
}



int main () {
    // 集合の初期化
    int A[N] = {0};
    int B[N] = {0};
    int AandB[N] = {0};
    int AorB[N * 2] = {0};

    // 集合の要素を入力
    inputArray(A, N, "SetA: ");
    inputArray(B, N, "SetB: ");

    // 共通部分集合を出力
    calcCommon(AandB, A, B);
    printf("Common subset: ");
    printArray(AandB);

    // 和集合を出力
    calcUnion(AorB, A, B);
    printf("Union set: ");
    printArray(AorB);

    return 0;
}