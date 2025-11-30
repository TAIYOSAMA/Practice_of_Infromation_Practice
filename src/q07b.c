#include <stdio.h>

#define MAX_GOODS 10    // 最大の商品数

int main () {
    FILE *fp, *fout;
    fp = fopen("price.txt", "r");
    fout = fopen("receipt.txt", "w");

    int goods_id, price, goods_num = 0;
    int order_id;
    int total = 0;

    // 0列目に商品の値段、1列目に商品の個数を格納する配列を定義
    int orders_table[MAX_GOODS][2] = {0};

    // 商品の値段を格納
    while (fscanf(fp, "%d %d", &goods_id, &price) == 2)
        orders_table[goods_id][0] = price;
    goods_num = goods_id + 1;

    // 注文を入力
    order_id = 0;
    printf("order: ");
    while (1) {
        scanf("%d", &order_id);
        if (order_id < 0) break;
        orders_table[order_id][1]++;
    }

    // レシートを作成
    for (int i = 0; i < goods_num; i++) {
        if (orders_table[i][1] == 0) continue;
        int line_total = orders_table[i][0] * orders_table[i][1];
        fprintf(fout, "#%d   $%4d     %d   $%4d\n", i, orders_table[i][0], orders_table[i][1], line_total);
        total += line_total;
    }
    fprintf(fout, "------------------------\nTotal $%d\n", total);

    fclose(fp);
    fclose(fout);

    return 0;
}