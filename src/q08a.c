#include <stdio.h>

int main () {
    int i = 10;
    int *p;                 /* int型変数を指すポインタpの宣言 */
    p = &i;                 /* ポインタpに変数iのアドレスを代入 */
    printf("%d\n", *p);     /* ポインタpの指す変数の値を表示 */
    *p = 10 * (*p);         /* ポインタpの指す変数の値を10倍にする */
    printf("%d\n", *p);     /* ポインタpの指す変数の値を表示 */
    return 0;
}