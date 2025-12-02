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
        k[n - 1] = temp;
    max_n = n;

    // それぞれ単純移動平均を求める
    for (int i = 0; i < N1; i++)
        P_N1[N1 - 1] += k[N1 - 1 - i];
    for (int i = N1 - 1; i < max_n - 1; i++) {
        P_N1[i + 1] = P_N1[i] - k[i - N1 + 1] + k[i + 1];
        P_N1[i] /= N1;
    }
    P_N1[max_n - 1] /= N1;

    for (int i = 0; i < N2; i++)
        P_N2[N2 - 1] += k[N2 - 1 - i];
    for (int i = N2 - 1; i < max_n - 1; i++) { //N2
        P_N2[i + 1] = P_N2[i] - k[i - N2 + 1] + k[i + 1];
        P_N2[i] /= N2;
    }
    P_N2[max_n - 1] /= N2;

    // 計算結果をファイルに出力
    for (int i = N2 - 1; i < max_n; i++)
        fprintf(fout, "%d %f %f %f\n", i + 1, P_N1[i], P_N2[i], P_N1[i] - P_N2[i]);

    fclose(fp);
    fclose(fout);

    return 0;
}