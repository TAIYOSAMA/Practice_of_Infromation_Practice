#include <stdio.h>

#define N1 5
#define N2 20
#define MAX_DAYS 300

int main () {
    // エラー処理
    if (!(N1 < N2)) {
        printf("N1の値はN2の値よりも小さく設定してください。");
        return 0;
    }

    FILE *fp, *fout;
    int n, max_n; //第n日の株価をk[n]とする。
    int k[MAX_DAYS] = {0};
    double P_N1[MAX_DAYS] = {0}, P_N2[MAX_DAYS] = {0};

    // ファイルのオープン
    fp = fopen("chart1.txt", "r");
    fout = fopen("chart2.txt", "w");

    // 日付と株価のデータを読み込む
    int temp;
    while (fscanf(fp, "%d %d", &n, &temp) == 2)
        k[n] = temp;
    max_n = n;

    // それぞれ単純移動平均を求める
    for (int i = N1; i <= max_n; i++) { //N1
        for (int j = 0; j < N1; j++)
            P_N1[i] += k[i - j];
        P_N1[i] /= N1;
    }

    for (int i = N2; i <= max_n; i++) { //N2
        for (int j = 0; j < N2; j++)
            P_N2[i] += k[i - j];
        P_N2[i] /= N2;
    }

    // 計算結果をファイルに出力
    for (int i = N2; i <= max_n; i++)
        fprintf(fout, "%d %f %f %f\n", i, P_N1[i], P_N2[i], P_N1[i] - P_N2[i]);

    fclose(fp);
    fclose(fout);

    return 0;
}