#include <stdio.h>

#define MAX_GOODS 10    // 最大の商品数
#define MAX_ORDERS 100  // 最大の注文数

int main () {
    FILE *fp, *fout;
    fp = fopen("price.txt", "r");
    fout = fopen("receipt.txt", "w");

    int prices[MAX_GOODS] = {0};
    int orders[MAX_ORDERS] = {0};
    int goods_num; // 品物の数
    int orders_num; // 注文数

    // 品物の値段を取得
    int index, price;
    while (fscanf(fp, "%d %d", &index, &price) == 2)
        prices[index] = price;
    goods_num = index + 1;

    // 注文を入力
    printf("order: ");
    for (int i = 0; i < MAX_ORDERS; i++) {
        scanf("%d", &orders[i]);
        if (orders[i] == -1) {
            orders_num = i;
            break;
        }
    }

    // レシートを作成
    int total = 0;
    int sub_goods_num;  // ある商品だけに着目したときの購入数
    int sub_total;      // ある商品だけの合計金額

    fprintf(fout, "Receipt:\n");
    for (int i = 0; i < goods_num; i++) {
        sub_goods_num = 0;

        // i番目の商品の購入数を計算
        for (int j = 0; j < orders_num; j++)
            if (orders[j] == i) sub_goods_num++;

        // 購入数が0ならば次の処理へ
        if (sub_goods_num == 0) continue;

        // i番目の商品の合計金額を計算
        sub_total = prices[i] * sub_goods_num;

        // 出力
        fprintf(fout, "#%d   $%4d     %d   $%4d\n", i, prices[i], sub_goods_num, sub_total);

        // 合計金額を加算
        total += sub_total;
    }
    fprintf(fout, "------------------------\n");
    fprintf(fout, "Total $%d\n", total);

    fclose(fp);
    fclose(fout);

    return 0;
}