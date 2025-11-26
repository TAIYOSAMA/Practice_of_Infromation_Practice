#include <stdio.h>

int main()
{
    int x, y;
    int wa, sa, seki, syou;

    /* データの入力 */
    printf("x=");
    scanf("%d", &x);
    printf("y=");
    scanf("%d", &y);

    /* 和、差、積、商の計算 */
    wa = x + y;     sa = x - y;
    seki = x * y;   syou = x / y;

    /* 結果の出力 */
    printf("wa=%d sa=%d seki=%d syou=%d\n", wa, sa, seki, syou);

    return 0;
}